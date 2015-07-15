//
//  Player.h
//  KawaztanJet
//
//  Created by Okada Akihito on 2015/07/15.
//
//

#ifndef __KawaztanJet__Player__
#define __KawaztanJet__Player__

#include <stdio.h>

class Player :public
cocos2d::Sprite
{
protected:
    bool init() override;
public:
    void update(float dt) override;
    
    //ジェットの推進力
    CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vec2, _acceleration, Acceleration);
    CREATE_FUNC(Player);
};

#endif /* defined(__KawaztanJet__Player__) */
