#include "MainGameScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

// test comment to see if this works
CCScene* MainGame::scene()
{
    CCScene*    scene = CCScene::create();        // 'scene' is an autorelease object
    MainGame* layer = MainGame::create();     // 'layer' is an autorelease object

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainGame::init()
{
    //////////////////////////////
    // 1. super init first
    if(!CCLayer::init())
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the process. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
                                                           menu_selector(MainGame::menuCloseCallback));
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your code below...

    // add a label shows "Extreme Beat Annihilation"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Extreme Beat Annihilation", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width / 2, size.height / 2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    return true;
}

void MainGame::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}