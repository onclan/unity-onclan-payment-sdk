//
//  OCSDKChatSettingUserTableView.h
//  OnClanSDK
//
//  Created by TienLe on 8/9/14.
//
//

//#import "OCSDKBaseAPITableController.h"
@class OCSDKChatSettingView;
@interface OCSDKChatSettingUserTableView : UITableView<UITableViewDataSource, UITableViewDelegate>

@property (strong, nonatomic) NSMutableArray *items;
@property (nonatomic, assign) BOOL isAdmin;
@property (nonatomic, strong) OCSDKChatSettingView *chatSettingView;
-(void)initWithDelegateAndDataSource:(OCSDKChatSettingView*)chatSettingView;
@end
