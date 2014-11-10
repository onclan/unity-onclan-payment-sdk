//
//  OCSDKClanObject.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/14/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseObject.h"

typedef enum
{
    OCSDKClanNotFollowState,
    OCSDKClanFollowingState,
    OCSDKClanPendingFollowState,
} OCSDKClanFollowState;

@interface OCSDKClanObject : OCSDKBaseObject
- (OCSDKClanFollowState) getClanFollowState;
- (void) setClanFollowedState:(OCSDKClanFollowState) followedState;
- (NSString*) getClanID;
- (NSString*) getClanName;
- (int) getTotalMember;
- (NSString*) getClanCover;
- (NSString*) getClanImage;
@end
