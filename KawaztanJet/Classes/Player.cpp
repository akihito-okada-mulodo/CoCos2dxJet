//
//  Player.cpp
//  KawaztanJet
//
//  Created by Okada Akihito on 2015/07/15.
//
//

#include "Player.h"
#include "Stage.h"

USING_NS_CC;

const int FRAME_COUNT = 4;
const int VELOCITY_LIMIT = 40;
const Vec2 INITIAL_ACCELERATION = Vec2(200, 0);

bool Player::init()
{
    if(!Sprite::initWithFile("player.png")) {
        return false;
    }
    
    // 1フレームの画像サイズを取得する
    auto frameSize = Size(this->getContentSize().width / FRAME_COUNT, this->getContentSize().height);
    
    this->setTextureRect(Rect(0, 0, frameSize.width, frameSize.height));
    
    Vector<SpriteFrame *> frames;
    
    for (int i = 0; i < FRAME_COUNT; ++i) {
        auto frame = SpriteFrame::create("player.png", Rect(frameSize.width * i, 0, frameSize.width, frameSize.height));
        frames.pushBack(frame);
    }
    
    auto animation = Animation::createWithSpriteFrames(frames);
    
    animation->setDelayPerUnit(0.05);
    
    this->runAction(RepeatForever::create(Animate::create(animation)));
    
    auto body = PhysicsBody::createCircle(this->getContentSize().width / 2.0);
    
    //剛体の回転を無効にする
    body->setRotationEnable(false);
    this->setPhysicsBody(body);
    
    //初期速度を設定する
    _acceleration = INITIAL_ACCELERATION;
    
    this->scheduleUpdate();
    
    return true;
}

void Player::update(float dt)
{
    this->getPhysicsBody()->applyImpulse(_acceleration);
    auto v = this->getPhysicsBody()->getVelocity();
    if (v.x > VELOCITY_LIMIT) {
        v.x = VELOCITY_LIMIT;
        this->getPhysicsBody()->setVelocity(v);
    }
}
