//
//  OCSDKLeaderboardTableviewCell.h
//  OnClanSDK
//
//  Created by Appota on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseTableViewCell.h"

@interface OCSDKLeaderboardTableviewCell : UITableViewCell {
    
    IBOutlet UIImageView *avatarLeaderboard;
    IBOutlet UILabel *nameLeaderboard;
    NSDictionary *cellDict;
}
+ (id)cellFromNib;
-(void)configCell:(id)data;
@end
