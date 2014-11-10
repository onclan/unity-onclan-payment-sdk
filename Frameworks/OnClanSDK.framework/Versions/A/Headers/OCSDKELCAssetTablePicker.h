//
//  AssetTablePicker.h
//
//  Created by ELC on 2/15/11.
//  Copyright 2011 ELC Technologies. All rights reserved.
//

//#import <UIKit/UIKit.h>
#import "OCSDKBaseViewController.h"
#import <AssetsLibrary/AssetsLibrary.h>
#import "OCSDKELCAsset.h"
#import "ELCAssetSelectionDelegate.h"
#import "OCSDKPickImageArrowView.h"
#import "OCSDKPickImageViewController.h"
#import "ELCShowVideoView.h"
#import "OCSDKELCAssetCell.h"

@interface OCSDKELCAssetTablePicker : OCSDKBaseViewController <ELCAssetDelegate, ELCAssetCellSingleClick, UITableViewDataSource, UITableViewDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, UIGestureRecognizerDelegate> {
    UIView *backgroundView;
    UIButton *buttonTakePicture;
    NSArray *indexPathInsertRow;
    NSMutableArray *tableArray;
    NSMutableArray *imageArraySellected;
    
    OCSDKPickImageViewController *modalViewController;
    ELCShowVideoView *showView;
    
    int countTime;
    CGRect videoRect;
    BOOL isAddCell, isDisplay;
    BOOL isShowAlbum, isTakePicture;
}

@property (strong, nonatomic) IBOutlet UITableView *tableViewImage;
@property (nonatomic, strong) id <ELCAssetSelectionDelegate> parent;
@property (nonatomic, retain) ALAssetsGroup *assetGroup;
@property (nonatomic, retain) NSMutableArray *elcAssets;
@property (nonatomic, retain) NSMutableArray *assetGroups;
@property (nonatomic, retain) IBOutlet UILabel *selectedAssetsLabel;
@property (nonatomic, assign) BOOL singleSelection;
@property (nonatomic, assign) BOOL immediateReturn;
@property (nonatomic, strong) UIButton *midButton;
@property (nonatomic, strong) UIImageView *arrowImg;
@property (nonatomic, strong) UIPopoverController *popController;
@property (assign, nonatomic) CATransform3D initialTransformation;

- (int)totalSelectedAssets;
- (void)takePicture;
- (void)setDataForImage: (NSMutableArray*)data;
- (void)doneAction:(id)sender;

- (void)assetSelected:(OCSDKELCAsset *)asset;
- (void)reloadInputTableView;

- (void)menuAction: (id)sender;

@end