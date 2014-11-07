//
//  ChatBubbleCell.h
//  NewAppotaApp
//
//  Created by ToanDK on 12/16/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AMMessage.h"
#import "OCSDKCircularProgressView.h"
//#import "OCSDKOHAttributedLabel.h"
#import <AVFoundation/AVFoundation.h>

//@interface OCSDKLeftChatBubbleCell : UITableViewCell<OHAttributedLabelDelegate> {
@interface OCSDKLeftChatBubbleCell : UITableViewCell<UITextViewDelegate> {
    __weak IBOutlet UIImageView *avatarImg;
    __weak IBOutlet UIImageView *borderImg, *backgroundImg, *clientImg;
//    __weak IBOutlet UILabel *nameLabel;
    __weak IBOutlet UIButton *maskBtn;
    __weak IBOutlet UILabel *contentLabel;
    __weak IBOutlet UIView *voiceView;
    __weak IBOutlet UILabel *voiceTimeLabel, *readLabel, *timeLabel;
    __weak IBOutlet UIButton *voicePlayBtn, *timeBtn;
    __weak IBOutlet UITextView *contentChatTextView;
    OCSDKCircularProgressView *progressView;
    AVPlayer *player;
    NSTimer *playingTimer;
    NSString *nameLabel;
    float playingDuration;
}
@property (nonatomic, assign) AMMessage *message;
@property (nonatomic, weak) IBOutlet UIImageView *photoImg;
@property (nonatomic, weak) IBOutlet UIButton *photoBtn;
+(float)heightForRowWithMessage:(AMMessage*)message;
-(void)setupCell:(AMMessage *)msg;
-(void)startPlayingVoice;

-(void)setCellWidth:(float)width;

//-(void)setupTimeLabel;

@end
