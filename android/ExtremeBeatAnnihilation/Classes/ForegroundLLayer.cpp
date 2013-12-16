#include "ForegroundLLayer.h"

using namespace cocos2d;

// Initialize the left player's foreground (obstacles, player) for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool ForegroundLLayer::init()
{
    CCSize screenSize;                         // the size of the window
    CCSize layerSize;                          // size of this layer

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    screenSize = CCDirector::sharedDirector()->getWinSize();

    // set layerSize to be the full height and half the width of screenSize, and position the layer to
    //   the left side of the screen
    layerSize.setSize(screenSize.width * POS_HALF_SCREEN, screenSize.height);
    setContentSize(layerSize);
    setPosition(0, 0);

    // create the player and add it
    m_player = PlayerL::create();
    m_player->setPosition( ccp(layerSize.width/2, layerSize.height/3) );
    CCLog("Player pointer L %p", m_player);
    addChild(m_player);

    return true;
}

// Needs description
//
// touches [in] -
// event   [in] -
void ForegroundLLayer::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    CCSize        size            = CCDirector::sharedDirector()->getWinSize();
    CCSetIterator it              = touches->begin();
    CCPoint       currentLocation;
    CCTouch*      touch;
    CCRect*       bottomLeft      = new CCRect(0, 0, size.width, size.height/2);
    CCRect*       topLeft         = new CCRect(0, size.height/2, size.width, size.height / 2);

    for(int i = 0; i <= touches->count(); i++)
    {
        touch = (CCTouch*)(*it);
        currentLocation = touch->getLocationInView();
        //currentLocation = CCDirector(sharedDirector)::(convertToGL:currentLocation);

        if(bottomLeft->containsPoint(currentLocation))        // left player slide
        {
        	m_player->Slide();
        }
        else if(topLeft->containsPoint(currentLocation))      // left player jump
        {
            m_player->Jump();
        }
        else
        {
            CCLog("2Congratulations, you have broken the physical laws of reality.\n");
        }

        it++;
    }
}
