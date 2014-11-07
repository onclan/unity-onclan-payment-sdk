//
//  OCSDKInputLoginView.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/23/14.
//
//

#import "OCSDKBaseView.h"
#import "OCSKTwoButtonSegmentSmallView.h"

@interface OCSDKInputLoginView : OCSDKBaseView <KTSegmentViewDelegate, UITextFieldDelegate>
{
    IBOutlet OCSKTwoButtonSegmentSmallView *segmentView;
    IBOutlet UIView *inputLoginContentView;
    
    IBOutlet UITextField *usernameTextField;
    IBOutlet UITextField *passwordTextField;
    IBOutlet UIButton *quickLoginButton;
    IBOutlet UIButton *loginButton;
    
    IBOutlet UITextField *registerTextField;
    IBOutlet UITextField *registerPasswordTextField;
    IBOutlet UITextField *registerEmailTextField;
    IBOutlet UITextField *registerFullNameTextField;
    IBOutlet UIButton *registerCancelButton;
    IBOutlet UIButton *registerButton;
    IBOutlet UIView *inputRegisterContentView;
}

- (UITextField*) getEditingTextField;

- (IBAction)registerButtonAction:(id)sender;
- (IBAction)cancelRegisterButtonAction:(id)sender;
- (IBAction)getOnClanAction:(id)sender;

- (IBAction)forgotPasswordAction:(id)sender;
- (IBAction)closeButtonAction:(id)sender;
- (IBAction)twitterLoginAction:(id)sender;
- (IBAction)ggLoginAction:(id)sender;
- (IBAction)fbLoginAction:(id)sender;
- (IBAction)loginButtonAction:(id)sender;
- (IBAction)quickLoginButonAction:(id)sender;
@end
