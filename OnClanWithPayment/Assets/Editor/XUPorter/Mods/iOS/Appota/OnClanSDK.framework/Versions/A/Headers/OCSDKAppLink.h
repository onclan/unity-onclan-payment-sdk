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

+ (NSString*)getOpenUserLinkWithId:(NSString*)userId;

+ (NSString*)getOpenUpdateInfoLinkWithId:(NSString*)userId;

+ (NSString*)getOpenAliasLinkWithId:(NSString*)aliasId;

+ (NSString*)getOpenGameLinkWithId:(NSString*)gameId;

+ (NSString*)getOpenCreateClanLinkWithGameId:(NSString*)gameId;

+ (NSString*)getOpenChatLinkWithId:(NSString*)topicId;

+ (NSString*)getOpenClanLinkWithId:(NSString*)clanId;

+ (NSString*)getOpenPostLinkWithId:(NSString*)postId;

+ (NSString*)getOpenShopLink;

+ (NSString*) getInviteFriendLinkWithId:(NSString*) gameId withGameName:(NSString*) gameName;

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
