//
//  OCSDKOpenURLController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/15/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKConst.h"

@interface OCSDKOpenURLController : NSObject
@property (nonatomic, strong) OCSDKObjectMessageBlock openURLHandler;
+ (OCSDKOpenURLController*) sharedInstance;
- (BOOL) handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
@end
