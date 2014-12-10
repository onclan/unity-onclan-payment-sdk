//
//  OCSDKConfigure.h
//  Framework-iOS
//
//  Created by Tue Nguyen on 6/30/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKConst.h"
#import "OCUserInfo.h"

//#define GAME_ID                 @"52a846fd479c19cf778b45e2"
#define GAME_LEADERBOARD_ID     @"53b68227479c191d1f8b4649"

@interface OCSDKConfigure : NSObject
+ (OCSDKConfigure*) sharedInstance;

#pragma mark - Login handler
@property (nonatomic, strong) OCSDKObjectHandler loginHandler;

#pragma mark - Variable
@property (readwrite) BOOL disableAutoShowLogin;

/*
 *  default is YES. If set to NO, chat head can not move any more
 */
@property (nonatomic, assign) BOOL chatHeadDragable;

/*
 *  Default is YES. If set to NO, chat head can move freely without boucing to edge of screen
 */
@property (nonatomic, assign) BOOL bouncingEdge;

/*
 *  Default is YES. If set to NO, leaderboard will not show.
 */
@property (nonatomic, assign) BOOL isUseLeaderboard;

@property (nonatomic, assign) BOOL logoutButtonHidden;

#pragma mark - Config function
/**
 *  Config function called when init app
 *  Start auto login after configuration
 *  @param apiKey API key to identify app
 */
+ (void) configWithAPIKey:(NSString*) apiKey;

/**
 *  Config APIKey
 *
 *  @param apiKey 
 *  Return with block of user access token, error (optional), message (optional)
 */
+ (void) configWithAPIKey:(NSString*) apiKey
              withHandler:(OCSDKObjectHandler) handler;

#pragma mark - Show View function
+ (void) logOut;
+ (void) showLoginView;

//+ (void)showOCMenu:(BOOL)enableAppotaIcon withChat:(BOOL)enableChat withLeaderBoard:(BOOL)enableLeaderboard withCamera:(BOOL)enableCamera atPosition:(CGPoint)startPoint;

+ (void)showLeaderBoard;

+ (void)showChat;

+ (void)showRecord;

+ (void)showUser;

+ (void) showPaymentView;
#pragma mark - Support function
+ (BOOL) checkUserLoggedIn;

+ (BOOL) handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

- (void) loginCallBack:(id) object;

- (void)setChatHeadPosition:(CGPoint)center;

- (OCUserInfo*)getUserInfo;

@end
