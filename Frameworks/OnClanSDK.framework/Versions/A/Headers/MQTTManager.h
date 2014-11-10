//
//  MQTTManager.h
//  NewAppotaApp
//
//  Created by ToanDK on 3/5/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MQTTManager : NSObject {
    NSDictionary *broker;
    NSString *currentChatTopic;
}
@property (nonatomic, assign) BOOL enableBackgroundNotification;

+(MQTTManager *)sharedManager;

-(void)setUpNotificationSystem;
-(void)reconnectMQTT;
-(void)disconnectMQTT;
-(BOOL)didSetupNotificationSystem;

- (NSString *)currentChatTopic;

- (void)setCurrentChatTopic:(NSString *)newValue;

@end
