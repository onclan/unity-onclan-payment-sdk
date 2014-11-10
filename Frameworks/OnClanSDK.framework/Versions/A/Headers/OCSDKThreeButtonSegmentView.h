//
//  ThreeButtonSegmentView.h
//  NewAppotaApp
//
//  Created by Kien Nguyen on 8/1/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKKTSegmentView.h"

@interface OCSDKThreeButtonSegmentView : OCSDKKTSegmentView {
    IBOutlet UIButton *leftButton;
    IBOutlet UIButton *rightButton;
    IBOutlet UIButton *centerButton;
}
@end
