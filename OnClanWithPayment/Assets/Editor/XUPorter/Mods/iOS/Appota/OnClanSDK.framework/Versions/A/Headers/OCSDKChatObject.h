//
//  OCSDKChatObject.h
//  OnClanSDK
//
//  Created by TienLe on 10/7/14.
//
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@interface OCSDKChatObject : NSObject<NSCoding>

@property (strong, nonatomic) NSString *topicID;
@property (strong, nonatomic) NSString *messageId;
@property (strong, nonatomic) NSString *emojiId;
@property (strong, nonatomic) NSString *text;
@property (strong, nonatomic) NSString *textColor;
@property (strong, nonatomic) NSString *timestamp;
@property (strong, nonatomic) NSString *type;
@property (strong, nonatomic) NSString *avatar;
@property (strong, nonatomic) NSString *fullname;
@property (strong, nonatomic) NSString *url;
@property (strong, nonatomic) NSString *frame;
@property (strong, nonatomic) NSString *aliasId;
@property (strong, nonatomic) NSString *userId;
@property (strong, nonatomic) NSString *attachmentId;
@property (strong, nonatomic) NSMutableArray *arrayChat;
@property (strong, nonatomic) NSMutableDictionary *dictChat;

- (void)setTopicID:(NSString *)value;
- (void)setMessageId:(NSString *)value;
- (void)setText:(NSString *)value;
- (void)setTextColor:(NSString *)value;
- (void)setTimestamp:(NSString *)value;
- (void)setType:(NSString *)value;
- (void)setAvatar:(NSString *)value;
- (void)setFullname:(NSString *)value;
- (void)setUserId:(NSString *)value;
- (void)setEmojiId:(NSString *)value;
- (void)setFrame:(NSString *)value;
- (void)setAttachmentId:(NSString *)value;

- (id)initWithArrayChat:(NSMutableArray*)arrayChat;

@end
