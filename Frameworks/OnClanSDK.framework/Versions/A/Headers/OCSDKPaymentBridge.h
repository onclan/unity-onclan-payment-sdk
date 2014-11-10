//
//  OCSDKPaymentBridge.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/1/14.
//
//

#import <Foundation/Foundation.h>
#import "OCSDKConst.h"

/**
 *  PaymentSDK bridge class
 */
@interface OCSDKPaymentBridge : NSObject
+ (NSString*) getAccessTokenFromLoginDict;
+ (BOOL) checkGameSDKState;
+ (void) getOCSDKSessionWithCompletionBlock:(OCSDKObjectBlock) completionBlock;
+ (void) clearPaymentSDKSession;
@end
//extern "C" {
//    void _OCSDKMakePayment();
//}