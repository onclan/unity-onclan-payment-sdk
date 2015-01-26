//
//  OCSDKConst.h
//  OCSDK
//
//  Created by Tue Nguyen on 7/1/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#ifndef OCSDK_OCSDKConst_h
#define OCSDK_OCSDKConst_h

//#define OCSDK_DEBUG YES

#define UNITY_DEPLOYMENT YES
//#define PAYMENT_SDK_SUPPORT YES

//#define WITH_TLS YES

//#ifdef OCSDK_DEBUG
#define OCSDKLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
//#else
//#define OCSDKLog(fmt, ...)
//#endif

typedef enum
{
    OCSDKViewActionClose,
} OCSDKViewAction;

/**
 *  Enum for menu type
 */
typedef enum
{
    OCSDKMenuTypeUser,
    OCSDKMenuTypeChat,
    OCSDKMenuTypeLeaderBoard,
    OCSDKMenuTypeSupport,
    OCSDKMenuTypeVideo,
    OCSDKMenuTypePayment
} OCSDKMenuType;

typedef void (^OCSDKStringBlock)(NSString *xmlString);
typedef void (^OCSDKArrayBlock)(NSArray *list);
typedef void (^OCSDKArrayCursorBlock)(NSArray *list, NSString *lastCursor_);
typedef void (^OCSDKDictionaryBlock)(NSDictionary *dict);
typedef void (^OCSDKObjectCacheBlock)(id object, BOOL isCache);
typedef void (^OCSDKBOOLBlock)(BOOL b);
typedef void (^OCSDKObjectBlock) (id object);
typedef void (^OCSDKObjectMessageBlock) (id object, NSString* message);
typedef void (^OCSDKErrorBlock) (NSError *error);
typedef void (^OCSDKViewHandler) (OCSDKViewAction action);
typedef void (^OCSDKObjectHandler) (id object, NSError *error , NSString *message);

#define OC_SDK_VERSION @"1.10"
#define OC_SDK_BUILD @"10"
#define OCSDK_API_VERSION @"1.0"

#define ONCLAN_APP_SCHEMA @"onclan"
#define ONCLAN_ITUNES_LINK @"https://itunes.apple.com/app/id776649990"

#endif
