//
//  OCSDKAPIController+Track.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKAPIController.h"

#define TRACK_SESSION_TOTAL_KEY     @"track_time_total"
#define TRACK_SESSION_TIME_ON_APP   @"track_time_on_app"
#define TRACK_SESSION_PREV_ID       @"track_session_prev_id"

@interface OCSDKAPIController (Track)
- (void) getTrackInfoWithCompletionBlock:(OCSDKObjectBlock) completionBlock
                          withErrorBlock:(OCSDKErrorBlock) errorBlock;
@end
