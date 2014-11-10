//
//  OCSDKCreateChatViewController.h
//  OnClanSDK
//
//  Created by TienLe on 8/11/14.
//
//

#import "OCSDKBaseMenuViewController.h"
#import "OCSDKTwoButtonSegmentView.h"
#import "OCSDKPeopleTableController.h"
#import "OCSDKListClanTableController.h"

typedef enum {
    OCSDKCreateChatTabViewPlayer,
    OCSDKCreateChatTabViewClan
}OCSDKCreateChatTabView;

@interface OCSDKCreateChatViewController : OCSDKBaseMenuViewController <KTSegmentViewDelegate,  OCSDKNavigationCustomKeyboardDelegate>{
    __weak OCSDKNavigationCustom *customView;
    OCSDKPeopleTableController *peopleController;
    OCSDKListClanTableController *clanController;
    __weak IBOutlet UIView *viewContentAll;
    __weak IBOutlet UIView *viewContentSegment;
    __weak IBOutlet UITableView *peopleTableView;
    __weak IBOutlet UITableView *clanTableView;
    __weak IBOutlet OCSDKTwoButtonSegmentView *twoSegment;
    UIView *viewBackground;
    NSString *lastKeywordSearch;
}

@property (assign, nonatomic) OCSDKCreateChatTabView createChatTabView;
@property (nonatomic) BOOL isPushView;
@end
