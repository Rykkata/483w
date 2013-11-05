#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* MainMenu::Scene()
{
    CCScene*  scene = CCScene::create();
    MainMenu* layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::Init()
{
    if(!CCLayer::init())
    {
        return false;
    }

    // add a "close" icon to exit the process
    CCMenuItemImage* pCloseItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
                                                            menu_selector(MainMenu::menuCloseCallback));
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    // add your code below...

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

// a selector callback
void MainMenu::MenuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
