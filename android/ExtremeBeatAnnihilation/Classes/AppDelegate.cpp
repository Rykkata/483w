#include "AppDelegate.h"

USING_NS_CC;
using namespace CocosDenshion;

// externs defined in Global.cpp
extern int   Font_Size_Default;
extern int   Font_Size_Small;
extern bool  Allow_Volume_Set;
extern float Music_Volume;
extern float SFX_Volume;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // set the initial volumes
    Music_Volume = INIT_MUSIC_VOL;
    SFX_Volume   = INIT_SFX_VOL;
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(Music_Volume / VOLUME_FACTOR);
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(SFX_Volume / VOLUME_FACTOR);
    Allow_Volume_Set = false;    // initialized to false, so volumes don't get set to default values on
                                 //   init of options menu

    // set the font sizes for the whole game based on the size of the screen
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    Font_Size_Default = size.height / 10;
    Font_Size_Small   = size.height / 15;

    // start up the menu song
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MENU_MUSIC, true);

    // turn on fps for testing
    //pDirector->setDisplayStats(true);
    //pDirector->setAnimationInterval(1.0 / 60);

    // start up the intro scene as the first scene
    pDirector->runWithScene(IntroScene::Scene());

    return true;
}

// This function will be called when the app is inactive, or when a phone call comes in.
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // pause background music
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();

    // resume background music
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
