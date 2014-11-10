//
//  OCSDKLoginObject.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/10/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKBaseObject.h"

@interface OCSDKLoginObject : OCSDKBaseObject
- (NSString*) getAccessToken;
- (NSString*) getUserName;
@end
