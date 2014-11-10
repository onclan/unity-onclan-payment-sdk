//
//  ChatViewController.h
//  AppotaMessager
//
//  Created by ToanDK on 3/18/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseViewController.h"
#import "OCSDKChatTableView.h"
#import "OCSDKChatEmoticonView.h"
#import "OCSDKChatRecordView.h"
#import "OCSDKChatInputView.h"
#import "OCSDKChatSetupController.h"
#import "OCSDKChatInfoView.h"

typedef NS_ENUM(NSUInteger, InitChatType)
{
    InitChatTypeSolo = 0,
    InitChatTypeGame,
    InitChatTypeAlias,
    InitChatTypeTopic,
    InitChatTypeGroup,
};

typedef enum {
    OCSDKChatInputViewStateShow = 0,
    OCSDKChatInputViewStateHide
}OCSDKChatInputViewState;

@interface OCSDKChatViewController : OCSDKBaseViewController<MosquittoClientDelegate, EmoticonDelegate, ChatInputViewDelegate, OCSDKChatInfoViewDelegate>  {
    __weak IBOutlet OCSDKChatTableView *_tableView;
    __weak IBOutlet UIImageView *backgroundImg;
    __weak IBOutlet OCSDKChatInputView *chatInputView;
    __weak IBOutlet UIView *aliasPopupView;
    __weak IBOutlet UIButton *okBtn, *aliasBtn, *realnameBtn;
    
    __weak OCSDKNavigationCustom *customView;
    __weak OCSDKChatRecordView *recordView;
    __weak OCSDKChatEmoticonView *emoticonView;
    OCSDKChatSetupController *chatController;
    __weak OCSDKChatInfoView *chatInfoView;
    OCSDKChatInputViewState stateView;
    NSMutableArray *listPeople;
    NSMutableArray *listMessages;
    NSMutableDictionary *chatSetting;
    
    NSString *myAliasId, *myFullname, *backupAliasId, *backupAliasName;
    BOOL isCall;
    NSString *gameSchema;
}

@property (strong, nonatomic) IBOutlet UIView *viewChatVip;
@property (nonatomic, strong) NSString *chatType;
@property (weak, nonatomic) IBOutlet UIView *viewContentButtonScrollToBottom;

//+ (OCSDKChatViewController *)sharedManager;
- (id)initWithUserList:(NSArray*)listUser withTextMessage:(NSString*)text;
- (id)initWithUserList:(NSArray*)listUser withAliasList:(NSArray*)listAlias withGame:(NSString*)gameId withTextMessage:(NSString*)text;
- (id)initWithAliasId:(NSString *)aliasId andMyAlias:(NSString *)myAliasId_ withText:(NSString*)text;
-(id)initWithTopic:(NSString*)topicId;
-(void)showKeyboad;
-(void)showRecordView;
-(void)scrollTableToBottom;

-(void)retryMessage:(AMMessage *)message;
-(void)sendMsgFromOldView;
- (void)hideButtonScrollToBottom;
- (void)showButtonScrollToBottom;
- (IBAction)pressScrollToButton:(id)sender;

@end
