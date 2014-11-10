//
//  OCSDKGGController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/24/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKConst.h"

@interface OCSDKGGController : NSObject
@property (nonatomic, strong) OCSDKObjectHandler handler;

+ (id)sharedInstance;
+ (BOOL)handleURL:(NSURL *)url
sourceApplication:(NSString *)sourceApplication
       annotation:(id)annotation;

- (void) getGoogleTokenWithHandler:(OCSDKObjectHandler) objectHandler;
@end
