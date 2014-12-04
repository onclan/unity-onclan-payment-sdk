//
//  UserInfo.h
//  AppotaMessager
//
//  Created by ToanDK on 3/17/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKBaseObject.h"

@class OCSDKLeaderBoardPlayerObject;

@interface OCSDKUserInfo : OCSDKBaseObject

@property (nonatomic, readwrite) BOOL isLoggedIn;
@property (nonatomic, readonly) NSString *userId;
@property (nonatomic, readonly) NSString *aliasId;
@property (nonatomic, readonly) NSString *fullname;
@property (nonatomic, readonly) NSString *avatar;
@property (nonatomic, readonly) NSString *cover;
@property (nonatomic, readonly) NSString *level;
@property (nonatomic, strong) OCSDKLeaderBoardPlayerObject *leaderboardPlayerObject;

+(OCSDKUserInfo *) sharedUser;
- (void) reloadAndSaveWithObjectDict:(NSDictionary *)applicationDict;
- (NSString*) getUserVip;
@end
