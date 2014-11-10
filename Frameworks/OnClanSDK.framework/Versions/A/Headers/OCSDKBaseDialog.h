//
//  AppotaDialog.h
//  AppotaExample2
//
//  Created by tuent on 5/10/13.
//
//

#import <UIKit/UIKit.h>
@protocol AppotaDialogDelegate;


@interface OCSDKBaseDialog : UIView <UIWebViewDelegate, UIScrollViewDelegate> {

    UIInterfaceOrientation _orientation;
    BOOL _showingKeyboard;
    BOOL _isViewInvisible;
    
    CGFloat kPadding;
    CGFloat kBorderWidth;

    
    // Ensures that UI elements behind the dialog are disabled.
    UIView* _modalBackgroundView;
}
/**
 * The delegate.
 */
@property(nonatomic, assign) id<AppotaDialogDelegate> delegate;

- (void) showWithAnimation:(BOOL) animated;
- (void)show;
- (void)cancel;
- (void) hideOrShowViewWithState:(BOOL) hideState;
@end

///////////////////////////////////////////////////////////////////////////////////////////////////

/*
 *Your application should implement this delegate
 */
@protocol AppotaDialogDelegate <NSObject>
- (void) closeWebView;
@optional

/**
 * Called when the dialog succeeds and is about to be dismissed.
 */
- (void)dialogDidComplete:(OCSDKBaseDialog *)dialog;

/**
 * Called when the dialog succeeds with a returning url.
 */
- (void)dialogCompleteWithUrl:(NSURL *)url;

/**
 * Called when the dialog get canceled by the user.
 */
- (void)dialogDidNotCompleteWithUrl:(NSURL *)url;

/**
 * Called when the dialog is cancelled and is about to be dismissed.
 */
- (void)dialogDidNotComplete:(OCSDKBaseDialog *)dialog;

/**
 * Called when dialog failed to load due to an error.
 */
- (void)dialog:(OCSDKBaseDialog*)dialog didFailWithError:(NSError *)error;

/**
 * Asks if a link touched by a user should be opened in an external browser.
 *
 * If a user touches a link, the default behavior is to open the link in the Safari browser,
 * which will cause your app to quit.  You may want to prevent this from happening, open the link
 * in your own internal browser, or perhaps warn the user that they are about to leave your app.
 * If so, implement this method on your delegate and return NO.  If you warn the user, you
 * should hold onto the URL and once you have received their acknowledgement open the URL yourself
 * using [[UIApplication sharedApplication] openURL:].
 */
- (BOOL)dialog:(OCSDKBaseDialog*)dialog shouldOpenURLInExternalBrowser:(NSURL *)url;

- (void)dismiss:(BOOL)animated;

@end
