//
//  PauseLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 12/5/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "PauseLayer.h"
#import "SettingsLayer.h"
#import "MenuLayer.h"
#import "Registry.h"
#import "GameScene.h"
#import "SimpleAudioEngine.h"

@interface PauseLayer ()

@property (nonatomic, retain) GameScene *gameScene;

@end

@implementation PauseLayer


-(id)initWithGameScene:(GameScene *)scene
{
    if((self = [super init]))
    {
        _gameScene = scene;
        CCMenuItemFont *unPause = [CCMenuItemFont itemWithString:@"Return to Game" target:self selector:@selector(unPausePressed)];
        CCMenuItemFont *settings = [CCMenuItemFont itemWithString:@"Settings" target:self selector:@selector(settingsPressed)];
        CCMenuItemFont *quit = [CCMenuItemFont itemWithString:@"Quit" target:self selector:@selector(quitPressed)];
        CCMenu *pauseMenu = [CCMenu menuWithItems:unPause, settings, quit, nil];
        [pauseMenu alignItemsVertically];
        
        [self addChild: pauseMenu];
    }
    
    return self;
}

-(void)onEnter
{
    [super onEnter];
    ccColor4B black = {0, 0, 0, 255};
    CCLayerColor *colorLayer = [[CCLayerColor alloc] initWithColor:black];
    [[_gameScene avPlayer] setVolume:0.0f];
    [self addChild:colorLayer z:-1];
}

#pragma mark - Button presses

-(void)unPausePressed
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"back.wav"];
    NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
    NSNumber *value = [preferences objectForKey:kMusic];
    [[_gameScene avPlayer]setVolume:[value floatValue]];
    [[self gameScene] resumeGame];
}

-(void)settingsPressed
{
    [[CCDirector sharedDirector] pushScene:[SettingsLayer scene]];
}

-(void)quitPressed
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"back.wav"];
    [Registry clean];
    [[CCDirector sharedDirector] replaceScene:[MenuLayer scene]];
}

@end
