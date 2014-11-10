//
//  AMListChatViewController.h
//  AppotaMessager
//
//  Created by Appota on 7/4/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseViewController.h"
#import "OCSDKThreeButtonSegmentView.h"
#import "OCSDKPeopleTableController.h"
#import "OCSDKRecentTableController.h"
#import "OCSDKListClanTableController.h"
#import "OCSDKBaseMenuViewController.h"

@interface OCSDKListChatViewController : OCSDKBaseMenuViewController{
    
    __weak IBOutlet UITableView *recentChatTableView;
    
    OCSDKRecentTableController *recentController;

    NSMutableArray *listSegment;
    UIView *viewBottomButtonView;
    UIView *lineBottomView;
    
    BOOL isLoadRecent, isLoadPeople, isLoadClan;
}

@property (strong, nonatomic) OCSDKNavigationCustom *customView;
@end
