//
//  EmoticonView.h
//  NewAppotaApp
//
//  Created by ToanDK on 6/12/13.
//  Copyright (c) 2013 ToanDK's Mac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKCustomSegmentedControl.h"
#import "OCSDKBaseView.h"
//#import "Emoji.h"
//#import "StickerGroup.h"

//typedef void (^EmojiBlock)(Emoji *emoji);

typedef void (^EmojiBlock)(NSDictionary* emojiDict);

@class OCSDKChatRecordView;

#define EMOJI_RUNNING_IPHONE        ( [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone )
#define EMOJI_ITEM_SIZE             ( EMOJI_RUNNING_IPHONE ? 40.f : 40.f )
#define EMOJI_FONT_SIZE             ( EMOJI_RUNNING_IPHONE ? 32.f : 32.f )
#define EMOJI_NB_ITEM_IN_ROW        ( EMOJI_RUNNING_IPHONE ? 7.f : 7.f )
#define EMOJI_NB_ITEM_IN_COL        ( EMOJI_RUNNING_IPHONE ? 2.f : 2.f )
#define EMOJI_GRID_MARGIN           ( EMOJI_RUNNING_IPHONE ? 1.f : 2.f )
#define EMOJI_GRID_DEFAULT_WIDTH    ( EMOJI_ITEM_SIZE * EMOJI_NB_ITEM_IN_ROW + EMOJI_GRID_MARGIN * 2.f )
#define EMOJI_GRID_DEFAULT_HEIGHT   ( EMOJI_ITEM_SIZE * EMOJI_NB_ITEM_IN_COL + EMOJI_GRID_MARGIN * 2.f )
#define EMOJI_PAGECONTROL_HEIGHT    10.f

#define STICKY_ITEM_SIZE             ( EMOJI_RUNNING_IPHONE ? 70.f : 70.f )
#define STICKY_NB_ITEM_IN_ROW        ( EMOJI_RUNNING_IPHONE ? 4.f : 4.f )
#define STICKY_NB_ITEM_IN_COL        ( EMOJI_RUNNING_IPHONE ? 2.f : 2.f )

@class OCSDKChatEmoticonView;

@protocol EmoticonDelegate <NSObject>
@required
-(void)emoticonView:(OCSDKChatEmoticonView*)emoticonView didClickedOnCharacter:(NSString*)character;
-(void)emoticonView:(OCSDKChatEmoticonView*)emoticonView didClickedOnSticky:(NSDictionary*)sticky;
-(void)emoticonView:(OCSDKChatEmoticonView*)emoticonView clearEmoji:(id)sender;
-(void)emoticonView:(OCSDKChatEmoticonView*)emoticonView didSelectImage:(UIImage *)image;
-(void)emoticonView:(OCSDKChatEmoticonView *)emoticonView didRecordVoice:(NSString *)soundFile withLength:(float)time;

@end

@interface OCSDKChatEmoticonView : OCSDKBaseView<UIScrollViewDelegate, OCSDKCustomSegmentedControlDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate> {
    __weak IBOutlet UIScrollView *scrollView, *tabScrollView;
    __weak IBOutlet UIPageControl *pageControl;
    __weak IBOutlet UIView *attachmentView, *tabView;
    __weak IBOutlet UIButton *photoBtn, *voiceBtn;
    
    NSMutableArray *tableViews, *stickyGroupList;
    int totalPages;
    OCSDKCustomSegmentedControl *tabControl;
}
@property (weak, nonatomic) id<EmoticonDelegate> delegate;

+(OCSDKChatEmoticonView *)createNewViewWithSuperView:(UIView*)superView;
+(NSDictionary *)getEmojiCodeDict;
+(NSDictionary *)getStickyCodeDict;
+(NSString *)stringByEncodingEmojiCharacter:(NSString *)inputString;
+(NSString *)stringByDecodingEmojiCharacter:(NSString *)inputString;
+(NSString *)stringByEncodingStickyCharacter:(NSString *)inputString;
+(NSString *)stringByDecodingStickyCharacter:(NSString *)inputString;
+(void)addNewStickerGroup:(NSDictionary *)dict;
+(void)getStickerDictFromId:(NSString *)stickerId completeBlock:(EmojiBlock)completionBlock;
-(void)showStickyTab;
+(void)addDefaultSticker;
-(void)layoutViewAfterRotation:(UIView *)superView;
-(void)removeDelegate;

@end
