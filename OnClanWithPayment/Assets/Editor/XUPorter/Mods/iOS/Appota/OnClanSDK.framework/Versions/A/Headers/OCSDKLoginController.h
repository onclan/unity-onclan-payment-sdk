//
//  OCSDKLoginController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 10/14/14.
//
//

#import <Foundation/Foundation.h>

@interface OCSDKLoginController : NSObject
+ (BOOL) handleLoginWithPaymentGameSDKObject:(id) object
                   withMessage:(NSString*) message;
@end
