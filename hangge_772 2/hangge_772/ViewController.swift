//
//  ViewController.swift
//  weather
//
//  Created by 杨扬 on 2018/12/13.
//  Copyright © 2018 杨扬. All rights reserved.
//
import UIKit
import AVFoundation

class ViewController: UIViewController {
    
    var recorder:AVAudioRecorder? //录音器创建音频会话对象
    var player:AVAudioPlayer? //播放器
    var recorderSeetingsDic:[String : Any]? //录音器设置参数数组
    var volumeTimer:Timer! //定时器线程，循环监测录音的音量大小
    var aacPath:String? //录音存储路径
    
    @IBOutlet weak var volumLab: UILabel! //显示录音音量
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //初始化录音器
        
        let docDir = NSSearchPathForDirectoriesInDomains(.documentDirectory,
                                                         .userDomainMask, true)[0]
        //组合录音文件路径
        aacPath = docDir + "/play.aac"
        //初始化字典并添加设置参数
        recorderSeetingsDic =
            [
                AVFormatIDKey: NSNumber(value: kAudioFormatMPEG4AAC),
                AVNumberOfChannelsKey: 2, //录音的声道数，立体声为双声道
                AVEncoderAudioQualityKey : AVAudioQuality.max.rawValue,//指定采样率转换质量的键
                AVEncoderBitRateKey : 320000,//标识音频比特率的整数
                AVSampleRateKey : 44100.0 //录音器每秒采集的录音样本数
        ]
    }
    
    //按下录音
    @IBAction func downAction(_ sender: AnyObject) {
        //初始化录音器
        recorder = try! AVAudioRecorder(url: URL(string: aacPath!)!,
                                        settings: recorderSeetingsDic!)//
        if recorder != nil {
            //开启仪表计数功能
            recorder!.isMeteringEnabled = true
            //准备录音
            recorder!.prepareToRecord()
            //开始录音
            recorder!.record()
            //启动定时器，定时更新录音音量
            volumeTimer = Timer.scheduledTimer(timeInterval: 0.1, target: self,
                                selector: #selector(ViewController.levelTimer),
                                userInfo: nil, repeats: true)
        }
    }
    
    //松开按钮，结束录音
    @IBAction func upAction(_ sender: AnyObject) {
        //停止录音
        recorder?.stop()
        //录音器释放
        recorder = nil
        //暂停定时器
        volumeTimer.invalidate()
        volumeTimer = nil
        volumLab.text = "录音音量:0"
    }
    
  
    //播放录制的声音
    @IBAction func playAction(_ sender: AnyObject) {
        //播放
        player = try! AVAudioPlayer(contentsOf: URL(string: aacPath!)!)
        if player == nil {
            print("播放失败")
        }else{
            //让音频通过喇叭播放
            try! AVAudioSession.sharedInstance().overrideOutputAudioPort(.speaker)
            player?.play()
        }
    }
    
    //定时检测录音音量
    func levelTimer(){
        recorder!.updateMeters() // 刷新音量数据
        let averageV:Float = recorder!.averagePower(forChannel: 0) //获取音量的平均值
        let maxV:Float = recorder!.peakPower(forChannel: 0) //获取音量最大值
        let lowPassResult:Double = pow(Double(10), Double(0.05*maxV))
        volumLab.text = "录音音量:\(lowPassResult)"
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
}

