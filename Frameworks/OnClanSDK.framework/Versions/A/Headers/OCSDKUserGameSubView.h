//
//  OCSDKUserGameSubView.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/11/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseView.h"

@class OCSDKGameObject;
@interface OCSDKUserGameSubView : OCSDKBaseView
{
    NSString *gameId;
    IBOutlet UIImageView *gameAvatarImageView;
    IBOutlet UILabel *gameNameLabel;
    IBOutlet UILabel *gameDescriptionLabel;
}

- (void) loadViewWithGameObject:(OCSDKGameObject*) gameObject;

- (IBAction)pressLinkToGame:(id)sender;
@end
