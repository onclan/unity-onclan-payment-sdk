//
//  ELCAssetTablePicker+Animation.h
//  onClan
//
//  Created by Appota on 6/12/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import "OCSDKELCAssetTablePicker.h"

@interface OCSDKELCAssetTablePicker (Animation)

- (void)removeMenuView;
- (void)addMenuView;
- (void)addCellCamera;
- (void)setupRightMenuButton;
- (void)setupMidMenuButton;

- (void)animationCell: (UITableViewCell*)cell;

@end
