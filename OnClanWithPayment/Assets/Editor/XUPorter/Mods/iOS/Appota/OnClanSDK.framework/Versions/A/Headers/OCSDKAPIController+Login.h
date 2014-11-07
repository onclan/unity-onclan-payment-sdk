//
//  OCSDKAPIController+Login.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/7/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (Login)
- (void) loginWithUserName:(NSString*) userName
              withPassword:(NSString*) password
       withCompletionBlock:(OCSDKObjectMessageBlock) completionBlock
            withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) loginFBWithCompletionBlock:(OCSDKObjectMessageBlock) completionBlock
                     withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) loginWithFBToken:(NSString*) fbToken
      withCompletionBlock:(OCSDKDictionaryBlock) completionBlock
           withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) loginWithGGToken:(NSString*) ggToken
      withCompletionBlock:(OCSDKDictionaryBlock) completionBlock
           withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) loginWithTWToken:(NSString*) twToken
        withTWTokenSecret:(NSString*) twSecret
      withCompletionBlock:(OCSDKDictionaryBlock) completionBlock
           withErrorBlock:(OCSDKErrorBlock) errorBlock;


- (void) quickLoginWithCompletionBlock:(OCSDKObjectMessageBlock) completionBlock
                        withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) getOCTokenWithGameToken:(NSString*) gameToken
             withCompletionBlock:(OCSDKDictionaryBlock) completionBlock
                  withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) loginOCWithCompletionBlock:(OCSDKObjectMessageBlock) completionBlock
                     withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) loginOCWithAuthorizeToken:(NSString*) ocToken
               withCompletionBlock:(OCSDKDictionaryBlock) completionBlock
                    withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (id) handleLoginObjectFromDict:(NSDictionary*) dict;
- (id) handleQuickLoginObject:(id) quickLoginObject;
@end
