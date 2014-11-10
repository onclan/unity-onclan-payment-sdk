//
//  NSThread+OCSDKAdditions.h
//  OCSDKFoundation
//
//  Created by Spencer MacDonald on 06/07/2011.
//  Copyright 2011 Square Bracket Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSThread (OCSDKAdditions)

+ (void)OCSDK_performBlockOnMainThread:(void (^)())block;
+ (void)OCSDK_performBlockInBackground:(void (^)())block;
+ (void)OCSDK_runBlock:(void (^)())block;
- (void)OCSDK_performBlock:(void (^)())block;
- (void)OCSDK_performBlock:(void (^)())block waitUntilDone:(BOOL)wait;
- (void)OCSDK_performBlock:(void (^)())block afterDelay:(NSTimeInterval)delay;

@end
