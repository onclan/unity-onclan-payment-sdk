//
//  AssetCell.h
//
//  Created by ELC on 2/15/11.
//  Copyright 2011 ELC Technologies. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <AVFoundation/AVFoundation.h>
#import "OCSDKELCAsset.h"

@protocol ELCAssetCellSingleClick
- (void)singleClick:(OCSDKELCAsset*)asset;

@end


@interface OCSDKELCAssetCell : UITableViewCell <UIAlertViewDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate>{
    IBOutlet UIImageView *image1;
    IBOutlet UIImageView *image2;
    IBOutlet UIImageView *image3;
    IBOutlet UIImageView *image4;
}
@property (strong, nonatomic) IBOutletCollection(UIImageView) NSArray *imageCollection;
@property (strong, nonatomic) IBOutletCollection(UIButton) NSArray *buttonCollection;
@property (strong, nonatomic) IBOutlet UIButton *button1;
@property (strong, nonatomic) IBOutlet UIButton *button2;
@property (strong, nonatomic) IBOutlet UIButton *button3;
@property (strong, nonatomic) IBOutlet UIButton *button4;
@property (nonatomic) BOOL singleSellection;

@property (weak, nonatomic) id<ELCAssetCellSingleClick>delegate;


+ (id)cellFromNib;
- (void)setDataForCell: (NSMutableArray*)data;

- (IBAction)selectImage:(id)sender;

@end
