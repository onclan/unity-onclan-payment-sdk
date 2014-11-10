//
//  AppAdsBundleManager.h
//  AppotaAdsFramework
//
//  Created by tuent on 5/26/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCSDKBundleController : NSObject
+ (UIImage*) imageNamed:(NSString*) imageName;
+ (NSBundle *)frameworkBundle;

+ (UIImage*) getLikeImage;

@end
