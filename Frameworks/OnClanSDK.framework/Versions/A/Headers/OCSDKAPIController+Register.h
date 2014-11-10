//
//  OCSDKAPIController+Register.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/11/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"


@interface OCSDKAPIController (Register)
- (void) registerWithUserName:(NSString*) username
                 withPassword:(NSString*) password
                 withFullName:(NSString*) fullName
                    withEmail:(NSString*) email
          withCompletionBlock:(OCSDKObjectMessageBlock) completionBlock
               withErrorBlock:(OCSDKErrorBlock) errorBlock;
@end
