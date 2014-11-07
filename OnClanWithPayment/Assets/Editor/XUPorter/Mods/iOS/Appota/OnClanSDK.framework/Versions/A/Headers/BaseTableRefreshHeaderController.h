//
//  BaseTableRefreshHeaderController.h
//  Appvn
//
//  Created by apolo2 on 3/6/14.
//  Copyright (c) 2014 Appota. All rights reserved.
//

#import "OCSDKBaseTableController.h"
#import "BaseRefreshTableHeaderView.h"

@interface BaseTableRefreshHeaderController : OCSDKBaseTableController <UIScrollViewDelegate, OCSDKEGORefreshTableHeaderDelegate> {
    
}

@property (strong, nonatomic) id tableDidSCrollHandleController;
@property (nonatomic, retain) BaseRefreshTableHeaderView * refreshHeaderView;
@property (readwrite) BOOL isLoadingRefreshHeader;

//- (id) initWithTargetTable:(UITableView *)targetTable withParamsDict:(NSMutableDictionary *)params withControllerHandleTableDidScroll:(id) handleController;

- (void) reloadDataSourceItems;
- (void) removeRefreshHeaderView;

@end
