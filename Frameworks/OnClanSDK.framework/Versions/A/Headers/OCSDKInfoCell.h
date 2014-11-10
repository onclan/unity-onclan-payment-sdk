//
//  OCSDKInfoCell.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 10/1/14.
//
//

#import "OCSDKBaseTableViewCell.h"

@interface OCSDKInfoCell : OCSDKBaseTableViewCell
@property (strong, nonatomic) IBOutletCollection(UIImageView) NSArray *infoImageViewArray;
- (IBAction)chooseInfoType:(id)sender;

@end
