//
//  UIImage+TintHelper.h
//  NewAppotaApp
//
//  Created by tuent on 7/5/13.
//  Copyright (c) 2013 ToanDK's Mac. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (OCSDKHelper)
- (UIImage *)tintedImageUsingColor:(UIColor *)tintColor;
+ (UIImage *)imageWithColor:(UIColor *)color andSize:(CGSize)size;
- (UIImage *) scaleAndRotateImage: (UIImage *)image;
@end
