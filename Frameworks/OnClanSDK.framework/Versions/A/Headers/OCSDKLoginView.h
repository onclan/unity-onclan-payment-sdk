//
//  OCSDKLoginView.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/3/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKBaseView.h"

@interface OCSDKLoginView : OCSDKBaseView
{
    __weak IBOutlet UIButton *closeButton;
    
    __weak IBOutlet UIButton *loginButton;
    __weak IBOutlet UIButton *quickLoginButton;
    __weak IBOutlet UIButton *fbLoginButton;
    __weak IBOutlet UIButton *ggLoginButton;
    __weak IBOutlet UIButton *twitterLoginButton;
    __weak IBOutlet UIButton *ocLoginButton;
    __weak IBOutlet UIButton *signUpButton;
    __weak IBOutlet UIButton *forgotButton;
    __weak IBOutlet UIImageView *loginBackgroundView;
}
- (IBAction)forgotButtonAction:(id)sender;
- (IBAction)signUpButtonAction:(id)sender;
- (IBAction)ocLoginButtonAction:(id)sender;
- (IBAction)twitterLoginButtonAction:(id)sender;
- (IBAction)ggLoginButtonAction:(id)sender;
- (IBAction)fbLoginButtonAction:(id)sender;
- (IBAction)quickLoginButtonAction:(id)sender;
- (IBAction)loginButtonAction:(id)sender;
- (IBAction)closeButtonAction:(id)sender;
@end
