//
//  BaseTableViewCell.h
//  Appvn
//
//  Created by tuent on 2/6/14.
//  Copyright (c) 2014 Appota. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKBundleController.h"

@interface OCSDKBaseTableViewCell : UITableViewCell
@property (strong, nonatomic) NSIndexPath *cellIndexPath;
- (void) configCell:(id) data;
- (void) selectCell:(id) data;
- (void) removeHandlers;
+ (UINib *)nib;
+ (NSString*) nibName;
+ (float) height;
@end
