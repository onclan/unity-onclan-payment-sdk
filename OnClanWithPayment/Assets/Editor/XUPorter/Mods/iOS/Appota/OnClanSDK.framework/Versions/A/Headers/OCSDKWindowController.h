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
+ (void)sizeToFitOrientation:(BOOL)transform
                    withView:(UIView*) view;

+ (CGSize) sizeInOrientation:(UIInterfaceOrientation)orientation;

+ (CGSize) getWindowSize;

+ (CGRect) getApplicationFrame;

+ (CGPoint) getApplicationCenter;

+ (BOOL) isDeviceIpad;

+ (void) dissmissAllTextInput:(UIView*) view;

+ (CGAffineTransform)transformForOrientation;

+ (CGRect) getSDKNavigationFrame;

+ (BOOL) shouldProceedTransformationWithiOS8;

+ (UIView*) transformOrientationForView:(UIView*) v;
@end
