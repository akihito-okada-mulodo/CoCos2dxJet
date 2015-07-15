//
//  MainScene.h
//  KawaztanJet
//
//  Created by Okada Akihito on 2015/07/08.
//
//

#ifndef __KawaztanJet__MainScene__
#define __KawaztanJet__MainScene__

#include "cocos2d.h"
#include "Stage.h"

class MainScene : public cocos2d::Layer
{
protected:
    MainScene();
    virtual ~MainScene();
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    void update(float dt) override;
    CC_SYNTHESIZE_RETAIN(Stage *, _stage, Stage);
    CC_SYNTHESIZE(bool, _isPress, IsPress);
    CREATE_FUNC(MainScene);
};

#endif /* defined(__KawaztanJet__MainScene__) */
