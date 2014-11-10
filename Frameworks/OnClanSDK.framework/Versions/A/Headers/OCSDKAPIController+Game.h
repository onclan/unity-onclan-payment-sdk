//
//  OCSDKAPIController+Game.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/13/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (Game)
- (void) getGameWithGameID:(NSString*) gameID
       withCompletionBlock:(OCSDKObjectMessageBlock) completionBlock
            withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) getVideosWithGameID:(NSString*) gameID
        withCompletionBlock:(OCSDKObjectMessageBlock) completionBlock
             withErrorBlock:(OCSDKErrorBlock) errorBlock;

-(void)getListFollowerOfGame:(NSString *)gameId
                  lastCursor:(NSString *)cursor
                       start:(int)start
                       limit:(int)limit
                  onComplete:(OCSDKDictionaryBlock) completionBlock
                     onError:(OCSDKErrorBlock) errorBlock;

-(void)searchPlayerOfGame :(NSString *)gameId
             keywordSearch:(NSString *)keywordSearch
                lastCursor:(NSString *)cursor
                     start:(int)start
                     limit:(int)limit
                onComplete:(OCSDKDictionaryBlock) completionBlock
                   onError:(OCSDKErrorBlock) errorBlock;

- (void) getClansWithGameID:(NSString*) gameID
                  withStart:(int)start
             withLastCursor:(NSString*) cursor
        withCompletionBlock:(OCSDKArrayCursorBlock) completionBlock
             withErrorBlock:(OCSDKErrorBlock) errorBlock;

- (void) searchClanWithGameID:(NSString*) gameID
                keywordSearch:(NSString *)keywordSearch
                       cursor:(NSString *)cursor
                        start:(int)start
                   onComplete:(OCSDKArrayCursorBlock) completionBlock
                      onError:(OCSDKErrorBlock) errorBlock;

- (void) getClanWithUserID:(NSString*) userID
                withGameID:(NSString*) gameID
                 withStart:(int) start
            withLastCursor:(NSString*) cursor
       withCompletionBlock:(OCSDKArrayCursorBlock) completionBlock
            withErrorBlock:(OCSDKErrorBlock) errorBlock;
@end
