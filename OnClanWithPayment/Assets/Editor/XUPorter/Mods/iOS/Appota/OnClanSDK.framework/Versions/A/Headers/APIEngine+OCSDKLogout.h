//
//  APIEngine+OCSDKLogout.h
//  OnClanSDK
//
//  Created by Appota on 7/18/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIEngine.h"

@interface OCSDKAPIEngine (OCSDKLogout)
- (void)logOutWithUserName:(NSString*)userName
                onComplete:(OCSDKDictionaryBlock) completionBlock
                   onError:(OCSDKErrorBlock) errorBlock;
@end
