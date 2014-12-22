//
//  OCSDKUnityBridge.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/28/14.
//
//

#import <Foundation/Foundation.h>

@interface AppotaGameSDKUnityBridge : NSObject

@end

#ifdef __cplusplus
extern "C" {
#endif
    
    void UnitySendMessage(const char *, const char *, const char *);
    
//    void configSDK(char* apiKey, char* sandboxApiKey, char* noticeURL, char* configURL);
//
//    void logoutSDK();
//    
//    void showPaymentView();
//    
//    void showUserInfoView();
//    
//    void showSwitchUserView();
//    
//    void showLoginView();
//    
//    void setAutoShowLogin(bool autoShowLogin);
    
#ifdef __cplusplus
}
#endif
