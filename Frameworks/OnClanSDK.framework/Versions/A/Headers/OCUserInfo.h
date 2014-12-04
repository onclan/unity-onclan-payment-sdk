//
//  OCUserInfo.h
//  OnClanSDK
//
//  Created by ToanDK on 11/26/14.
//
//

#import <Foundation/Foundation.h>

@interface OCUserInfo : NSObject

@property (nonatomic, readonly) BOOL isLoggedIn;
@property (nonatomic, readonly) NSString *userId;
@property (nonatomic, readonly) NSString *aliasId;
@property (nonatomic, readonly) NSString *fullname;
@property (nonatomic, readonly) NSString *avatar;
@property (nonatomic, readonly) NSString *cover;
@property (nonatomic, readonly) NSString *level;

-(NSDictionary*)toDictionary;

@end
