//
//  OCSDKCHController+CircleDelegate.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/8/14.
//
//

#import "OCSDKCHController.h"
#import "OCSDKAwesomeMenu.h"

@interface OCSDKCHController (CircleDelegate) <OCSDKAwesomeMenuDelegate>
- (void) touchCircleMenuAndInitDatabase;
- (OCSDKAwesomeMenu*) getCircleMenuViewWithPosition:(CGPoint) position;
@end
