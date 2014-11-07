//
//  SystemConfig.h
//  AppotaMessager
//
//  Created by ToanDK on 3/17/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#ifndef AppotaMessager_SystemConfig_h
#define AppotaMessager_SystemConfig_h

#import "UIView+OCSDKAnimationHelper.h"
#import "Language.h"
#import "OCSDKAPIController+GA.h"
#import "OCSDKNavigationCustom.h"
#import <QuartzCore/QuartzCore.h>

#define WIN_SIZE [UIScreen mainScreen].bounds.size

//#define LOADING_ICON                @"Icon.png"
#define LOADING_EMOTICON            @"games.png"
#define LOADING_AVATAR_PLADEHOLDER  @"avatar60.png"
#define LOADING_GAME_PLADEHOLDER    @"app60.png"

#define NUMBER_OF_MENU              4
#define DEGREES_RADIANS(angle)      ((angle) / 180.0 * M_PI)
#define MAX_FILE_SIZE_UPLOAD        2000000    // bytes

#define TABLE_CONTENT_LIMIT         10
#define CLAN_MEMBER_LIMIT           100

#define OCSDK_AUTO_PLAY_VOICE               @"ocsdk_auto_play_voice_chat"
#define REFRESH_CHAT_NOTIFICATION           @"RefreshChatNotification"
#define HIDE_CHAT_INPUT_NOTIFICATION_NAME       @"HideChatInputNotification"
#define CURRENT_CHAT_ID @"current_chat_id"

//iphone
#define KEYBOARD_PORTRAIT_HEIGHT 216
#define KEYBOARD_LANDSCAPE_HEIGHT 160
#define KEYBOARD_PORTRAIT_HEIGHT_IPAD 264
#define KEYBOARD_LANDSCAPE_HEIGHT_IPAD 352
#define SIZE_WIDTH_CHATVIEW_IPAD 390
#define SIZE_HEIGHT_CHATVIEW_IPAD 568
//#define OCSDK_KEYBOARD_LANDSCAPE_HEIGHT 
//#define OCSDK_KEYBOARD_PORTRAIT_HETGHT

//Orientation
#define IS_PORTRAIT ([UIApplication sharedApplication].statusBarOrientation == UIDeviceOrientationPortrait || [UIApplication sharedApplication].statusBarOrientation == UIDeviceOrientationPortraitUpsideDown)
#define IS_LANDSCAPE ([UIApplication sharedApplication].statusBarOrientation == UIDeviceOrientationLandscapeRight || [UIApplication sharedApplication].statusBarOrientation == UIDeviceOrientationLandscapeLeft)
#define LANDSCAPE_RIGHT ([UIApplication sharedApplication].statusBarOrientation == UIDeviceOrientationLandscapeRight)
#define LANDSCAPE_LEFT ([UIApplication sharedApplication].statusBarOrientation == UIDeviceOrientationLandscapeLeft)
//Device version
#define IOS_OLDER_THAN_6 ([[[UIDevice currentDevice] systemVersion] floatValue] < 6.0)
#define IS_IOS_OLDER_THAN_IOS7 ([[[UIDevice currentDevice] systemVersion] floatValue] < 7.0)
#define IS_IOS6_AND_UP ([[UIDevice currentDevice].systemVersion floatValue] >= 6.0)
#define IS_IOS7_AND_UP ([[UIDevice currentDevice].systemVersion floatValue] >= 7.0)
#define IS_BETWEEN_IOS6_AND_IOS7 ([[UIDevice currentDevice].systemVersion floatValue] >= 6.0 && [[UIDevice currentDevice].systemVersion floatValue] < 7.0)

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

//Device
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPHONE_4 (IS_IPHONE && MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height) == 480.0f)
#define IS_IPHONE_5 (IS_IPHONE && MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height) == 568.0f)
#define IS_IPHONE_6 (IS_IPHONE && MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height) == 667.f)
#define IS_IPHONE_6PLUS (IS_IPHONE && MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height) == 736.f)

//AM Menu
#define kAMMenuViewSpaceBetweenIcon 10.f
#define kAMMenuViewStatusViewAnimationInterval 0.1f
#define KAMMemuViewItemSize 40
#define kAMMenuViewNumberOfIcon 4
#define kAMMenuViewAnimationTime 0.4
#define kAMMenuViewAnimationInterval (kAMMenuViewAnimationTime / 4)

//Frame for ipad
#define kOCSDKFrameTableIpadWidth 512.f
#define kOCSDKFrameTableIpadHeigth 455.f
#define kOCSDKFrameNavigationWidth 512.f
#define kOCSDKFrameNavigationHeightPortrait 44.f
#define KOCSDKFrameNavigationHeightLandScape 32.f

//Menu View
#define OCSDK_SIZE_OF_MAIN_MENU 50
#define OCSDK_SIZE_OF_CIRCLE_MENU 30
#define OCSDK_DISTANCE_FROM_MAINMENU_TO_CIRCLEMENU 60
#define OCSDK_DISTANCE_MIN (70*cosf(DEGREES_RADIANS(30))-15)
#endif
