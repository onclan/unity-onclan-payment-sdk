//
//  NSObject+PerformBlocks.h
//  NewAppotaApp
//
//  Created by ToanDK's Mac on 5/14/13.
//  Copyright (c) 2013 ToanDK's Mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (OCSDKPerformBlocks)

- (void)performBlock:(void (^)(void))block
          afterDelay:(NSTimeInterval)delay;

void runOnMainQueueWithoutDeadlocking(void (^block)(void));

@end
