//
//  OCSDKPlayerTableCell.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/14/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseTableViewCell.h"

@interface OCSDKPlayerTableCell : OCSDKBaseTableViewCell
{
    IBOutlet UIImageView *avatarImageView;
    IBOutlet UILabel *nameLabel;
    IBOutlet UILabel *descriptionLabel;
    IBOutlet UIButton *followBtn;
}
- (IBAction)followBtnAction:(id)sender;
@end
