//
//  APIEngine+OCSDKChatFriend.h
//  AppotaMessager
//
//  Created by ToanDK on 3/17/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKAPIEngine.h"

@interface OCSDKAPIEngine (OCSDKChatFriend)

-(void) getBasicUserInfo:(NSString *)userId
              onComplete:(OCSDKDictionaryBlock) completionBlock
                 onError:(OCSDKErrorBlock) errorBlock;

-(void)getListOfChatFriendWithStart:(int)start
                              limit:(int)limit
                             cursor:(NSString *)cursor
                         onComplete:(OCSDKDictionaryBlock) completionBlock
                            onError:(OCSDKErrorBlock) errorBlock;

-(void)getListPhotoOfUser:(NSString *)userId
                   cursor:(NSString *)cursor
                    limit:(int)limit
                 withType:(NSString *)type
               onComplete:(OCSDKDictionaryBlock) completionBlock
                  onError:(OCSDKErrorBlock) errorBlock;

@end
