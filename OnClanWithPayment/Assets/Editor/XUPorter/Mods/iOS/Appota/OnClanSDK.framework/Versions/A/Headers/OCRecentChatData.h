//
//  OCRecentChatData.h
//  onClan
//
//  Created by ToanDK on 7/23/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import "OCSDKBaseObject.h"

@interface OCRecentChatData : OCSDKBaseObject {
    BOOL isUnread;
}
@property (nonatomic, strong) NSDictionary *lastMessageInfo;
@property (nonatomic, assign) int lastMessageTime;

-(BOOL)isUnread;

-(void)setRead:(BOOL)read;

@end
