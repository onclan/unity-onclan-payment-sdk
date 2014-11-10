//
//  OCSDKRecordTableViewCell.h
//  OnClanSDK
//
//  Created by Appota on 7/21/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseTableViewCell.h"
#import "OCSDKRecordPhotoSingleView.h"

@protocol OCSDKRecordPhotoTableViewCellDelegate <NSObject>
- (void)reloadRecordTableView;
@end
@interface OCSDKRecordPhotoTableViewCell : OCSDKBaseTableViewCell <OCSDKRecordPhotoSingleDeletePhoto>{
    NSMutableArray *cellData;    
}
@property (assign, nonatomic) id<OCSDKRecordPhotoTableViewCellDelegate> delegate;
@end
