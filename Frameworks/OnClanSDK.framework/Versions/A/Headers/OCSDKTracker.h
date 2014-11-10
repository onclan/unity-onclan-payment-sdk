//
//  OCSDKTracker.h
//  OnClanSDK
//
//  Created by ToanDK on 10/31/14.
//
//

#import <Foundation/Foundation.h>

@interface OCSDKTracker : NSObject

+ (OCSDKTracker*) sharedInstance;

//- (void) applicationWillTerminate;

- (void) setupObservers;

@end
