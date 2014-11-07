//
//  CHDraggableView+Avatar.h
//  ChatHeads
//
//  Created by Matthias Hochgatterer on 4/19/13.
//  Copyright (c) 2013 Matthias Hochgatterer. All rights reserved.
//

#import "OCSDKCHDraggableView.h"

@interface OCSDKCHDraggableView (Avatar)

+ (id)draggableViewWithImage:(UIImage *)image;
- (void) hideNotificationView;
- (void) showNotificationViewWithNum:(int) num;
@end
