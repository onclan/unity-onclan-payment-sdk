//
//  OCSDKRegisterView.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKNormalLoginView.h"
/**
 *  TextField1 - Store username
 *  TextField2 - Store password
 */
@interface OCSDKRegisterView : OCSDKNormalLoginView<UITextFieldDelegate> {    
    IBOutlet UIImageView *avatarImageView;
    IBOutlet UIButton *chooseAvatarButton;
}
- (IBAction)chooseAvatarAction:(id)sender;

@end
