//
//  MainScene.cpp
//  KawaztanJet
//
//  Created by Okada Akihito on 2015/07/08.
//
//

#include "MainScene.h"

USING_NS_CC;

// 重力を表すベクトル
const Vec2 GRAVITY_ACCELERATION = Vec2(0, -3);
// 浮力を表すベクトル
const Vec2 INPULSE_ACCELERATION = Vec2(0, 180);

MainScene::MainScene()
:_stage(nullptr)
, _isPress(false)
{
    
}

MainScene::~MainScene()
{
    CC_SAFE_RELEASE_NULL(_stage);
}


bool MainScene::init()
{
    if (!Layer::init()){
        return false;
    }
    
    auto stage = Stage::create();
    
    this->addChild(stage);
    
    this->setStage(stage);
    
    this->scheduleUpdate();
    
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = [this](Touch *touch, Event *event)
    {
        this->setIsPress(true);
        return true;
    };
    
    listener->onTouchEnded = [this](Touch *touch, Event *event)
    {
        this->setIsPress(false);
    };
    
    return true;
}

Scene* MainScene::createScene()
{
    //物理エンジンを有効にしたシーンを作成する
    auto scene = Scene::createWithPhysics();
    
    //物理空間を取り出す
    auto world = scene->getPhysicsWorld();
    
    //重力を設定する
    world->setGravity(GRAVITY_ACCELERATION);
    
    //デバッグビルドの時
#if COCOS2D_DEBUG > 0
    
    //物理空間にデバッグ用の表示を追加する
    world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
#endif
    
    //物理空間のスピードを設定する
    world->setSpeed(6.0f);
    
    //レイヤを作成する
    auto layer = MainScene::create()    ;
    scene->addChild(layer);
    
    return scene;
}

void MainScene::update(float dt)
{
    
}