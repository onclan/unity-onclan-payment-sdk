//
//  OCSDKAPIController+Me.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/11/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (Me)
- (void) getUserInfoWithCompletionBlock:(OCSDKDictionaryBlock) completionBlock
                         withErrorBlock:(OCSDKErrorBlock) errorBlock;
- (void) getAndUpDateUserInfo;
@end
