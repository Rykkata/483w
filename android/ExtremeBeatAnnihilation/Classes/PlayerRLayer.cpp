#include "PlayerRLayer.h"

using namespace cocos2d;

// Initialize the right player for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool PlayerRLayer::init()
{
    if(!CCLayer::init())
    {
        return false;
    }

    return true;
}
