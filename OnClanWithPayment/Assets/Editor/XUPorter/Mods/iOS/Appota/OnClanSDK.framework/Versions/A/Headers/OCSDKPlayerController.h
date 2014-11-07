//
//  OCSDKPlayerController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/23/14.
//
//

#import <Foundation/Foundation.h>
@class OCSDKPlayerObject;
@interface OCSDKPlayerController : NSObject
+ (void) pushToActionSheetWithPlayerObject:(OCSDKPlayerObject*) playerObject
                                  fromView:(UIView*) view andShowInView:(UIView*)aView;
+ (void) pushToChatWithPlayerObject:(OCSDKPlayerObject*) playerObject
                           fromView:(UIView*) view andShowInView:(UIView*)aView;
+ (void) pushChatWithUserID:(NSString*) userID fromView:(UIView*) view andShowInView:(UIView*)aView;

+ (void) pushToActionSheetWithAdminPlayerObject:(OCSDKPlayerObject *)playerObject
                                       fromView:(UIView *)view andShowInView:(UIView*)aView;

//+ (void)showAlertControllerWith:(OCSDKPlayerObject*)playerObject inViewController:(UIViewController*)vc;
@end
