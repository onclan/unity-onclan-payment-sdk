//
//  UIBubbleTypingTableCell.h
//  UIBubbleTableViewExample
//
//  Created by Александр Баринов on 10/7/12.
//  Copyright (c) 2012 Stex Group. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKChatTableView.h"


@interface OCSDKChatTypingCell: UITableViewCell

+ (CGFloat)height;

@property (nonatomic) AMChatTypingType type;
@property (nonatomic) BOOL showAvatar;

@end
