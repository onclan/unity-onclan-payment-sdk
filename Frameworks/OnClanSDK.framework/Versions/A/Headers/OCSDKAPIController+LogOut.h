//
//  OCSDKAPIController+LogOut.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/30/14.
//
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (LogOut)
- (void) logOutWithCompletionBlock:(OCSDKObjectBlock) completionBlock
                    withErrorBlock:(OCSDKErrorBlock) errorBlock;
@end
