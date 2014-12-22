//
//  OCSDKAppLink.h
//  OnClanSDK
//
//  Created by ToanDK on 7/9/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
@class OCSDKPlayerObject;
@class OCSDKClanObject;
@interface OCSDKAppLink : NSObject

+ (NSString*)getClientId;

+ (NSString*)getClientName;

#pragma mark - onClan app communicate

+ (NSString*) getOpenDevLink;

+ (NSString*)getAuthorizeLink;

+ (void)getOpenUserLinkWithId:(NSString*)userId withComplete:(OCSDKStringBlock)completionBlock;

+ (void)getOpenUpdateInfoLinkWithId:(NSString*)userId withComplete:(OCSDKStringBlock)completionBlock;

+ (void)getOpenAliasLinkWithId:(NSString*)aliasId withComplete:(OCSDKStringBlock)completionBlock;

+ (void)getOpenGameLinkWithId:(NSString*)gameId withComplete:(OCSDKStringBlock)completionBlock;

+ (void)getOpenCreateClanLinkWithGameId:(NSString*)gameId withComplete:(OCSDKStringBlock)completionBlock;

+ (void)getOpenChatLinkWithId:(NSString*)topicId withComplete:(OCSDKStringBlock)completionBlock;

+ (void)getOpenClanLinkWithId:(NSString*)clanId withComplete:(OCSDKStringBlock)completionBlock;

+ (void)getOpenPostLinkWithId:(NSString*)postId withComplete:(OCSDKStringBlock)completionBlock;

+ (NSString*)getOpenShopLink;

+ (void) getInviteFriendLinkWithId:(NSString*) gameId withGameName:(NSString*) gameName withComplete:(OCSDKStringBlock)completionBlock;

+ (NSString*)getOpenStickyWithId:(NSString*)stickyId;

+ (NSString*) getPostPhotoWithID:(NSString*)photoID;

+ (void) checkOnClanAppAndOpenLink:(NSString*)link;

+ (void) askUserToInstallOnClan;

+ (BOOL) checkOnClanInstalled;

+ (void) showOnClanInItunes;

//+ (void) openPickFriendList;

+ (void) showPlayerProfile:(OCSDKPlayerObject*) playerObject;

+ (void) invitePlayer;

+ (void) createClan;

+ (void) showClanProfile:(OCSDKClanObject*) clanObject;
@end
