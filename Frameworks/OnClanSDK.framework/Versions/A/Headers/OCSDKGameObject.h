//
//  OCSDKGameObject.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/13/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseObject.h"

@interface OCSDKGameObject : OCSDKBaseObject
- (NSString*) getGameIcon;
- (NSString*) getGameName;
- (int) getGameTotalClan;
- (int) getGameTotalPlayer;
- (NSString*) getDevID;
@end
