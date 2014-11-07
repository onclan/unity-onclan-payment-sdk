//
//  AppotaWrapper.h
//  AppotaGameUnitySDK
//
//  Created by tutv on 03/09/14
//
//

#import <UIKit/UIKit.h>
#import "AppotaSDK/AppotaSDK.h"

@interface AppotaWrapper : NSObject<AppotaGameSDKConfigureDelegate>{
    
}

+ (id) sharedInstance;

@end
