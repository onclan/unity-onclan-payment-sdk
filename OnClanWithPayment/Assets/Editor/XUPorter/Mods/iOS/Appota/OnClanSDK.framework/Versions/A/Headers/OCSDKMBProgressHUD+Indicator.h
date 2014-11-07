//
//  MBProgressHUD+Indicator.h
//  Appvn
//
//  Created by tuent on 3/25/14.
//  Copyright (c) 2014 Appota. All rights reserved.
//

#import "OCSDKMBProgressHUD.h"

@interface OCSDKMBProgressHUD (Indicator)
//- (void) setIndicatorStyle:(UIActivityIndicatorViewStyle) style;
//- (UIActivityIndicatorView*) getIndicatorView;
+ (id) showHUDWithIndicatorStyle:(UIActivityIndicatorViewStyle) style;
+ (id) showHUDWithIndicatorStyle:(UIActivityIndicatorViewStyle)style
                        withView:(UIView*) view;

+ (id) showHUDWithIndicatorStyle:(UIActivityIndicatorViewStyle)style
                           color:(UIColor*) color
                        withView:(UIView*) view;

@end
