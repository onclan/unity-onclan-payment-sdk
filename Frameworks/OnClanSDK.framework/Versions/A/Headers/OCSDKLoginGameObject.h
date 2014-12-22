//
//  OCSDKLoginGameObject.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKLoginObject.h"

@interface OCSDKLoginGameObject : OCSDKLoginObject
- (NSString*) getGameLoginAccessToken;
- (BOOL) isRequireUpdatePassword;
@end
