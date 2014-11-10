//
//  OCSDKScoreViewController.h
//  OnClanSDK
//
//  Created by Appota on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseViewController.h"
#import "OCSDKScoreFriend.h"
#import "OCSDKScoreOverall.h"
@interface OCSDKScoreViewController : OCSDKBaseViewController {
    IBOutlet UITableView *overallTable;
    IBOutlet UITableView *friendTable;
    
    OCSDKScoreOverall *overallController;
    OCSDKScoreFriend *friendsController;
    OCSDKNavigationCustom *customView;
    
    NSMutableArray *listSegment;
    NSString *leaderBoard;
}
@property (nonatomic, assign) int numberOfLeaderBoard;
@property (nonatomic) NSString *leaderBoardID;
@end
