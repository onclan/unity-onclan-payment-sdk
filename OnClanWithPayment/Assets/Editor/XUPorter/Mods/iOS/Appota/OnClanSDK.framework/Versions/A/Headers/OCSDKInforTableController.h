//
//  OCSDKInforTableController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 10/1/14.
//
//

#import "OCSDKBaseTableController.h"

typedef enum {
    OCSDKInforInviteFriendType,
    OCSDKInforProfileType,
    OCSDKInforGameInfoType,
    OCSDKInforSupportType,
    OCSDKInforCreateClanType,
    OCSDKInforLogoutType,
} OCSDKInforType;

@interface OCSDKInforObject : NSObject
@property (nonatomic, strong) NSString *inforDescription;
@property (readwrite) OCSDKInforType inforType;
+ (NSString*) getImageNameWithInforType:(OCSDKInforType) infoType;
@end

@interface OCSDKInforTableController : OCSDKBaseTableController

@end
