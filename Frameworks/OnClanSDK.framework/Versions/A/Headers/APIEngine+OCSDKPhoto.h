//
//  APIEngine+OCSDKPhoto.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/6/14.
//
//


#import "OCSDKAPIEngine.h"
@interface OCSDKAPIEngine (OCSDKPhoto)
- (void) postPhotoToUserWallWithPath:(NSString*) filePath
                 withCompletionBlock:(OCSDKObjectBlock) completionBlock
                      withErrorBlock:(OCSDKErrorBlock) errorBlock;
-(void)createNewPostToUser:(NSString *)uid
            withParameters:(NSDictionary *)dict
                onComplete:(OCSDKObjectBlock) completionBlock
                   onError:(OCSDKErrorBlock) errorBlock;
@end
