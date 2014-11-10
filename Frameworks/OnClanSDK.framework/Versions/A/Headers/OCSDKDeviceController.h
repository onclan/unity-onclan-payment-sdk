//
//  OCSDKDeviceController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCSDKDeviceController : NSObject
+ (NSString*) getDeviceID;
+ (NSString*) getQuickLoginDeviceID;
+ (void) resetDeviceID;
+ (NSString*) getAppVersion;
+ (NSString*) getAppBundleID;
+ (NSString *)systemVersion;
+ (NSString*) getAppName;
@end
