//
//  AMPeopleTableController.h
//  AppotaMessager
//
//  Created by ToanDK on 3/17/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseAPITableController.h"
@class OCSDKUserViewController;
@interface OCSDKPeopleTableController : OCSDKBaseAPITableController {
    BOOL isLoading;
}

@property (assign, nonatomic) BOOL isFirstSearch;
@property (assign, nonatomic) BOOL isTableNormal;
@property (strong, nonatomic) OCSDKUserViewController *userViewController;
@property (nonatomic) NSString *keywordSearch;
//@property (nonatomic, strong) UIView *tableHeaderView;

- (id)initWithTargetTable:(UITableView *)targetTable andKind:(OCSDKBaseTableViewKind)tableKind andHeadSection:(UIView *)headerSection;
- (void)initWithViewController:(OCSDKUserViewController*)viewController;
@end
