//
//  MPNotificationView.h
//  Moped
//
//  Created by Engin Kurutepe on 1/2/13.
//  Copyright (c) 2013 Moped Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class OCSDKMPNotificationView;
@protocol OCSDKMPNotificationViewDelegate;

extern NSString *kMPNotificationViewTapReceivedNotification;

typedef void (^MPNotificationSimpleAction)(OCSDKMPNotificationView * view);

@interface OCSDKMPNotificationView : UIView

@property (nonatomic, strong) IBOutlet UILabel *textLabel;
@property (nonatomic, strong) IBOutlet UILabel *detailTextLabel;
@property (nonatomic, strong) IBOutlet UIImageView *imageView;
@property (nonatomic, assign) IBOutlet id<OCSDKMPNotificationViewDelegate> delegate;

@property (nonatomic) NSTimeInterval duration;

+ (OCSDKMPNotificationView *) notifyWithText:(NSString*)text
                                 detail:(NSString*)detail
                                  image:(UIImage*)image
                            andDuration:(NSTimeInterval)duration;

+ (OCSDKMPNotificationView *) notifyWithText:(NSString*)text
                                 detail:(NSString*)detail
                            andDuration:(NSTimeInterval)duration;

+ (OCSDKMPNotificationView *) notifyWithText:(NSString*)text
                              andDetail:(NSString*)detail;

+ (OCSDKMPNotificationView *) notifyWithText:(NSString*)text
                                 detail:(NSString*)detail
                                  image:(UIImage*)image
                               duration:(NSTimeInterval)duration
                          andTouchBlock:(MPNotificationSimpleAction)block;

+ (OCSDKMPNotificationView *) notifyWithText:(NSString*)text
                                 detail:(NSString*)detail
                               duration:(NSTimeInterval)duration
                          andTouchBlock:(MPNotificationSimpleAction)block;

+ (OCSDKMPNotificationView *) notifyWithText:(NSString*)text
                                 detail:(NSString*)detail
                          andTouchBlock:(MPNotificationSimpleAction)block;

+ (OCSDKMPNotificationView *) notifyWithText:(NSString*)text
                                 detail:(NSString*)detail
                                  image:(UIImage*)image
                               duration:(NSTimeInterval)duration
                                   type:(NSString *)type
                          andTouchBlock:(MPNotificationSimpleAction)block;


+ (void)registerNibNameOrClass:(id)nibNameOrClass
        forNotificationsOfType:(NSString *)type;
+ (void) showNextNotification;


@end

@protocol OCSDKMPNotificationViewDelegate <NSObject>

@optional
- (void)didTapOnNotificationView:(OCSDKMPNotificationView *)notificationView;

@end
