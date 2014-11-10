//
//  OCSDKLoginGameObject.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKLoginObject.h"

typedef enum {
    OCSDKLoginGameNormalType,
    OCSDKLoginGameQuickType,
    OCSDKLoginGameFBType,
    OCSDKLoginGameTWType,
    OCSDKLoginGameGGType,
    OCSDKLoginGameOCType,
} OCSDKLoginGameType;

@interface OCSDKLoginGameObject : OCSDKLoginObject
@property (readwrite) OCSDKLoginGameType gameType;
- (NSString*) getQuickLoginAccessToken;
- (OCSDKLoginGameType) getLoginGameType;
- (BOOL) isQuickLogin;
@end
