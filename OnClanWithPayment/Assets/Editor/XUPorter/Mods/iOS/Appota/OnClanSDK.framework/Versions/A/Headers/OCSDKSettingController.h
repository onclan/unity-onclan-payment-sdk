//
//  OCSDKDefaultController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OCSDKTrackObject;
@class OCSDKLoginGameObject;
@class OCSDKLoginOCObject;
@class OCSDKGameObject;
@class OCSDKInfoObject;

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

@interface OCSDKSettingController : NSObject
+ (OCSDKSettingController*) sharedInstance;
@property (nonatomic, strong) NSString *ocAccessToken;
@property (nonatomic, strong) NSString *apiKey;
@property (nonatomic, strong) OCSDKGameObject *gameObject;
@property (nonatomic, strong) OCSDKTrackObject *trackObject;
@property (nonatomic, strong) OCSDKLoginOCObject *loginOCObject;
@property (nonatomic, strong) OCSDKInfoObject *infoObject;

/**
 *  Game information
 */
@property (nonatomic, strong) OCSDKLoginGameObject *loginGameObject;

- (void) loadLoginSession;
- (NSString*) loadToken;
- (void) loadMQTTSession;
- (void) resetToken;

+ (void) saveObject:(id) object;
+ (id) loadObjectWithClass:(Class) objectClass;

+ (id) loadObjectWithKey:(NSString*) objectKey;
+ (void) saveObject:(id) object
            withKey:(NSString*) objectKey;

- (NSString*) getGameToken;
- (NSString*) getGameID;
- (NSString*) getClientID;
- (BOOL) checkUserUpdateInfor;

#pragma mark - 3rd login setting
- (NSString*) getGoogleClientID;
- (NSString*) getTwitterConsumerKey;
- (NSString*) getTwitterConsumerSecret;
@end
