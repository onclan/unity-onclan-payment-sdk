//
//  OCSDKLeaderboard.h
//  OnClanSDK
//
//  Created by ToanDK on 7/15/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKConst.h"

@interface OCSDKLeaderboard : NSObject

/**
 *  Submit highscore to a Category
 *
 *  @param score           highscore
 *  @param categoryId      ID of category
 *  @param completionBlock status: true if successful
 errorCode:
 type:
 message:
 *  @param errorBlock      Return an error if failed
 */
+ (void) submitScore:(unsigned int) score;

+ (void) submitScore:(unsigned int)score inCategory:(NSString*)categoryId onComplete:(OCSDKObjectBlock)completionBlock onError:(OCSDKErrorBlock)errorBlock;

+ (void) submitScore:(unsigned int)score inCategory:(NSString*)categoryId;

/**
 *  Get list leaderboard categories of game
 *
 *  @param completionBlock  status: true if successful
 count: Int
 leaderboards: Array of objects
 leaderboardId: String
 name: String
 image: String, URL
 totalPlayer: Int
 pointType: String, [int | decimal1 | decimal2 | decimal3]
 pointUnit: String
 submitType: String, [best | recent]
 range: Array, [min, max]
 *  @param errorBlock
 */
+ (void) getListLeaderboardCategoryWithComplete:(OCSDKDictionaryBlock)completionBlock
                                        onError:(OCSDKErrorBlock)errorBlock;

/**
 *  Get list score of all players in a category
 *
 *  @param categoryId      ID of category
 *  @param filter          Type of leaderboard (today/week/month). Pass nil to get all overall
 *  @param ascendingOrder  Sort result with ascending or descending order
 *  @param cursor          Cursor of last call that determine the last data
 *  @param limit           Number of return records
 *  @param completionBlock status:
 errorCode:
 type:
 data:
 count: Int
 cursor: String
 players: Array of objects
 userId: String
 aliasId: String
 aliasNum: String
 fullname: String
 avatar: String, URL
 point: Int | Decimal
 rank: Int
 message:
 *  @param errorBlock      Return an error if failed
 */
+ (void) getListLeaderboardInCategory:(NSString*)categoryId
                           withFilter:(NSString*)filter
                   withAscendingOrder:(BOOL)ascendingOrder
                           withCursor:(NSString*)cursor
                            withStart:(int)start
                            withLimit:(int)limit
                           onComplete:(OCSDKObjectBlock)completionBlock
                              onError:(OCSDKErrorBlock)errorBlock;

/**
 *  Similar with getListLeaderboardInCategory but only get scores of friends
 *
 */
+ (void) getListLeaderboardOfFriendsInCategory:(NSString*)categoryId
                                    withFilter:(NSString*)filter
                            withAscendingOrder:(BOOL)ascendingOrder
                                    withCursor:(NSString*)cursor
                                     withStart:(int)start
                                     withLimit:(int)limit
                                    onComplete:(OCSDKObjectBlock)completionBlock
                                       onError:(OCSDKErrorBlock)errorBlock;

@end
