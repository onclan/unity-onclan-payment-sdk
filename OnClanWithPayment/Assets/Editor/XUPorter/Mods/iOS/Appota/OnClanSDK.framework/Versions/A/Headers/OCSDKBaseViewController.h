//
//  OCSDKBaseViewController.h
//  AppotaMessager
//
//  Created by ToanDK on 3/17/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKBundleController.h"

@interface OCSDKBaseViewController : UIViewController <UIGestureRecognizerDelegate> {
    
}
@property (nonatomic, strong) UILabel *labelTitle;
- (id)initUsingNibFile;
+ (id) initViewFromXib;
-(void)backView:(id)sender;
- (void)settitleLabel: (NSString*)title;
@end
