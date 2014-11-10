//
//  PickImageViewController.h
//  NewAppotaApp
//
//  Created by Appota on 6/3/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>
@protocol PickImageViewDelegate <NSObject>
- (void)reDrawView;
@end
@class OCSDKELCAssetTablePicker;
@interface OCSDKPickImageViewController : UIViewController <UITableViewDataSource, UITableViewDelegate> {
    
}
@property (strong, nonatomic) NSMutableArray *elcAssets;
@property (strong, nonatomic) id<PickImageViewDelegate>delegate;
@property (strong, nonatomic) IBOutlet UITableView *tableChooseLib;
@property (nonatomic, retain) NSMutableArray *assetGroups;
@property (strong, nonatomic) OCSDKELCAssetTablePicker *picker;
@property (strong, nonatomic) NSMutableArray *arraySellect;
@end
