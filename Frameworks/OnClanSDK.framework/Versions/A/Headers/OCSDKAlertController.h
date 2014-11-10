//
//  OCSDKAlertController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCSDKAlertController : NSObject
+ (void) alertWithMessage:(NSString*) message;
+ (void) logoutWithAlert;
//+ (UIAlertController*) logoutWithAlertControllerInView:(UIView*)view;
+ (void) infoAlertActionSheet;
+ (void) infoAlertActionSheetFromView:(UIView*) v;
//+ (UIAlertController*)infoAlertViewControllerInView:(UIView*)view;
+ (void) alertInstallOnClanApp;
+ (void) alertUserName;
+ (void) alertPassword;
+ (void) alertEmail;
+ (void) alertFullName;
@end
