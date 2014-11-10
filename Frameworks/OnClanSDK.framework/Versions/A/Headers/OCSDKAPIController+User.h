//
//  OCSDKAPIController+User.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/14/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (User)
- (void) updateUserInfoWithUserDict:(NSDictionary*) userDict
                           onComplete:(OCSDKDictionaryBlock) completionBlock
                              onError:(OCSDKErrorBlock) errorBlock;
@end
