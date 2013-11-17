#ifndef __FOREGROUND_R_LAYER_H__
#define __FOREGROUND_R_LAYER_H__

#include "cocos2d.h"

#define POS_HALF_SCREEN    0.5             // factor of width/height which gives a position halfway
#define POS_QUARTER_SCREEN 0.25            // factor of width/height which gives a position quarter-way

class ForegroundRLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(ForegroundRLayer);
};

#endif // __FOREGROUND_R_LAYER_H__
