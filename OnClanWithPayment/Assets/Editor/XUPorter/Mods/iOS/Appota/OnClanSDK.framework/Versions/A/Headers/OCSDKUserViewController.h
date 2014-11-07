//
//  AMSettingViewController.h
//  AppotaMessager
//
//  Created by ToanDK on 3/21/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseMenuViewController.h"
#import "OCSDKPeopleTableController.h"
#import "OCSDKListClanTableController.h"
#import "OCSDKTwoButtonSegmentView.h"

@class OCSDKGameObject;
@interface OCSDKUserViewController : OCSDKBaseMenuViewController <UIAlertViewDelegate, KTSegmentViewDelegate, UIActionSheetDelegate>
{
    IBOutlet OCSDKTwoButtonSegmentView *twoSegment;
    IBOutlet UILabel *nameGroup;
    IBOutlet UILabel *levelGroup;
    IBOutlet UIView *viewContentSegment;
    IBOutlet UIView *viewContentTable;
    IBOutlet UIView *viewContentHeaderView;
    IBOutlet UITableView *playerTableView;
    IBOutlet UITableView *clanTableView;
    
    OCSDKPeopleTableController* playerTableController;
    OCSDKListClanTableController* clanTableController;
    OCSDKNavigationCustom *customView;

}

//- (IBAction) clanPlayerAction:(id)sender;
@end
