//
//  ChatInputView.h
//  NewAppotaApp
//
//  Created by ToanDK on 8/19/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKBaseNibLoadedView.h"

typedef enum {
    AnimationStateNormal = 0,
    AnimationStateAnimating,
    AnimationStateDone,
} AnimationState;

@protocol ChatInputViewDelegate <NSObject>

-(void)chatInputDidSelectEmoji;
-(void)chatInputDidSelectSticky;
-(void)chatInputDidSendText:(NSString *)text;
-(void)chatInputDidSelectRecord:(BOOL)showRecord;
-(void)chatInputDidSelectAlias;
-(void)chatInputDidSelectLike;
-(BOOL)chatInputCanSendLike;
@end

@interface OCSDKChatInputView : OCSDKBaseNibLoadedView <UITextViewDelegate> {
    __weak IBOutlet UIButton *emojiBtn, *sendBtn, *recordBtn, *likeButton;
    __weak IBOutlet UIButton *aliasBtn, *colorBtn;
    IBOutlet UIView *colorView;
    float keyboardHeight;
    BOOL isShowingKeyboard, isEditingChat;
}
@property (nonatomic, weak) id<ChatInputViewDelegate> delegate;
@property (nonatomic, weak) IBOutlet UITextView *textView;
@property (nonatomic, weak) IBOutlet UILabel *placeHolderLabel;
@property (nonatomic, assign) BOOL enableRecording;

-(void)addGestureToView:(UIView *)aview;
-(void)setText:(NSString *)text;
-(void)hideKeyboard:(id)sender;
-(void)hideColorPicker;
-(void)setRecordButtonHidden:(BOOL)hidden;
-(void)enableChoosingAlias;

@end
