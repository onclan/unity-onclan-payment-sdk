//
//  APIEngine+OCSDKLeaderBoard.h
//  OnClanSDK
//
//  Created by Appota on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIEngine.h"

@interface OCSDKAPIEngine (OCSDKLeaderBoard)

- (void)getListLeaderBoardOfGame:(NSString*)gameID
                      onComplete:(OCSDKDictionaryBlock)completionBlock
                         onError:(OCSDKErrorBlock)errorBlock;

- (void)getListLeaderBoardOverall:(NSString*)gameID
                      leaderboard:(NSString*)leaderboardId
                       lastCursor:(NSString *)cursor
                            start:(int)start
                            limit:(int)limit
                           filter:(NSString*)filter
                            order:(NSString*)order
                       onComplete:(OCSDKDictionaryBlock)completionBlock
                          onError:(OCSDKErrorBlock)errorBlock;

- (void)getListLeaderBoardFriends:(NSString*)gameID
                      leaderboard:(NSString*)leaderboardId
                       lastCursor:(NSString *)cursor
                            start:(int)start
                            limit:(int)limit
                           filter:(NSString*)filter
                            order:(NSString*)order
                       onComplete:(OCSDKDictionaryBlock)completionBlock
                          onError:(OCSDKErrorBlock)errorBlock;

- (void)postScore:(int)point
      leaderboard:(NSString*)leaderboard
           gameId:(NSString*)gameId
       onComplete:(OCSDKDictionaryBlock)completionBlock
          onError:(OCSDKErrorBlock)errorBlock;
@end
