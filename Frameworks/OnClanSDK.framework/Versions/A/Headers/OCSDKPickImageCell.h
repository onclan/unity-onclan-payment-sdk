//
//  PickImageCell.h
//  NewAppotaApp
//
//  Created by Appota on 6/7/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface OCSDKPickImageCell : UITableViewCell {
    
    IBOutlet UILabel *labelNumberImage;
    IBOutlet UILabel *labelNameAlbum;
    IBOutlet UIButton *buttonSellected;
    
}
@property (strong, nonatomic) IBOutlet UIImageView *imageAlbum;
+ (id)cellFromNib;
- (void)setDataForCell: (NSMutableDictionary*)data;
@end
