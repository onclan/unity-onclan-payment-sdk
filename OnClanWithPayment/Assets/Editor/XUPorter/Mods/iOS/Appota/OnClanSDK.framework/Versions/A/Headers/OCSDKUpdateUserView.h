//
//  OCSDKUpdateUserView.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/14/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseView.h"

@interface OCSDKUpdateUserView : OCSDKBaseView  <UITextFieldDelegate>{
    
    IBOutlet UILabel *titleLabel;
    IBOutlet UILabel *userNameLabel;
    IBOutlet UILabel *updateDescriptionLabel;
    IBOutlet UITextField *userNameTextField;
    IBOutlet UITextField *passwordTextField;
    IBOutlet UITextField *emailTextField;
    IBOutlet UIButton *updateButton;
    IBOutlet UIButton *cancelButton;
    IBOutlet UIImageView *passwordBackgroundImageView;
    IBOutlet UIImageView *emailBackgroundImageView;    
    IBOutlet UIImageView *usernameBackgroundImageView;
}
- (IBAction)updateButtonAction:(id)sender;
- (IBAction)cancelButtonAction:(id)sender;
- (IBAction)logOutButtonAction:(id)sender;

- (void) setupViewWithEmail:(NSString*) emailString
        withRequirePassword:(BOOL) requirePassword;
@end
