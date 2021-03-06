#include "Obstacle.h"

using namespace cocos2d;

extern int Jump_Y_Pos;
extern int Slide_Y_Pos;

// initialize the obstacle based on type which specifies the image to use and y position, and the x
//   position is x
//
// x    [in] - the x coordinate to initially position the obstacle
// type [in] - JUMPING_OBSTACLE creates an obstacle positioned for jumping over, and SLIDING_OBSTACLE
//               creates an obstacle positioned for sliding under
void Obstacle::InitWithPositionAndType(int x, int type)
{
	switch(type)
	{
	case JUMPING_OBSTACLE:
		CCSprite::initWithFile(JUMPING_SPRITE);
		setPosition( ccp(x, Jump_Y_Pos) );
		break;
	case SLIDING_OBSTACLE:
		CCSprite::initWithFile(SLIDING_SPRITE);
		setPosition( ccp(x, Slide_Y_Pos) );
		break;
	default:
		CCLog("Illegal Obstacle Type");
	}
}
