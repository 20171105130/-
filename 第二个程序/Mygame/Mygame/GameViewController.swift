//
//  GameViewController.swift
//  Mygame
//
//  Created by 杨扬 on 2018/12/7.
//  Copyright © 2018 杨扬. All rights reserved.
//

import UIKit
import SpriteKit
import GameplayKit

class GameViewController: UIViewController {
    
    
   
    //@IBOutlet weak var result: UITextField!
    
    
    //result.text = "hello,world"
   
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if let view = self.view as! SKView? {
            // Load the SKScene from 'GameScene.sks'
            if let scene = SKScene(fileNamed: "GameScene") {
                // Set the scale mode to scale to fit the window
                scene.scaleMode = .aspectFill
                
                // Present the scene
                view.presentScene(scene)
            }
            
            view.ignoresSiblingOrder = true
            
            view.showsFPS = true
            view.showsNodeCount = true
        }
    }

    override var shouldAutorotate: Bool {
        return true
    }

    override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
        if UIDevice.current.userInterfaceIdiom == .phone {
            return .allButUpsideDown
        } else {
            return .all
        }
    }

    override var prefersStatusBarHidden: Bool {
        return true
    }
    #import<MyScene.h>
    @implementation MyScene{
    SKSpriteNode *ship;
    SKAction *actionMoveUp;
    SKAction *actionMoveDown;
    }
    -(id)initWithSize:(CGSize)size {
    if (self = [super initWithSize:size]) {
    self.backgroundColor = [SKColor whiteColor];
    //Making self delegate of physics World
    self.physicsWorld.gravity = CGVectorMake(0,0);
    self.physicsWorld.contactDelegate = self;
    }
    return self;
    }
    @end
    -(void)addShip{
    //initalizing spaceship node
    SKSpriteNode * ship = [SKSpriteNode new];
    ship = [SKSpriteNode spriteNodeWithImageNamed:@"Spaceship"];
    [ship setScale:0.5]; ship.zRotation = - M_PI / 2;
    //Adding SpriteKit physicsBody for collision detection
    ship.physicsBody = [SKPhysicsBody  bodyWithRectangleOfSize:ship.size];
    ship.physicsBody.categoryBitMask = shipCategory;
    ship.physicsBody.dynamic = YES;
    ship.physicsBody.contactTestBitMask = obstacleCategory;
    ship.physicsBody.collisionBitMask = 0;
    ship.name = @"ship";
    ship.position = CGPointMake(120,160);
    [self addChild:ship];
    actionMoveUp = [SKAction moveByX:0 y:30 duration:.2];
    actionMoveDown = [SKAction moveByX:0 y:-30 duration:.2];
    }
    
    - (void)initalizingScrollingBackground
    {
    for (int i = 0; i < 2;i++) {
    SKSpriteNode *bg = [SKSpriteNode spriteNodeWithImageNamed:@"bg"];
    bg.position = CGPointMake(i *bg.size.width, 0);
    bg.anchorPoint = CGPointZero;
    bg.name = @"bg";
    [self addChild:bg];
    }
    }
    // moveObstacle [ˈɑbstək(ə)l] 障碍物
    - (void)moveObstacle
    {
    NSArray *nodes = self.children;
    
    for (SKNode *node in nodes) {
    if (![node.name isEqual:@"bg"]&& ![node.name isEqual:@"ship"]) {
    SKSpriteNode *ob = (SKSpriteNode *) node;
    CGPoint obVelocity = CGPointMake(-OBJECT_VELOCITY, 0);
    CGPoint amtToMove = CGPointMultiplyScalar(obVelocity, _dt);
    
    ob.position = CGPointAdd(ob.position, amtToMove);
    if (ob.position.x < -100) {
    // 移除父节点
    [ob removeFromParent];
    }
    }
    }
    }
    
    - (void)update:(CFTimeInterval)currentTime
    {
    if (_lastUpdateTime) {
    _dt = currentTime - _lastUpdateTime;
    } else {
    _dt = 0;
    }
    
    _lastUpdateTime = currentTime;
    
    if (currentTime - _lastMissileAdded >1) {
    _lastMissileAdded = currentTime + 1;
    // 添加导弹
    [self addMissile];
    }
    
    // 移除背景
    [self moveBg];
    // 移除障碍物
    [self moveObstacle];
    }
}
