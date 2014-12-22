//
//  OCSDKWebDialog.h
//  AppotaSDK
//
//  Created by Tue Nguyen on 12/3/14.
//
//

#import "OCSDKBaseDialog.h"
#import "OCSDKConst.h"

@interface OCSDKWebDialog : OCSDKBaseDialog
- (id) initWithURL:(NSString*) url;
- (void) showWebViewWithHandler:(OCSDKObjectHandler) handler;

-(void)setSpinnerHidden:(BOOL)hidden;

@end
