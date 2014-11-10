//
//  YKImageCropperViewController.h
//  Copyright (c) 2013 yuyak. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKBaseViewController+TwoMenu.h"

@interface OCSDKYKImageCropperViewController : OCSDKBaseViewController <UIActionSheetDelegate>

@property (nonatomic, copy) void (^doneHandler)(UIImage *editedImage);
@property (nonatomic, copy) void (^cancelHandler)();
@property (nonatomic, assign) float cropRatio;

- (id)initWithImage:(UIImage *)image;

@end