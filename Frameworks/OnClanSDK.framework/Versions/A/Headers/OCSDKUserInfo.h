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
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *aliasId;
@property (nonatomic, strong) NSString *fullname;
@property (nonatomic, strong) NSString *avatar;
@property (nonatomic, strong) NSString *cover;
@property (nonatomic, strong) NSString *level;
@property (nonatomic, strong) OCSDKLeaderBoardPlayerObject *leaderboardPlayerObject;

+(OCSDKUserInfo *) sharedUser;
- (void) reloadAndSaveWithObjectDict:(NSDictionary *)applicationDict;
- (NSString*) getUserVip;
@end
