//
//  RecentChatCell.h
//  AppotaMessager
//
//  Created by ToanDK on 3/21/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseTableViewCell.h"
#import "OCRecentChatData.h"

@interface OCSDKRecentChatCell : OCSDKBaseTableViewCell {
    __weak IBOutlet UILabel *nameLabel, *timeLabel, *contentLabel;
    __weak IBOutlet UIImageView *avatarImg, *bgImg, *maskImg, *ribbonImg, *dotImg;
    __weak IBOutlet UIView *avatarView;
    
    IBOutlet UIView *viewLineBottom;
}

@property (nonatomic, strong) OCRecentChatData *chatData;

@end
