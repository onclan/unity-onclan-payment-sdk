//
//  AMClanChatTableViewCell.h
//  AppotaMessager
//
//  Created by Appota on 7/7/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseTableViewCell.h"

@class OCSDKClanObject;
@interface OCSDKListClanChatTableViewCell : OCSDKBaseTableViewCell {
    __weak IBOutlet UILabel *nameLabel, *timeLabel, *contentLabel;
    __weak IBOutlet UIImageView *avatarImg, *bgImg, *maskImg, *ribbonImg, *dotImg;
    __weak IBOutlet UIImageView *lockImg;
    __weak IBOutlet UIView *avatarView;
    __weak IBOutlet UIButton *joinBtn;
    OCSDKClanObject *clanObject;
}


@end
