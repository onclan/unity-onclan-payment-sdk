//
//  AMClanTableController.h
//  AppotaMessager
//
//  Created by Appota on 7/7/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseAPITableController.h"
@class OCSDKUserViewController;
@interface OCSDKListClanTableController : OCSDKBaseAPITableController {
    BOOL isLoading;
}

@property (assign, nonatomic) BOOL isFirstSearch;
@property (assign, nonatomic) BOOL isTableNormal;
@property (nonatomic) NSString *keywordSearch;
@property (nonatomic, strong) UIView *tableHeaderView;
@property (strong, nonatomic) OCSDKUserViewController *userViewController;
- (id)initWithTargetTable:(UITableView *)targetTable andKind:(OCSDKBaseTableViewKind)tableKind andHeadSection:(UIView *)headerSection;
- (void)initWithViewController:(OCSDKUserViewController*)viewController;
@end
