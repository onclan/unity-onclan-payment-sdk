//
//  OCSDKAPIController+GA.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

@interface OCSDKAPIController (GA)
- (void) sendScreenWithScreenName:(NSString*) screenName;
- (void) sendEventWithCategory:(NSString*) cate
                    withAction:(NSString*) action
                     withLabel:(NSString*) label;
@end
