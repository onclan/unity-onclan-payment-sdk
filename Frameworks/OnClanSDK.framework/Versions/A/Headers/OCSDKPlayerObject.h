//
//  OCSDKPlayerObject.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/13/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseObject.h"
typedef enum
{
    OCSDKPlayerNotFollowState,
    OCSDKPlayerFollowingState,
    OCSDKPlayerPendingFollowState,
    OCSDKPlayerAliasState,
} OCSDKPlayerFollowState;

@interface OCSDKPlayerObject : OCSDKBaseObject
- (NSString*) getAliasID;
- (NSString*) getUserID;
- (NSString*) getPlayerAvatar;
- (NSString*) getPlayerFullName;
- (OCSDKPlayerFollowState) getPlayerFollowedState;
- (void) setPlayerFollowedState:(OCSDKPlayerFollowState) followedState;
@end
