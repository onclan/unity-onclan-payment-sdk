//
//  OCSDKBaseViewController+TwoMenu.h
//  NewAppotaApp
//
//  Created by Kien Nguyen on 6/13/13.
//  Copyright (c) 2013 ToanDK's Mac. All rights reserved.
//

#import "OCSDKBaseViewController.h"

@interface UIViewController (TwoMenu)
-(void) setupLeftMenuButton;
-(void) setupRightMenuButton;
-(UIButton *) createButtonWithImageNamed:(NSString *)imageName highLightImage:(NSString *)hlightImg target:(id)target action:(SEL)selector;

-(void)addCustomBackBtn;

-(void) setRightBarItem:(UIBarButtonItem *)item;

-(void)setLeftBarItem:(UIBarButtonItem *)item;

-(void)addCancelButtonWithTarget:(id)target selector:(SEL)selector;
-(void)addDoneButtonWithTarget:(id)target selector:(SEL)selector;
-(void)prePressLeftButton;
@end
