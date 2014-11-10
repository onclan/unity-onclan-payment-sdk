//
//  YKImageCropperView.h
//  Copyright (c) 2013 yuyak. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface OCSDKYKImageCropperView : UIView

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, readwrite) float cropRatio;
@property (nonatomic, assign) BOOL keepingAspectRatio;

- (UIImage *)editedImage;
- (id)initWithImage:(UIImage *)image;
- (void)reset;
- (void)square;
- (void)setConstrain:(CGSize)size;

@end