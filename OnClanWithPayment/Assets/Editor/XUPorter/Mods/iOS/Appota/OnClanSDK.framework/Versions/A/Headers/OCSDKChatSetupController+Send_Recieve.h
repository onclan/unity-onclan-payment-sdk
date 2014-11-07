//
//  ChatBubbleController+Send_Recieve.h
//  NewAppotaApp
//
//  Created by ToanDK on 3/3/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import "OCSDKChatSetupController.h"

@interface OCSDKChatSetupController (Send_Recieve)


-(void)sendReadAction:(AMMessage*)message;
-(void)sendAction:(NSString *)actionName;
-(void)retryMessage:(AMMessage*)message;

-(void)sendASticky:(NSDictionary *)sticky;
-(void)sendChatText:(NSString *)text withColor:(UIColor*)color;
-(void)sendChatImageWithFilePath:(NSString*)filePath;
-(void)sendChatVoiceWithFilePath:(NSString*)filePath withLength:(float)length;

-(void)addStickyInfoForMessage:(AMMessage*)message;
- (void) recieveMessage:(AMMessage *)message;
-(void)processControlAction:(AMMessage *)message;


@end
