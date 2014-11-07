//
//  ChatBubbleController.h
//  NewAppotaApp
//
//  Created by ToanDK on 3/3/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKChatTableView.h"
//#import "ModelHelper.h"
#import "OCSDKUserInfo.h"
#import "OCSDKChatDataHelper.h"
#import "MosquittoClient.h"

@class OCSDKChatViewController;
@interface OCSDKChatSetupController : NSObject<OCSDKChatTableViewDataSource> {
    OCSDKChatTableView *_tableView;
    NSMutableArray *listMessages;
    NSMutableArray *listPeople;
    NSMutableArray *listDictionaryMessage;
    NSString *topicId;
    NSDictionary *chatSettings;
    int newSection;
    BOOL isHideView;
    float lastSendReadTime;
}
@property (nonatomic, strong) NSString *myAliasId;
@property (nonatomic, strong) NSString *myFullname;
@property (nonatomic, assign) BOOL isLastMessageOfMine;
@property (nonatomic, strong) OCSDKChatViewController *chatViewController;
-(id)initWithTableView:(OCSDKChatTableView *)tblView
             withSetting:(NSDictionary *)setting
             withAlias:(NSString *)aliasId
          withFullname:(NSString*)fullname
           withMembers:(NSMutableArray*)listMember;

-(void)loadMoreChat;
-(void)reloadChatTableView;
-(void)reloadChatTableViewWithoutScroll;
-(void)getChatHistory;
-(NSMutableDictionary*)getFullDataFromData:(NSDictionary *)data;

-(int)getIndexOfMessage:(AMMessage *)msg;
-(NSDictionary *)getUserDictWithUserId:(NSString *)userId andAliasId:(NSString *)aliasId;
-(void)saveMessage:(AMMessage *)msg;
-(void)scrollTableToBottom;
-(BOOL)isMessageOfMine:(AMMessage*)message;

-(AMMessage*)getLastChatMessage;

@end
