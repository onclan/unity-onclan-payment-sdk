//
//  FriendViewCell.h
//  AppotaMessager
//
//  Created by ToanDK on 3/17/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseTableViewCell.h"

@class OCSDKPlayerObject;
@interface OCSDKFriendViewCell : OCSDKBaseTableViewCell {
    __weak IBOutlet UIImageView *avatarView, *devMaskImg;
    __weak IBOutlet UILabel *nameLabel, *levelLabel;
    __weak IBOutlet UIButton *onlineBtn;    
}

@property (nonatomic, strong) OCSDKPlayerObject *playerObject;
@property (nonatomic, weak) IBOutlet UIButton *followBtn;
@property (nonatomic, weak) IBOutlet UIImageView *bgImg, *maskImg;
@property (nonatomic, weak) IBOutlet UILabel *followLabel;

- (IBAction)buttonFollow:(id)sender;
@end
