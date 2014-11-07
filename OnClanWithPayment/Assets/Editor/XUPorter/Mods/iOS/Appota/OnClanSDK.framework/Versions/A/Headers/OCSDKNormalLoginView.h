//
//  OCSDKNormalLoginView.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/7/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseView.h"

@interface OCSDKNormalLoginView : OCSDKBaseView <UITextFieldDelegate>
{
    __weak IBOutlet UIImageView *bgImageView;
    __weak IBOutlet UITextField *textFieldLine1;    // Store username
    __weak IBOutlet UITextField *textFieldLine2;    // Store password
    __weak IBOutlet UIButton *cancelButton;
    __weak IBOutlet UIButton *okButton;
}
- (IBAction)cancelButtonAction:(id)sender;
- (IBAction)okButtonAction:(id)sender;

@end
