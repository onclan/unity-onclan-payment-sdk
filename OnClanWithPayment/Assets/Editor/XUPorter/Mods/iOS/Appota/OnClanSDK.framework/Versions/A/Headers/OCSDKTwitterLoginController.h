//
//  AppotaTwitterLoginController.h
//  AppotaSDK
//
//  Created by Tue Nguyen on 7/22/14.
//
//

#import <Foundation/Foundation.h>
#import "OCSDKConst.h"

@class ACAccountStore;
@class OCSDKTWAPIManager;

@interface OCSDKTwitterLoginController : NSObject
@property (nonatomic, strong) ACAccountStore *accountStore;
@property (nonatomic, strong) OCSDKTWAPIManager *apiManager;
@property (nonatomic, strong) NSArray *accounts;

+(OCSDKTwitterLoginController *)sharedInstance;

- (void) loginTwitterWithHandler:(OCSDKObjectHandler) handler;

@end
