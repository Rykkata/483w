//
//  Constants.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "Registry.h"
#import "cocos2d.h"

@implementation Registry
NSString *const kMusic = @"Music";
NSString *const kSFX = @"SFX";
NSString *const GameReady = @"GameReady";

static NSInteger kCharOne = -1;
static NSInteger kCharTwo = -1;
static BOOL kIsSinglePlayer;
static NSString *kMusicName;
static NSURL *kMusicURL;
static NSInteger kScore = 0;
static NSInteger kScoreP1 = 0;
static NSInteger kScoreP2 = 0;
static BOOL kIsMenuMusicPlaying = NO;
static BOOL kIsFileFromLibrary;
static GameScene *kGameScene;

+(void)setChar:(NSInteger)index
{
    if(kCharOne == -1)
    {
        kCharOne = index;
    }
    else if(kCharTwo == -1)
    {
        kCharTwo = index;
    }
}

+(void)removeChar:(NSInteger)index
{
    if(kCharOne == index)
    {
        kCharOne = -1;
    }
    else if(kCharTwo == index)
    {
        kCharTwo = -1;
    }
}

+(NSInteger)getCharOne
{
    return kCharOne;
}

+(NSInteger)getCharTwo
{
    return kCharTwo;
}

+(BOOL)getIsSinglePlayer
{
    return kIsSinglePlayer;
}

+(void)setIsSinglePlayer:(BOOL)mode
{
    kIsSinglePlayer = mode;
}

+(NSString*)getMusicName;
{
    return kMusicName;
}

+(void)setMusicName:(NSString*)name
{
    kMusicName = name;
}

+(NSURL*)getMusicURL
{
    return kMusicURL;
}

+(void)setMusicURL:(NSURL*)URL
{
    kMusicURL = [[URL copy] retain];
}

+(void)setScore:(NSInteger)score
{
    kScore = score;
}

+(void)setFirstScore:(NSInteger)score1 andSecondScore:(NSInteger)score2
{
    kScoreP1 = score1;
    kScoreP2 = score2;
}

+(NSArray*)getScore
{
    if(kIsSinglePlayer)
    {
        return [NSArray arrayWithObjects:[NSNumber numberWithInteger:kScore], nil];
    }
    else
    {
        return [NSArray arrayWithObjects:[NSNumber numberWithInteger:kScoreP1], [NSNumber numberWithInteger:kScoreP2], nil];
    }
}

+(void)setIsMenuMusicPlaying:(BOOL)playing
{
    kIsMenuMusicPlaying = playing;
}

+(BOOL)getIsMenuMusicPlaying
{
    return kIsMenuMusicPlaying;
}

+(void)setIsFileFromLibrary:(BOOL)fromLibrary
{
    kIsFileFromLibrary = fromLibrary;
}

+(BOOL)getIsFileFromLibrary
{
    return kIsFileFromLibrary;
}

+(void)setGameScene:(GameScene *)scene
{
    kGameScene = scene;
}

+(GameScene *)getGameScene
{
    return kGameScene;
}

+(void)clean
{
    kCharOne = -1;
    kCharTwo = -1;
    kIsSinglePlayer = nil;
    kMusicName = nil;
    kMusicURL = nil;
    kScore = 0;
    kScoreP1 = 0;
    kScoreP2 = 0;
    kGameScene = nil;
    [CCSpriteFrameCache purgeSharedSpriteFrameCache];
}
@end
