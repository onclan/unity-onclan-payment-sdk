//
//  OCSDKLeaderBoardTableViewController.h
//  OnClanSDK
//
//  Created by Appota on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>
@class OCSDKLeaderBoardViewController;
@interface OCSDKLeaderBoardTableViewController : UITableView <UITableViewDataSource, UITableViewDelegate>{
    OCSDKLeaderBoardViewController *leaderBoardVC;
}
@property (strong, nonatomic) NSMutableArray *items;
-(void)initWithDelegateAndDataSource:(OCSDKLeaderBoardViewController*)leaderBoardViewController;
@end
