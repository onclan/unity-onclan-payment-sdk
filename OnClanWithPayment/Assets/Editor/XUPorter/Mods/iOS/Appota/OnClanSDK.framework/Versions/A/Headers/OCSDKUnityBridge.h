//
//  OCSDKUnityBridge.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/28/14.
//
//

#import <Foundation/Foundation.h>

@interface OCSDKUnityBridge : NSObject

@end

extern "C" {
    void _OCSDKPostScore(int score);
    
    void _OCSDKPostScoreToCategory(int score, const char *categoryID);

    void _OCSDKShowLeaderBoard();
    
    void _OCSDKConfigure(char *apiKey);
    
    void _OCSDKMakePayment();
    
    void _OCSDKSetDisableAutoLogin(BOOL disableAutoLogin);
}
