//
//  IAPHelper.h
//  In App Rage
//
//  Created by Ray Wenderlich on 9/5/12.
//  Copyright (c) 2012 Razeware LLC. All rights reserved.
//

#import <StoreKit/StoreKit.h>
#import "OCSDKConst.h"

UIKIT_EXTERN NSString *const OCSDKIAPHelperProductPurchasedNotification;

typedef void (^RequestProductsCompletionHandler)(BOOL success, NSArray * products, NSError *error);

@interface OCSDKIAPHelper : NSObject
+ (id) sharedInstance;
- (id)initWithProductIdentifiers:(NSSet *)productIdentifiers;
- (void)requestProductsWithCompletionHandler:(RequestProductsCompletionHandler)completionHandler;
- (void)buyProduct:(SKProduct *)product;
- (BOOL)productPurchased:(NSString *)productIdentifier;
- (void)restoreCompletedTransactions;
- (void) setProductIdentifiers:(NSSet*) productIdentifiers;
- (void) buyInAppWithProductID:(NSString*) productID
                   withHandler:(OCSDKObjectHandler) handler;
//- (void) buyInAppWithProductID:(NSString*) productID
//                     withState:(NSString*) state_
//                    withTarget:(NSString*) target_
//                 withNoticeUrl:(NSString*) noticeURL_
//                   withHandler:(AppotaPaymentHandler) handler;
@end