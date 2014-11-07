//
//  ControlBubbleCell.h
//  NewAppotaApp
//
//  Created by ToanDK on 12/16/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "NSBubbleData.h"
#import "OCSDKLeftChatBubbleCell.h"

@interface OCSDKChatControlBubbleCell : OCSDKLeftChatBubbleCell {
    __weak IBOutlet UILabel *controlLabel;
}

@end
