//
//  OCAPIController.h
//  OCSDK
//
//  Created by Tue Nguyen on 7/1/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKNetworkKit.h"
#import "OCSDKConst.h"

@interface OCSDKAPIController : OCSDKNetworkEngine
+ (id) sharedInstance;

- (id) startOperationWithLink:(NSString *) url
               withParameters:(NSDictionary *)params
                   httpMethod:(NSString *)method
                    withCache:(BOOL)enableCache
             onCompleteString:(OCSDKStringBlock) completionBlock
                      onError:(OCSDKErrorBlock) errorBlock;

- (id) startOperationWithLink:(NSString *)url
               withParameters:(NSDictionary *)params
                   httpMethod:(NSString *)method
         onCompleteDictionary:(OCSDKDictionaryBlock) completionBlock
                      onError:(OCSDKErrorBlock) errorBlock;

- (id) startOperationWithLink:(NSString *) url
               withParameters:(NSDictionary *)params
                   httpMethod:(NSString *)method
                    withCache:(BOOL)enableCache
         onCompleteDictionary:(OCSDKDictionaryBlock) completionBlock
                      onError:(OCSDKErrorBlock) errorBlock;

- (NSString *)currentGameToken;

- (void)setCurrentGameToken:(NSString *)newValue;

@end
