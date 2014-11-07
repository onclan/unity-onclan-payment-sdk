//
//  OCSDKNavigationCustom.h
//  OnClanSDK
//
//  Created by TienLe on 8/7/14.
//
//

#import <UIKit/UIKit.h>

typedef enum {
    OCSDKKindNavigationButtoLeftClose = 0,
    OCSDKKindNavigationButtoLeftBack
}OCSDKKindNavigationButtonLeft;

typedef enum {
    OCSDKKindNavigationButtonRightEdit = 0,
    OCSDKKindNavigationButtonRightInfo,
    OCSDKKindNavigationButtonRightCamera,
    OCSDKKindNavigationButtonRightAdd,
    OCSDKKindNavigationButtonRightOverrall,
    OCSDKKindNavigationButtonRightFriend,
    OCSDKKindNavigationButtonRightLogout,
    OCSDKKindNavigationButtonRightDone
}OCSDKKindNavigationButtonRight;

typedef enum {
    OCSDKNavigationCustomKeyboardShow,
    OCSDKNavigationCustomKeyboardHide
}OCSDKNavigationCustomKeyboard;

@protocol OCSDKNavigationCustomKeyboardDelegate <NSObject>
@optional
- (void)startOCSDKPushViewUp;
- (void)startOCSDKPullViewDown;
- (void)notificationKeyboardView:(BOOL)isShow;
- (void)clearTextOnSearchText;
@end

@class OCSDKAwesomeMenu;
@interface OCSDKNavigationCustom : UIView <UITextFieldDelegate>
@property (strong, nonatomic) OCSDKAwesomeMenu *circleMenu;
@property (strong, nonatomic) IBOutlet UIImageView *imageHeader;
@property (strong, nonatomic) IBOutlet UIButton *buttonLeft;
@property (strong, nonatomic) IBOutlet UIButton *buttonRight;
@property (strong, nonatomic) IBOutlet UIButton *buttonChangeImage;
@property (strong, nonatomic) IBOutlet UIButton *buttonMid;
@property (strong, nonatomic) IBOutlet UIImageView *formBackgroundImageView;
@property (strong, nonatomic) IBOutlet UIImageView *searchBackground;
@property (strong, nonatomic) IBOutlet UITextField *searchText;
@property (strong, nonatomic) IBOutlet UIView *viewContentSearch;
@property (strong, nonatomic) IBOutlet UIView *viewContentButtonMid;
@property (strong, nonatomic) IBOutlet UILabel *labelButtonMid;
@property (strong, nonatomic) IBOutlet UIButton *buttonHeader;
@property (strong, nonatomic) IBOutlet UIImageView *arrowDownImageView;

@property (assign, nonatomic) OCSDKKindNavigationButtonLeft leftButtonKind;
@property (assign, nonatomic) OCSDKKindNavigationButtonRight rightButtonKind;
@property (assign, nonatomic) OCSDKNavigationCustomKeyboard keyboardKind;

@property (assign, nonatomic) id <OCSDKNavigationCustomKeyboardDelegate> showKeyboardDelegate;

+ (id)drawOCSDKNavigationCustomView;
- (void)drawImageHeaderWithImage:(NSString*)imageName;
- (void)drawImageHeaderWithURL:(NSURL*)url andPladeholderText:(NSString*)placeHolderText;
- (void)drawAvatarImageHeaderWithURL:(NSURL*) url withPlaceHolder:(NSString*) placeHolderImageName;
- (void)setButtonLeftKind:(OCSDKKindNavigationButtonLeft)leftKind;
- (void)setButtonRightKind:(OCSDKKindNavigationButtonRight)rightKind;
- (void)drawImageButtonChangeImage;
- (void)setLineFormBackGround;
- (void)drawSearchBar;
- (void)drawButtonMidWithTitle:(NSString*)title;

- (IBAction)pressCircleButton:(id)sender;
- (IBAction)pressChangeImage:(id)sender;
- (IBAction)pressLeftButton:(id)sender;
- (IBAction)pressRightButton:(id)sender;
- (IBAction)pressMidButton:(id)sender;
@end
