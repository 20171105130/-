//: A UIKit based Playground for presenting user interface
  
import UIKit
import PlaygroundSupport

class MyViewController : UIViewController {
    
    func loadWeather()
    {
        let url=URL(string: "http://www.weather.com.cn/data/sk/101120101.html")
        let data = try! Data(contentsOf: url!)
        var json = try? JSONSerialization.jsonObject(with: data) as! [String:Any]
        var weatherInfo=json?["weatherinfo"] as! [String:Any]
        var city=weatherInfo["city"]
        var temp=weatherInfo["temp"]
        var wind=weatherInfo["WD"]
        
        tv.text="城市：\(city)\n温度：\(temp)\n风力：\(wind)\n"
    }
// Present the view controller in the Live View window
PlaygroundPage.current.liveView = MyViewController()
