//
//  IntroLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 9/11/13.
//  Copyright Crash Course Gaming 2013. All rights reserved.
//


// Import the interfaces
#import "IntroLayer.h"
#import "MenuLayer.h"
#import "MusicSelectLayer.h"

#pragma mark - IntroLayer

@implementation IntroLayer

// Helper class method that creates a Scene with the IntroLayer as the only child.
+(CCScene *) scene
{
	// 'scene' is an autorelease object.
	CCScene *scene = [CCScene node];
	
	// 'layer' is an autorelease object.
	IntroLayer *layer = [IntroLayer node];
	
	// add layer as a child to scene
	[scene addChild: layer];
	
	// return the scene
	return scene;
}

-(id) init
{
	if( (self=[super init])) {

		// ask director for the window size
		CGSize size = [[CCDirector sharedDirector] winSize];

		CCSprite *background;
		
		if( UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone )
        {
            if ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] &&
                ([UIScreen mainScreen].scale == 2.0))
            {
                background = [CCSprite spriteWithFile:@"Default@2x.png"];
            }
            else
            {
                background = [CCSprite spriteWithFile:@"Default.png"];
            }
			background.rotation = 90;
		} else {
			background = [CCSprite spriteWithFile:@"Default-Landscape~ipad.png"];
		}
		background.position = ccp(size.width/2, size.height/2);

		// add the label as a child to this Layer
		[self addChild: background];
	}
	
	return self;
}

-(void) onEnter
{
	[super onEnter];
	[[CCDirector sharedDirector] replaceScene:[CCTransitionFade transitionWithDuration:1.0 scene:[MenuLayer scene]]];
}
@end
