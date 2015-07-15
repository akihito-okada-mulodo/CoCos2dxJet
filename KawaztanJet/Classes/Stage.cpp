//
//  Stage.cpp
//  KawaztanJet
//
//  Created by Okada Akihito on 2015/07/14.
//
//

#include "Stage.h"

USING_NS_CC;

Stage::Stage()
: _titleMap(nullptr)
, _player(nullptr)
{
    
}

Stage::~Stage()
{
    CC_SAFE_RELEASE_NULL(_titleMap);
    CC_SAFE_RELEASE_NULL(_player);
}

bool Stage::init()
{
    if (!Layer::init()) {
        return false;
    }
    //マップからノードを作成する
    auto map = TMXTiledMap::create("stage1.tmx");
    this->addChild(map);
    this->setTitleMap(map);
    
    //地形レイヤを取得する
    auto terrainLayer = map->getLayer("Terrain");
    
    auto objectLayer = map->getLayer("Object");
    
    //mapのサイズ
    auto mapSize = map->getMapSize();
    
    for (int x = 0; x < mapSize.width; ++x) {
        for (int y = 0; y < mapSize.height; ++y) {
            auto cordinate = Vec2(x, y);
            
            this->addPhysicsBody(terrainLayer, cordinate);
            this->addPhysicsBody(objectLayer, cordinate);
        }
    }
    
    this->scheduleUpdate();
    
    auto player = Player::create();
    player->setPosition(Vec2(40, 160));
    
    this->addChild(player);
    this->setPlayer(player);
    
    return true;
}

void Stage::update(float dt)
{
    
}

Sprite* Stage::addPhysicsBody(cocos2d::TMXLayer *layer, cocos2d::Vec2 &cordinate)
{
    auto sprite = layer->getTileAt(cordinate);
    
    if (sprite) {
        auto material = PhysicsMaterial();
        
        material.friction = 0;
        
        auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), material);
        
        physicsBody->setDynamic(false);
        
        //剛体を付ける
        sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        
        sprite->setPhysicsBody(physicsBody);
        
        return sprite;
    }
    
    return nullptr;
}