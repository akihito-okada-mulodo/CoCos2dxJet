//
//  Stage.h
//  KawaztanJet
//
//  Created by Okada Akihito on 2015/07/14.
//
//

#ifndef __KawaztanJet__Stage__
#define __KawaztanJet__Stage__

#include "cocos2d.h"
#include "Player.h"

class Stage : public cocos2d::Layer
{
protected:
    Stage();
    virtual ~Stage();
    bool init() override;
public:
    void update(float dt) override;
    
    cocos2d::Sprite* addPhysicsBody(cocos2d::TMXLayer *layer, cocos2d::Vec2& cordinate);
    
    CC_SYNTHESIZE_RETAIN(cocos2d::TMXTiledMap *, _titleMap, TitleMap);
    CC_SYNTHESIZE_RETAIN(Player *, _player, Player);
    CREATE_FUNC(Stage);
};

#endif /* defined(__KawaztanJet__Stage__) */
