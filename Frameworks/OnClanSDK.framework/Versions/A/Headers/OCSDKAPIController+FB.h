//
//  OCSDKAPIController+FB.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (FB)
- (void) clearFBSession;
- (void) getFacebookAccessTokenWithCompletion:(OCSDKStringBlock) completionBlock
                               withErrorBLock:(OCSDKErrorBlock) errorBlock;
@end
