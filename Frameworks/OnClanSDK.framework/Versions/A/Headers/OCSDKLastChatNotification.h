//
//  OCSDKLastChatNotification.h
//  OnClanSDK
//
//  Created by TienLe on 1/19/15.
//
//

#import <Foundation/Foundation.h>

@interface OCSDKLastChatNotification : NSObject

+ (OCSDKLastChatNotification*) sharedInstance;

- (void)saveLastTopicId:(NSString *)topicId;
- (BOOL)checkTimeIsAvailable;
- (NSString*)getLastTopicId;

@end
