//
//  OCSDKAPIController+TW.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/24/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (TW)
- (void) loginTwitterWithCompletionBlock:(OCSDKObjectMessageBlock) completionBlock
                          withErrorBlock:(OCSDKErrorBlock) errorBlock;
@end
