//
//  OCSDKErrorUltility.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString *OCSDK_FBLoginErrorDomain = @"ocsdk_fblogin_error_domain";

@interface OCSDKErrorUltility : NSObject


+(NSError*) errorWithKey:(NSString*) key;
+(NSError*) errorWithKey:(NSString*) key withMessage:(NSString*) message;
+(NSError*) errorWithKey:(NSString*) key withUserInfo:(NSDictionary*) errorInfo;

@end
