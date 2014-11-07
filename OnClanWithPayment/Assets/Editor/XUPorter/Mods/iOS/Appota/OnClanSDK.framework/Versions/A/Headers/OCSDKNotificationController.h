//
//  OCSDKNotificationController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/6/14.
//
//

#import <Foundation/Foundation.h>

#define REFRESH_CHAT_RECENT_TABLE           @"RefreshChatRecentTable"

/**
 *  This class design for handling sdk action notification
 */
@interface OCSDKNotificationController : NSObject
+ (OCSDKNotificationController *) sharedInstance;
+ (void) closeSDK;
+ (void) showSDK;
+ (void) captureScreenWithFileName:(NSString*) filePath;
+ (void) finishPayment:(NSString*) paymentAmount;
@end
