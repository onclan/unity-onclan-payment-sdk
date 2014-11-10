//
//  AMMessage.h
//  AppotaMessager
//
//  Created by ToanDK on 3/18/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum _AMChatMessageType
{
    AMChatMessageTypeText = 0,
    AMChatMessageTypeSticky,
    AMChatMessageTypeVoice,
    AMChatMessageTypeImage,
    AMChatMessageTypeAddUser,
    AMChatMessageTypeKickUser,
    AMChatMessageTypeLeft,
    AMChatMessageTypeTyping,
    AMChatMessageTypeEndTyping,
    AMChatMessageTypeRead,
    AMChatMessageTypeJoin,
} AMChatMessageType;

typedef enum _AMSystemMessageType
{
    AMSystemMessageTypeNone = 0,
    AMSystemMessageTypeChat,
    AMSystemMessageTypeNotification,
    AMSystemMessageTypeControl,
    AMSystemMessageTypeSelfMessage,
} AMSystemMessageType;

typedef enum {
    AMMessageDeliveryStateDelivered = 0,
    AMMessageDeliveryStatePending = 1,
    AMMessageDeliveryStateFailed = 2,
    AMMessageDeliveryStateUploading,
} AMMessageDeliveryState;

typedef enum {
    AMMessagePositionStandAlone = 0,
    AMMessagePositionHeader,
    AMMessagePositionMiddle,
    AMMessagePositionFooter,
} AMMessagePosition;

typedef enum {
    AMMessageClientTypeUnknown = 0,
    AMMessageClientTypeIOS,
    AMMessageClientTypeAndroid,
    AMMessageClientTypeWeb,
    AMMessageClientTypeWinPhone,
} AMMessageClientType;

typedef enum {
    OCUserChatTypeNormal = 0,
    OCUserChatTypeDev,
    OCUserChatTypeAdmin,
    OCUserChatTypeCreator,
} OCUserChatType;

@interface AMMessage : NSObject <NSCoding>{
    NSMutableArray *listReadUsers;
}

@property (nonatomic, assign) int svMsgId;
@property (nonatomic, strong) NSString *messageId;
@property (nonatomic, strong) NSString *topicId;
@property (nonatomic, strong) NSString *command;
@property (nonatomic, readwrite) AMChatMessageType chatMessageType;
@property (nonatomic, readwrite) AMSystemMessageType systemMessageType;
@property (nonatomic, readwrite) AMMessageDeliveryState deliveryState;
@property (nonatomic, readwrite) BOOL isMine;
@property (nonatomic, readwrite) AMMessagePosition position;
@property (nonatomic, readwrite) AMMessageClientType clientType;
@property (nonatomic, assign) OCUserChatType userType;
@property (nonatomic, strong) NSString *fromUserId;
@property (nonatomic, strong) NSString *fromAliasId;
@property (nonatomic, strong) NSString *fromUserFullname;
@property (nonatomic, strong) NSString *fromUserAvatar;
@property (nonatomic, strong) NSString *toUserId;
@property (nonatomic, strong) NSString *toAliasId;
@property (nonatomic, strong) NSString *imageUrl;
@property (nonatomic) int timeStamp;
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSString *stickyCode;
@property (nonatomic, assign) int stickyFrames;
@property (nonatomic, readonly) NSDictionary *objectDictionary;
@property (nonatomic, strong) NSDictionary *attachmentInfo;
@property (nonatomic, strong) UIColor *textColor;

-(id)initWithChatType:(AMChatMessageType)type;
-(id)initWithMessageDict:(NSDictionary*)dict;
-(id)initWithJsonString:(NSString*)string;

-(void)generateMessageId;

-(BOOL)canShowPhoto;

-(BOOL)isLikeMessage;

-(BOOL)isChatControlMessage;

-(NSString *)toJsonString;

-(NSDictionary *)toDictionaryWithTimeStamp;

-(void)addReadUser:(NSDictionary*)userDict;

-(NSArray*)getListReadUser;

-(void)resetListReadUser;

-(NSDictionary*)getFullFromDict;

-(NSDictionary*)getDataDict;

@end
