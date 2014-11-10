//
//  OCSDKScoreTableViewCell.h
//  OnClanSDK
//
//  Created by Appota on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKFriendViewCell.h"

@interface OCSDKScoreTableViewCell : OCSDKFriendViewCell {
//    NSDictionary *cellDict;
//    
//    IBOutlet UIImageView *avatarUser;
//    IBOutlet UILabel *nameUser;
    __weak IBOutlet UILabel *userPointLabel;
    __weak IBOutlet UILabel *statusLabel;
    __weak IBOutlet UIImageView *topImageView;
}
//@property (strong, nonatomic) IBOutlet UIButton *buttonFollow;
//@property (strong, nonatomic) IBOutlet UILabel *labelSTT;
//@property (strong, nonatomic) IBOutlet UIImageView *imageTop;

//- (IBAction)pressViewUserWall:(id)sender;
//- (IBAction)pressFollow:(id)sender;


@end
