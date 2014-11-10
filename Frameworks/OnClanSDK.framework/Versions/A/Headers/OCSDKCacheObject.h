//
//  OCSDKCacheObject.h
//  OnClanSDK
//
//  Created by TienLe on 10/22/14.
//
//

#import <Foundation/Foundation.h>

@interface OCSDKCacheObject : NSObject

@property (strong, nonatomic) NSData *param;
@property (strong, nonatomic) NSData *data;
@property (strong, nonatomic) NSDate * date_modified;
@property (strong, nonatomic) NSString * url;
@property (strong, nonatomic) NSString * method;

@end
