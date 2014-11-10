//
//  MosquittoOperation.h
//  NewAppotaApp
//
//  Created by ToanDK on 10/11/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AMMessage.h"

typedef void (^AMMessageResponseBlock)(AMMessage* message, BOOL success);

@interface MosquittoOperation : NSObject {
    NSTimer *timer;
}
//@property (nonatomic, strong) NSString *message;
@property (nonatomic, strong) NSString *publishTopic;
@property (nonatomic, readonly) NSString *operationId;
@property (nonatomic, strong) AMMessage *message;
@property (nonatomic, strong) AMMessageResponseBlock completionBlock;

+(id)newOperationWithMessage:(AMMessage*)msg completeBlock:(AMMessageResponseBlock)completionBlock;
-(void)sendMessageSuccess;

@end
