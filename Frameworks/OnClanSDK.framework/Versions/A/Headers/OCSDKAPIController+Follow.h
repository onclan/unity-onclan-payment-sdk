//
//  OCSDKAPIController+Follow.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/19/14.
//
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (Follow)
- (void) followUserWithID:(NSString*) userID
      withCompletionBlock:(OCSDKObjectBlock) completionBlock
           withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) unFollowUserWithID:(NSString*) userID
        withCompletionBlock:(OCSDKObjectBlock) completionBlock
             withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) followClanWithID:(NSString*) clanID
      withCompletionBlock:(OCSDKObjectBlock) completionBlock
           withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) unFollowClanWithID:(NSString*) clanID
        withCompletionBlock:(OCSDKObjectBlock) completionBlock
             withErrorBlock:(OCSDKErrorBlock) errorBlock;
@end
