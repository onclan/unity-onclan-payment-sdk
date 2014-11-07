//
//  OCSDKPhotoObject.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/26/14.
//
//

#import "OCSDKBaseObject.h"

typedef enum {
    OCSDKPhotoLocalType,
    OCSDKPhotoServerType
} OCSDKPhotoType;

typedef enum {
    OCSDKPhotoNormalState,
    OCSDKPhotoEditingState,
    OCSDKPhotoDeletedState
} OCSDKPhotoState;

@interface OCSDKPhotoObject : OCSDKBaseObject
@property (readwrite) OCSDKPhotoType photoType;
@property (nonatomic, strong) NSString *photoURL;
@property (readwrite) OCSDKPhotoState photoState;
@end
