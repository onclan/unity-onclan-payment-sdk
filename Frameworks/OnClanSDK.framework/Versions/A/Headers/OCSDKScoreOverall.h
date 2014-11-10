//
//  OCSDScoreOverall.h
//  OnClanSDK
//
//  Created by Appota on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseAPITableController.h"
@class OCSDKScoreViewController;
@interface OCSDKScoreOverall : OCSDKBaseAPITableController {
   
}
@property (nonatomic, assign) NSString *leaderBoardID;
@property (nonatomic) BOOL isLoading;
@property (nonatomic, strong) OCSDKScoreViewController *scoreViewController;
- (NSString*) getHeaderLabelNameWithSection:(int) section;
- (id) initWithTargetTable:(UITableView *)targetTable andLeaderBoardID:(NSString*)leaderboard;
- (void)initWithController:(OCSDKScoreViewController*)viewController;
@end
