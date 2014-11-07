//
//  AMTwoButtonSegmentView.h
//  OnClanSDK
//
//  Created by Appota on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKKTSegmentView.h"

@interface OCSDKTwoButtonSegmentView : OCSDKKTSegmentView {
    
    __weak IBOutlet UIButton *leftButton;
    __weak IBOutlet UIButton *rightButton;
    __weak IBOutlet UIView *viewRunAtBottom;
}

@end
