//
//  AppotaAdsWindowsManager.h
//  AppotaAdsFramework
//
//  Created by tuent on 5/26/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCSDKWindowController : NSObject
+ (CGRect) getKeyWindowFrame;

+ (CGRect) getViewFrameWithSize:(CGSize) imageSize;

+ (UIWindow*) getKeyWindows;

+ (BOOL) isDeviceIpad;

+ (void) dissmissAllTextInput:(UIView*) view;

+ (CGRect) getSDKNavigationFrame;

@end
