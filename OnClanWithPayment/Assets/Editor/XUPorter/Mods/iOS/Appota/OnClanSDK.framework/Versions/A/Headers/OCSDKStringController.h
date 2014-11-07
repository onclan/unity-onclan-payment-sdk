//
//  OCSDKStringController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    OCSDKVerifyValid = 1,
    OCSDKVerifyNullUsername = 0,
    OCSDKVerifyNullPassword = 0,
    OCSDKVerifyNotValidUsername = 0,
    OCSDKVerifyNotValidPassword = 0,
    OCSDKVerifyNotValidEmail = 0,
    OCSDKVerifyNotValidFullName = 0
} OCSDKVerifyType;

@interface OCSDKStringController : NSObject
+ (NSString *) replaceTokenString:(NSString *)str;
+ (NSString *) replaceLanguageString:(NSString *)str;
+ (NSString *)replaceTokenString:(NSString *)str
                       withToken:(NSString*) token;
+ (OCSDKVerifyType) verifyValidPassword:(NSString*) passwordString;
+ (OCSDKVerifyType) verifyRegisterPassword:(NSString*) passwordString;
+ (OCSDKVerifyType) verifyRegisterUserName:(NSString*) userString;
+ (OCSDKVerifyType) verifyValidUsername:(NSString*) userString;
+ (OCSDKVerifyType) verifyEmail:(NSString *)emailStr;
+ (OCSDKVerifyType) verifyFullName:(NSString*)fullnameString;
+ (NSString*) upperFirstCharacterWithString:(NSString*) normString;
@end
