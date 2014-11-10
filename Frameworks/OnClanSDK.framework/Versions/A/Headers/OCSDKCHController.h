//
//  OCSDKCHController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/8/14.
//
//

#import <Foundation/Foundation.h>
#import "OCSDKConst.h"

@class OCSDKCHCoordinator;
@class OCSDKCHView;
@class OCSDKAwesomeMenu;


@interface OCSDKCHController : NSObject {
    
}
@property (nonatomic, strong) OCSDKAwesomeMenu *circleMenu;
@property (nonatomic, strong) OCSDKCHCoordinator *draggingCoordinator;
@property (nonatomic, strong) OCSDKCHView  *draggableView;

+(OCSDKCHController *) sharedInstance;

+ (void) showHeadChatButton;
+ (void) showRecordHeadChatButton;
+ (void) hideRecordHeadChatButton;
@end
