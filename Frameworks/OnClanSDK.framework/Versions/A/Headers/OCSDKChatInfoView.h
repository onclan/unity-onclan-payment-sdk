//
//  OCSDKChatInfoView.h
//  OnClanSDK
//
//  Created by TienLe on 9/8/14.
//
//

#import "OCSDKBaseView.h"

@protocol OCSDKChatInfoViewDelegate <NSObject>
- (void)showListMemberOnChatConversation;
- (void)leaveChatConversation;
- (void)showClanInOnClan;
- (void)showMore;
@end

@interface OCSDKChatInfoView : OCSDKBaseView {
    
    
}

@property (nonatomic, strong) IBOutlet UIButton *buttonSound;
@property (nonatomic, assign) BOOL isAdmin;
@property (nonatomic, assign) id<OCSDKChatInfoViewDelegate> delegate;
+ (id)drawChatInfoView;
- (IBAction)pressSound:(id)sender;
- (IBAction)pressPeople:(id)sender;
- (IBAction)pressMore:(id)sender;

@end
