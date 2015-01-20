//
//  AppotaWrapper.h
//  AppotaGameUnitySDK
//
//  Created by tutv on 03/09/14
//
//

#import "AppotaWrapper.h"
#import "AppotaSDK/AppotaSDK.h"
#define NOUI_LOGIN YES
#define CLIENT_ID           @"e8a1ffd03bfe5d401d875df633cd43eb051f0a4fc"
#define CLIENT_SECRET       @"060f9c20e5259e2462f1cc00c15c6f93051f0a4fc"
#define INAPP_API_KEY       @"1e1aa54ce3c646d8f6456558434d9475051f74156"

/*
 * SANDBOX_ID will be used when app's not been published yet
 */
#define SANDBOX_CLIENT_ID @"SANDBOX_CLIENT_ID"
#define SANDBOX_CLIENT_SECRET @"SANDBOX_CLIENT_SECRET"
#define SANDBOX_INAPP_API_KEY @"SANDBOX_INAPP_API_KEY"

@implementation AppotaWrapper

static AppotaWrapper* sharedMyInstance = nil;

+ (id) sharedInstance {
    @synchronized(self) {
        if( sharedMyInstance == nil )
            sharedMyInstance = [[super allocWithZone:NULL] init];
    }
    return sharedMyInstance;
} // end sharedInstance()


extern "C" {
    
    const void configSDK(const char *clientId, const char *clientSecret, const char *inAppApiKey, const char *gameState, const char *noticeURL, const char *configURL) {
    
    	[AppotaGameSDKConfigure configureWithClientID:[NSString stringWithUTF8String:clientId]
                                 withClientSecret:[NSString stringWithUTF8String:clientSecret]
                                  withInAppAPIKey:[NSString stringWithUTF8String:inAppApiKey]
                                        withState:[NSString stringWithUTF8String:gameState]
                                    withNoticeUrl:[NSString stringWithUTF8String:noticeURL]
                                    withConfigUrl:[NSString stringWithUTF8String:configURL]
     	];
	}
    
    const void setGoogleClientId(const char *id){
        [AppotaGameSDKConfigure sharedGameConfig].googleClientId = [NSString stringWithUTF8String:id];
        // id: @"381575391023-q1kemg9m0m4pacje3dq12dufr890hvdg.apps.googleusercontent.com";
    }
    
    const void setOnlyOpenProfile(bool isOnlyOpenProfile){
        [AppotaGameSDKConfigure sharedGameConfig].isOnlyOpenProfile = isOnlyOpenProfile;

    }
    
    const void setShowCloseLoginView(bool isShowCloseLoginView){
        [AppotaGameSDKConfigure sharedGameConfig].isShowCloseLoginView = isShowCloseLoginView;
    }
    
    #warning Set up auto show payment button and login dialog here, by default autoShowPaymentButton and autoShowLoginDialog are YES
    const void setAutoShowPaymentButton(bool autoShowPaymentButton){
        [AppotaGameSDKConfigure sharedGameConfig].autoShowPaymentButton = autoShowPaymentButton;
    }
    
    const void setDelegate(){
        [AppotaGameSDKConfigure sharedGameConfig].delegate = [AppotaWrapper sharedInstance];
    }
    
    const void setJsonConfigUrl(const char *url){
        [[AppotaGameSDKConfigure sharedGameConfig] setJsonConfigUrl:[NSString stringWithUTF8String:url]];
    }
    
	const void showSDKView(){
        [AppotaGameSDKConfigure showSDKView];
    }
    
    const void logoutSDK(){
    	if ([AppotaGameSDKConfigure checkUserLogin]) {
        	[AppotaGameSDKConfigure logOut];
    	}
    	else {
        	[AppotaGameSDKConfigure showLoginView];
    	}
    }

	const void showSwitchUserView(){
		[AppotaGameSDKConfigure showSwitchUserView];
	}

	const void showPaymentView(){
		[AppotaGameSDKConfigure showPaymentView];
	}

	const void showPaymentButton(){
		[AppotaGameSDKConfigure showPaymentButton];
	}
	
	const void hidePaymentButton(){
		[AppotaGameSDKConfigure hidePaymentButton];
	}

	const void showUserInfoView(){
	}

	const void showLoginView(){
		[AppotaGameSDKConfigure showLoginView];
	}

	const void setAutoShowLogin(bool autoShowLogin){
		[AppotaGameSDKConfigure sharedGameConfig].autoShowLoginDialog = autoShowLogin;
	}

	const void setPaymentState(const char *paymentState){
         [[AppotaGameSDKConfigure sharedGameConfig] setPaymentState:[NSString stringWithUTF8String:paymentState]];
	}
	
	const bool isUserLogin(){
		return [AppotaGameSDKConfigure checkUserLogin];
	}
	
	char* cStringCopy(const char* string)
    {
        if (string == NULL)
            return NULL;
        
        char* res = (char*)malloc(strlen(string) + 1);
        strcpy(res, string);
        
        return res;
    }
	
	const char* getUserID() {
		if (![AppotaGameSDKConfigure getUserID]) {
			NSString *emptyString = @"";
        	return cStringCopy([emptyString UTF8String]);
		}
		else {
			NSString *userString = [AppotaGameSDKConfigure getUserID];
        	return cStringCopy([userString UTF8String]);
		}
    }
}

#pragma mark - Gameconfig delegate
/*
 * Implement your verification here
 */
- (void) didFinishLogin:(NSDictionary *)userInfoDict {
#warning Insert your verify action here
    NSLog(@"Login Success!!!");
    //UnitySendMessage("AppotaSDKReceiver", "OnLoginSuccess", "Login Success!!!");
}

- (void) didLogOut:(NSString *)userName {
    // Update viewcontroller logout state
    NSLog(@"Logout %@", userName);
    NSString *temp = @"Logout %@";
    temp = [temp stringByAppendingString:userName];
   
    //UnitySendMessage("AppotaSDKReceiver", "OnLogoutSuccess", [temp UTF8String]);
    
}

- (void) didFinishPaymentWithDictionary:(NSDictionary *)paymentDict withState:(AppotaPaymentState)status withError:(NSError *)error {
    NSLog(@"Payment result");
    //[[AppotaGameSDKConfigure sharedGameConfig] setPaymentState:@"TestPaymentState"];
    //UnitySendMessage("AppotaSDKReceiver", "OnPaymentSuccess", "Payment Success!!!");
}
- (void) didCloseLoginView {
    NSLog(@"Close login view");
    //UnitySendMessage("AppotaSDKReceiver", "OnLoginSuccess", "Did Close LoginView!!!");
}

- (void) didFinishSwitchUser:(NSDictionary*) userInfoDict{
    //UnitySendMessage("AppotaSDKReceiver", "OnSwitchAccountSuccess", "Switch Success!!!");
}


@end
