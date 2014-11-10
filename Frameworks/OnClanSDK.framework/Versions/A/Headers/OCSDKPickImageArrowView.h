//
//  PickImageArrowView.h
//  NewAppotaApp
//
//  Created by Appota on 6/4/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface OCSDKPickImageArrowView : UIView
@property (nonatomic, strong) UIImageView *arrowImage;
- (UIImage *)drawArrowImage:(CGSize)size;
@end
