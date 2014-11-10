//
//  RecordView.h
//  NewSDK
//
//  Created by Anh Toan on 12/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "OCSDKChatEmoticonView.h"
#import "OCSDKBaseView.h"

typedef enum {
    kTouchStateInside = 0,
    kTouchStateOutside,
} kTouchState;

@interface OCSDKChatRecordView : OCSDKBaseView<AVAudioRecorderDelegate> {
    NSString *saveFileName;
    
    float startTime;
    NSTimer *tickTimer;
    AVAudioRecorder *avRecorder;
    NSTimer *timer;
    AVPlayer *player;
    kTouchState touchState;
    __weak IBOutlet UIImageView *cancelImg, *recordImg;
    __weak IBOutlet UILabel *timeLabel, *cancelLabel;
    __weak IBOutlet UIButton *recordBtn, *keyboardBtn;
    IBOutlet UIView *bottomView, *meterView, *recordScreenView;
    IBOutlet UIImageView *voiceIcon;
}
@property (weak, atomic) id<EmoticonDelegate> delegate;

+(OCSDKChatRecordView *)createNewView;
-(void)layoutViewAfterRotation:(UIView*)parentView;
-(void)showRecordScreen:(BOOL)isShow;
-(void)prepareRecording;
-(void)willRotateToWidth:(float)width;

@end
