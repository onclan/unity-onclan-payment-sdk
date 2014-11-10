//
//  BaseAPITableController.h
//  Appvn
//
//  Created by tuent on 2/6/14.
//  Copyright (c) 2014 Appota. All rights reserved.
//

#import "OCSDKBaseTableController.h"
#import "OCSDKBaseTableRefreshHeaderController.h"
#import "OCSDKAPIEngine.h"

@class BannerListData;

typedef enum{
    OCSDKTableControllerStateNormal = 0,
    OCSDKTableControllerStateLoadingMore = 1,
    OCSDKTableControllerStateUsingCache = 2,
    OCSDKTableControllerStateCantLoadMore,
} OCSDKTableControllerState;

static NSString *OCSDKUpdateTableItemKey = @"ocsdk_update_table_item_key";

@interface OCSDKBaseAPITableController : OCSDKBaseTableRefreshHeaderController
{
    NSString *lastCursor;
}

@property (readwrite) int lastItemCursor;
@property (readwrite) OCSDKTableControllerState tableState;
- (void) getListItemWithCompletionBlock:(OCSDKArrayBlock) completionBlock
                    withErrorBlock:(OCSDKErrorBlock) errorBlock;
- (NSArray*) getListItemCached;
- (void) loadMoreContent;
- (void) startLoadItem;
@end
