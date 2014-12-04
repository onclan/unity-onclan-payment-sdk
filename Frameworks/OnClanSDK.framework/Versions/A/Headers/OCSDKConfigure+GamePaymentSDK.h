//
//  OCSDKConfigure+GamePaymentSDK.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 10/13/14.
//
//

#import "OCSDKConfigure.h"

@interface OCSDKConfigure (GamePaymentSDK)
+ (BOOL) isUsingAppotaPaymentSDK;
- (void) registerGamePaymentNotification;
- (void) proceedGameSDKWithOCSDK;
+ (void) logoutPaymentGameSDK;
+ (BOOL) verifyGameSDKLoginDictAndUpdateInfo:(NSDictionary*) loginDict;
+ (BOOL) isGameSDKDebugMode;
@end
