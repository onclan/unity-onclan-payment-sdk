//
//  APIEngine+OCSDKChat.h
//  AppotaMessager
//
//  Created by ToanDK on 3/18/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKAPIEngine.h"

@interface OCSDKAPIEngine (OCSDKChat)

-(void)getListSubscriptionWithComplete:(OCSDKDictionaryBlock) completionBlock
                               onError:(OCSDKErrorBlock) errorBlock;

-(void)getChatInfoFromTopicId:(NSString *)topicId
                   onComplete:(OCSDKObjectCacheBlock) completionBlock
                      onError:(OCSDKErrorBlock) errorBlock;

-(void)initChatWithUser2:(NSString *)uid
              onComplete:(OCSDKObjectCacheBlock) completionBlock
                 onError:(OCSDKErrorBlock) errorBlock;

-(void)initChatWithAlias:(NSString *)aliasId
             withMyAlias:(NSString *)myAliasId
              onComplete:(OCSDKObjectCacheBlock) completionBlock
                 onError:(OCSDKErrorBlock) errorBlock;

-(void)initChatWithUserList:(NSArray *)listUser
              withAliasList:(NSArray *)aliasList
                     inGame:(NSString *)gameId
                 onComplete:(OCSDKObjectCacheBlock) completionBlock
                    onError:(OCSDKErrorBlock) errorBlock;

-(void)getListRecentChatWithLimit:(int)limit
                           cursor:(NSString *)cursor
                       onComplete:(OCSDKDictionaryBlock) completionBlock
                          onError:(OCSDKErrorBlock) errorBlock;

-(void)updateChatInfo:(NSString *)topicId
           parameters:(NSDictionary *)params
           onComplete:(OCSDKDictionaryBlock) completionBlock
              onError:(OCSDKErrorBlock) errorBlock;

-(void)getListOfRecentTopicWithStart:(int)start
                               limit:(int)limit
                              cursor:(NSString *)cursor
                          onComplete:(OCSDKDictionaryBlock) completionBlock
                             onError:(OCSDKErrorBlock) errorBlock;

-(void)getListOfGroupChatWithStart:(int)start
                             limit:(int)limit
                        onComplete:(OCSDKDictionaryBlock) completionBlock
                           onError:(OCSDKErrorBlock) errorBlock;

-(void)getListMemberOfClan:(NSString *)clanId
                    cursor:(NSString *)cursor
                     start:(int)start
                     limit:(int)limit
                onComplete:(OCSDKDictionaryBlock) completionBlock
                   onError:(OCSDKErrorBlock) errorBlock;

-(void)getListOfUserInTopic:(NSString *)topicId
                 onComplete:(OCSDKObjectCacheBlock) completionBlock
                    onError:(OCSDKErrorBlock) errorBlock;

-(void)addUserToChatTopic:(NSString *)topicId
                 listUser:(NSArray *)listUser
              listAliases:(NSArray *)listAliases
               onComplete:(OCSDKDictionaryBlock) completionBlock
                  onError:(OCSDKErrorBlock) errorBlock;

-(void)kickUserFromChatTopic:(NSString *)topicId
                        user:(NSString *)uid
                       alias:(NSString *)aliasId
                  onComplete:(OCSDKDictionaryBlock) completionBlock
                     onError:(OCSDKErrorBlock) errorBlock;

-(void)quitChatSoloWithTopic:(NSString*)topicId
                clearHistory:(BOOL)clearHistory
                  onComplete:(OCSDKDictionaryBlock) completionBlock
                     onError:(OCSDKErrorBlock) errorBlock;

// Get chat history from last_id
-(void)getChatHistoryOfTopic2:(NSString *)topic
                        start:(int)start
                        limit:(int)limit
                       cursor:(NSString *)cursor
                        after:(NSString *)after
                       before:(NSString *)before
                       isClan:(BOOL)isClan
                   onComplete:(OCSDKDictionaryBlock) completionBlock
                      onError:(OCSDKErrorBlock) errorBlock;

-(void)getListChatRoomCategoryWithComplete:(OCSDKDictionaryBlock) completionBlock
                                   onError:(OCSDKErrorBlock) errorBlock;

-(void)getListChatRoomWithCategoryId:(NSString *)cateId
                          onComplete:(OCSDKDictionaryBlock) completionBlock
                             onError:(OCSDKErrorBlock) errorBlock;

-(void)getListUnreadChatTopicWithComplete:(OCSDKDictionaryBlock) completionBlock
                                  onError:(OCSDKErrorBlock) errorBlock;

-(void)getListMyStickerGroupWithComplete:(OCSDKDictionaryBlock) completionBlock
                                 onError:(OCSDKErrorBlock) errorBlock;

-(void)getChatInfoFromGameId:(NSString *)gameId
                  onComplete:(OCSDKDictionaryBlock) completionBlock
                     onError:(OCSDKErrorBlock) errorBlock;

-(OCSDKNetworkOperation *)uploadAnAttachment:(NSString *)filePath
                                  inTopic:(NSString *)topicId
                                     type:(NSString *)type
                               onComplete:(OCSDKDictionaryBlock) completionBlock
                                  onError:(OCSDKErrorBlock) errorBlock;

-(void)onOffNotificationForTopic:(NSString *)topicId
                          turnOn:(BOOL)turnOn
                      onComplete:(OCSDKDictionaryBlock) completionBlock
                         onError:(OCSDKErrorBlock) errorBlock;

#pragma mark UPLOAD FILE/PHOTO
-(OCSDKNetworkOperation *)uploadAPhoto:(NSString *)filePath
                               type:(NSString *)type
                         onComplete:(OCSDKDictionaryBlock) completionBlock
                            onError:(OCSDKErrorBlock) errorBlock;

-(OCSDKNetworkOperation *)uploadAPhotoScreenShot:(NSString *)filePath
                                          gameID:(NSString*)gameId
                                            type:(NSString *)type
                                           limit:(int)limit
                                          cursor:(NSString*)cursor
                                      onComplete:(OCSDKDictionaryBlock) completionBlock
                                         onError:(OCSDKErrorBlock) errorBlock;

//-(void)createNewPostToUser:(NSString *)uid
//            withParameters:(NSDictionary *)dict
//                onComplete:(OCSDKObjectBlock) completionBlock
//                   onError:(OCSDKErrorBlock) errorBlock;

#pragma mark Sticker
- (void) getStickerListFromStickerId:(NSString*)stickerID
                          onComplete:(OCSDKDictionaryBlock) completionBlock
                             onError:(OCSDKErrorBlock) errorBlock;

- (void) getStickerListFromEmojiId:(NSString*)emojiId
                        onComplete:(OCSDKDictionaryBlock) completionBlock
                           onError:(OCSDKErrorBlock) errorBlock;

@end
