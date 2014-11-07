//
//  APIEngine+OCSDKClan.h
//  OnClanSDK
//
//  Created by ToanDK on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIEngine.h"

@interface OCSDKAPIEngine (OCSDKClan)

-(void)getListClanOfGame:(NSString *)gameId
                  cursor:(NSString *)cursor
                   start:(int)start
                   limit:(int)limit
              onComplete:(OCSDKDictionaryBlock) completionBlock
                 onError:(OCSDKErrorBlock) errorBlock;

-(void)searchClanOfGame:(NSString *)gameId
          keywordSearch:(NSString *)keywordSearch
                  cursor:(NSString *)cursor
                   start:(int)start
                   limit:(int)limit
              onComplete:(OCSDKDictionaryBlock) completionBlock
                 onError:(OCSDKErrorBlock) errorBlock;

//-(void)joinAClan:(NSString*)clanId
//       onComplete:(OCSDKDictionaryBlock) completionBlock
//          onError:(OCSDKErrorBlock) errorBlock;

- (void)getListClanOfUser:(NSString*)userID
                   gameID:(NSString*)gameId
                    start:(int)start
                    limit:(int)limit
                   cursor:(NSString*)cursor
               onComplete:(OCSDKDictionaryBlock) completionBlock
                  onError:(OCSDKErrorBlock) errorBlock;
@end
