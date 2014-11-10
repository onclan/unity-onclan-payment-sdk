//
//  OCSDKRecordController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/14/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    OCSDKNoRecordState,
    OCSDKPreparePhotoState,
    OCSDKPrepareVideoSate,
    OCSDKCapturingPhotoState,
    OCSDKRecordingVideoState,
} OCSDKRecordState;

@class OCSDKCHView;
@class OCSDKPhotoObject;
@interface OCSDKRecordController : NSObject
@property (readwrite) OCSDKRecordState recordState;
@property (strong) NSMutableArray *listLocalImage;
@property (nonatomic, strong) OCSDKCHView *dragRecordView;
@property (readwrite) int captureCount;
+ (id)sharedInstance;
+ (void) preparePhotoCapture;
+ (void) prepareVideoRecord;
+ (UIImage*) snapOpenGLScreenView;
+ (UIImage*) snapScreenView;
+ (void) capturePhoto:(void(^)())completionBlock;
+ (void) stopPhotoCapture;
+ (NSString*) getLocalStorageKey;
- (void) deletePhotoObject:(OCSDKPhotoObject*) photoObject;
@end
