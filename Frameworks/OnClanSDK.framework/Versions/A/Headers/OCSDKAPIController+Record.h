//
//  OCSDKAPIController+Record.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/14/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (Photo)

- (void) getUserPhotoWithType:(NSString*) photoType
                    withLimit:(int) limit
                   withCursor:(NSString*) cursor
          withCompletionBlock:(OCSDKDictionaryBlock) completionBlock
               withErrorBlock:(OCSDKErrorBlock) errorBlock;

@end
