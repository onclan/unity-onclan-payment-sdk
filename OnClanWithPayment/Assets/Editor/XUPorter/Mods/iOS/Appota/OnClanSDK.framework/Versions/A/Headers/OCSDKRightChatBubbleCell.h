//
//  RightChatBubbleCell.h
//  NewAppotaApp
//
//  Created by ToanDK on 12/16/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import "OCSDKLeftChatBubbleCell.h"

@interface OCSDKRightChatBubbleCell : OCSDKLeftChatBubbleCell {
    __weak IBOutlet UIButton *errorButton;
    __weak IBOutlet UIImageView *loadingIcon;
}

@end
