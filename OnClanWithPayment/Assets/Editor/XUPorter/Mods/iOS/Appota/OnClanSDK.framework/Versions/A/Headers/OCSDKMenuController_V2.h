//
//  OCSDKMenuController_V2.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/8/14.
//
//

#import <Foundation/Foundation.h>
#import "OCSDKCHController.h"
#import "OCSDKConst.h"

#define OCSDK_MENU_TAG 1102
#define OCSDK_POPUP_DIALOG_TAG 1202
/**
 *  This function will be incharge of
 */
@class OCSDKMenuViewDialog;
@class OCSDKNavigationController;
@interface OCSDKMenuController_V2 : NSObject
{
    
}
@property (nonatomic, strong) UINavigationController *navigationController;
+ (OCSDKMenuController_V2*) sharedInstance;
- (OCSDKMenuViewDialog*) getMenuDialog;
- (void) presentMenuWithType:(OCSDKMenuType) menuType;
- (void) closeMenu;
- (void) pullMenu;
- (void) pushMenu;
@end
