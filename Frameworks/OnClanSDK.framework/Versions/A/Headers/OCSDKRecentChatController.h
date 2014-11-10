//
//  RecentChatController.h
//  onClan
//
//  Created by ToanDK on 7/23/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKConst.h"
#import "AMMessage.h"
#import "OCRecentChatData.h"

@interface OCSDKRecentChatController : NSObject {
}

@property (nonatomic, strong) NSMutableArray *listChat;

+(OCSDKRecentChatController *)sharedInstance;

-(void)setFinishBlock:(OCSDKDictionaryBlock)block;

-(void)getListRecentChatWithComplete:(OCSDKDictionaryBlock)completionBlock;

-(int)getNumberOfUnreadChat;

-(void)markSeenAllChat;

-(void)saveLastMessage:(AMMessage*)message withRead:(BOOL)read;

-(void)setReadForTopic:(NSString*)topicId;

+(void)setChatNotificationNumber:(int)number;

+(void)updateUnreadChatNotificationBadge;

@end
