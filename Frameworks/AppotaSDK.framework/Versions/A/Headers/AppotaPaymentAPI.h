//
//  AppotaAPI.h
//  AppotaSDK
//
//  Created by Appota's Mac on 1/7/13.
//  Copyright (c) 2013 Appota's Mac. All rights reserved.
//

////////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>
#import "AppotaGameSDKLanguage.h"
#import "AppotaProgressView.h"
#import "AppotaAppleIAPItem.h"
#import "AppotaGameSDKConfigure.h"

// up-front decl's
@class AppotaPaymentAPI;
@class AppotaEngine;
@class AppotaAppleIAPItem;
@class AppotaPaymentLoginDialog;
/*
 * State cho AppotaEngine handler
 */
typedef enum {
    AppotaRequestSucceed        = 1,
    AppotaRequestFailed         = 0,
    AppotaRequestFacebookLoginRequired = 2
} AppotaRequestState;

/*
 * State cho AppotaApi handler
 */
typedef enum {
    AppotaApiSucceed        = 1,
    AppotaApiFailed         = 0
} AppotaApiState;

/*
 * State cho AppotaLogin handler
 */
typedef enum {
    AppotaLoginSucceed = 1,
    AppotaLoginFailed = 0,
    AppotaFacebookLoginRequired = 2
} AppotaLoginApiState;

/*
 * State cho TopUp Web
 */
typedef enum {
    AppotaTopupLogOut = 0,
    AppotaTopupCancel = 1,
    AppotaTopupDone = 2,
    AppotaTopupWaiting = 3,
    AppotaTopupFailed = 4,
} AppotaTopupErrorCode;

/*
 * Event handler cho kết quả trả về của Appota API
 */
typedef void(^AppotaPaymentHandler)(NSDictionary *apiDict, AppotaPaymentState status, NSError *error);

/*
 * Event hander for Top-up in Webview
 */
typedef void (^AppotaTopUpWebHandler)(BOOL status, NSDictionary *resultDict, AppotaTopupErrorCode error_code);

/*
 * Event handler cho AppotaEngine
 */
typedef void (^AppotaRequestHandler)(AppotaEngine *appApi, AppotaRequestState status, NSError *error);

/*
 * Event handler cho AppotaAPI
 */
typedef void (^AppotaApiHandler)(AppotaPaymentAPI *appApi, AppotaApiState status, NSError *error);

/*
 * Event handler cho kết quả trả về của Appota API
 */
typedef void(^AppotaResultHandler)(NSDictionary *apiDict, AppotaApiState status, NSError *error);


/*
 * Định nghĩa các biến token xác thực kết nối với APPOTA
 */
@interface AppotaPaymentAPI : NSObject {
    NSString *inappId;
}

@property BOOL isSandBoxMode;
@property (nonatomic, strong) NSString *clientID;
@property (nonatomic, strong) NSString *clientSecret;
@property (nonatomic, strong) NSString *sandboxKey;
@property (nonatomic, strong) NSString *inappKey;
@property (readwrite) BOOL debugMode;

#pragma mark -
#pragma mark - Shared Appota API
/*
 * AppotaAPI singleton các API sẽ được gọi theo format [[AppotaAPI shareAPI] api];
 */
+(AppotaPaymentAPI *)shareAPI;

//-(BOOL)handleOpenURL:(NSURL *)url;

#pragma mark -
#pragma mark - SMS
/*!
 @method
 
 @abstract Open SMS app with message for a selected amount
 
 @param amount price for SMS message (required)
 @param state - string for response SMS to user (optional)
 @param target - string for targeting user make SMS payment (optional)
 @param noticeURL - url for noticing SMS payment (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
- (void) makeSMSPaymentWithAmount:(int) amount
                        withState:(NSString*) state
                       withTarget:(NSString*) target
                    withNoticeUrl:(NSString*) noticeUrl
            withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @method
 @param listAmount - list price for SMS message (NSArray of NSNumber) (required)
 @param state - string for response SMS to user (optional)
 @param target - string for targeting user make SMS payment (optional)
 @param noticeURL - url for noticing SMS payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler) 
 */
- (void) makeSMSPaymentWithListAmount:(NSArray*) listAmount
                        withState:(NSString*) state
                       withTarget:(NSString*) target
                    withNoticeUrl:(NSString*) noticeUrl
                  withDescription:(NSString*) description
            withCompletionHandler:(AppotaPaymentHandler) handler;

- (void) makeSMSPaymentWithListAmount:(NSArray*) listAmount
                            withState:(NSString*) state
                           withTarget:(NSString*) target
                        withNoticeUrl:(NSString*) noticeUrl
                      withDescription:(NSString*) description
                    withPaymentDialog:(AppotaPaymentLoginDialog*) pDialog
                withCompletionHandler:(AppotaPaymentHandler) handler;

- (void) makeSMSPaymentWithListPayment:(NSArray*) listPayment
                             withState:(NSString*) state
                            withTarget:(NSString*) target
                         withNoticeUrl:(NSString*) noticeUrl
                       withDescription:(NSString*) description
                     withPaymentDialog:(AppotaPaymentLoginDialog*) pDialog
                           withSMSDict:(NSDictionary*) smsDict
                 withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @method
 
 @abstract Open a view with list of payment price to choose, list get from server
 
 @param state - string for response SMS to user (optional)
 @param target - string for targeting user make SMS payment (optional)
 @param noticeURL - url for noticing SMS payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
- (void) makeSMSPaymentWithState:(NSString*) state
                      withTarget:(NSString*) target
                   withNoticeUrl:(NSString*) noticeUrl
                 withDescription:(NSString*) description
           withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @abstract API lấy cấu trúc tin nhắn nạp tiền inApp và iapp_id (iapp_id cần được lưu lại để kiểm tra status giao dịch của user sau khi nạp tiền - gọi API checkTransactionInAppWithID)
 @param noticeURL: Đường dẫn nhận thông báo khi người dùng thực hiện giao dịch
 @param stateString    : Nội dung tuỳ chọn, trong trường hợp ứng dụng không có notice_url, trường này sẽ được sử dụng làm tin nhắn trả về cho người dùng sau khi nhắn tin thanh toán. Giới hạn độ dài nhỏ hơn 100 kí tự
 @param targetString   : Nội dung tuỳ chọn, được gửi về cùng với thông báo. Giới hạn độ dài nhỏ hơn 100 kí tự
 @param isShortType    : chọn mẫu tin nhắn dạng ngắn
 @param handler
 *  Event handler trả về state AppotaApiSucceed kèm theo NSDictionary có chứa thông tin cấu trúc các tin nhắn nạp tiền và iapp_id nếu kết nối thành công
 *  Event handler trả về state AppotaApiFailed kèm theo mã lỗi nếu kết nối thất bại
 */
-(void) getSMSInAppWithNoticeUrl:(NSString*) noticeURL
                       withState:(NSString*) stateString
                      withTarget:(NSString*) targetString
                     withSMSType:(BOOL) isShortType
           withCompletionHandler:(AppotaPaymentHandler) handler;

#pragma mark -
#pragma mark - Paypal

/*!
 @method
 @param amount price for Paypal message (required)
 @param state - string for response Paypal to user (optional)
 @param target - string for targeting user make Paypal payment (optional)
 @param noticeURL - url for noticing Paypal payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler) 
 */
- (void) makePaypalPaymentWithAmount:(float) amount
                           withState:(NSString*) state
                          withTarget:(NSString*) target
                       withNoticeUrl:(NSString*) noticeUrl
               withCompletionHandler:(AppotaPaymentHandler) handler;

- (void) makePaypalPaymentWithAmount:(float) amount
                           withState:(NSString*) state
                          withTarget:(NSString*) target
                       withNoticeUrl:(NSString*) noticeUrl
                   withPaymentDialog:(AppotaPaymentLoginDialog*) pDialog
               withCompletionHandler:(AppotaPaymentHandler) handler;
/*!
 @method
 @param listAmount - list price for Paypal message, NSArray of NSNumber (required)
 @param state - string for response Paypal to user (optional)
 @param target - string for targeting user make Paypal payment (optional)
 @param noticeURL - url for noticing Paypal payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
//- (void) makePaypalPaymentWithListAmount:(NSArray*) listAmount
//                           withState:(NSString*) state
//                          withTarget:(NSString*) target
//                       withNoticeUrl:(NSString*) noticeUrl
//                     withDescription:(NSString*) description
//               withCompletionHandler:(AppotaPaymentHandler) handler;

- (void) makePaypalPaymentWithListItem:(NSArray*) listPaymentItem
                             withState:(NSString*) state
                            withTarget:(NSString*) target
                         withNoticeUrl:(NSString*) noticeUrl
                       withDescription:(NSString*) description
                     withPaymentDialog:(AppotaPaymentLoginDialog*) pDialog
                 withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @method
 
 @abstract Open a view with list of payment price to choose, list get from server
 
 @param state - string for response Paypal to user (optional)
 @param target - string for targeting user make Paypal payment (optional)
 @param noticeURL - url for noticing Paypal payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
- (void) makePaypalPaymentWithState:(NSString*) state
                         withTarget:(NSString*) target
                      withNoticeUrl:(NSString*) noticeUrl
                    withDescription:(NSString*) description
              withCompletionHandler:(AppotaPaymentHandler) handler;
#pragma mark -
#pragma mark - Card

/*!
 @method
 @param cardCode - code of the phone card (required)
 @param cardSerial - serial of the phone card (required)
 @param state - string for response Card to user (optional)
 @param target - string for targeting user make Card payment (optional)
 @param noticeURL - url for noticing Card payment
 @param description - string will show in detail
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler) 
 */
-(void) makeCardPaymentWithCardCode:(NSString *)cardCode
                     withCardSerial:(NSString *)cardSerial
                     withCardVendor:(NSString *)cardVendor
                          withState:(NSString*) state
                         withTarget:(NSString*) target
                      withNoticeUrl:(NSString*) noticeUrl
              withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @method
 
 @abstract Open a view with list of payment price to choose, list get from server
 
 @param state - string for response Card to user (optional)
 @param target - string for targeting user make Card payment (optional)
 @param noticeURL - url for noticing Card payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
-(void) makeCardPaymentWithState:(NSString*) state
                      withTarget:(NSString*) target
                   withNoticeUrl:(NSString*) noticeUrl
                 withDescription:(NSString*) description
           withCompletionHandler:(AppotaPaymentHandler) handler;

-(void) makeCardPaymentWithState:(NSString*) state
                      withTarget:(NSString*) target
                   withNoticeUrl:(NSString*) noticeUrl
                 withDescription:(NSString*) description
               withPaymentDialog:(AppotaPaymentLoginDialog*) pDialog
           withCompletionHandler:(AppotaPaymentHandler) handler;
#pragma mark - 
#pragma mark - Bank

- (void) makeBankPaymentWithListPayment:(NSArray*) listPayment
                              withState:(NSString*) state
                             withTarget:(NSString*) target
                          withNoticeUrl:(NSString*) noticeUrl
                        withDescription:(NSString*) description
                      withPaymentDialog:(AppotaPaymentLoginDialog*) pDialog
                  withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @method
 @param amount price for Bank message (required)
 @param state - string for response Bank to user (optional)
 @param target - string for targeting user make Bank payment (optional)
 @param noticeURL - url for noticing Bank payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
- (void) makeBankPaymentWithAmount:(int) amount
                         withState:(NSString*) state
                        withTarget:(NSString*) target
                     withNoticeUrl:(NSString*) noticeUrl
                    withDesciption:(NSString *)description
             withCompletionHandler:(AppotaPaymentHandler) handler;
/*!
 @method
 @param listAmount - list price for Bank message, NSArray of NSNumber (required)
 @param state - string for response Bank to user (optional)
 @param target - string for targeting user make Bank payment (optional)
 @param noticeURL - url for noticing Bank payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
- (void) makeBankPaymentWithListAmount:(NSArray*) listAmount
                         withState:(NSString*) state
                        withTarget:(NSString*) target
                     withNoticeUrl:(NSString*) noticeUrl
                   withDescription:(NSString*) description
             withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @method
 
 @abstract Open a view with list of payment price to choose, list get from server
 
 @param state - string for response Bank to user (optional)
 @param target - string for targeting user make Bank payment (optional)
 @param noticeURL - url for noticing Bank payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
- (void) makeBankPaymentWithState:(NSString*) state
                       withTarget:(NSString*) target
                    withNoticeUrl:(NSString*) noticeUrl
                  withDescription:(NSString*) description
            withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @method
 
 @abstract Call payment for apple iap - result by callback handler
 
 @param item - Item to purchase
 @param state - string for response Bank to user (optional)
 @param target - string for targeting user make Bank payment (optional)
 @param noticeURL - url for noticing Bank payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
- (void) makeApplePaymentWithItem:(AppotaAppleIAPItem*) item
                        withState:(NSString*) state
                        withTarget:(NSString*) target
                     withNoticeUrl:(NSString*) noticeUrl
                   withDescription:(NSString*) description
             withCompletionHandler:(AppotaPaymentHandler) handler;

/*!
 @method
 
 @abstract Call payment for apple iap - result by callback handler
 
 @param item - Item to purchase
 @param state - string for response Bank to user (optional)
 @param target - string for targeting user make Bank payment (optional)
 @param noticeURL - url for noticing Bank payment (optional)
 @param description - string will show in detail (optional)
 @param handler - Completion block for handling return state of payment action (result detail please read AppotaPaymentHandler)
 */
- (void) makeApplePaymentWithListItem:(NSArray*) lisItem
                        withState:(NSString*) state
                       withTarget:(NSString*) target
                    withNoticeUrl:(NSString*) noticeUrl
                  withDescription:(NSString*) description
            withCompletionHandler:(AppotaPaymentHandler) handler;

- (void) makeApplePaymentWithListItem:(NSArray*) lisItem
                            withState:(NSString*) state
                           withTarget:(NSString*) target
                        withNoticeUrl:(NSString*) noticeUrl
                      withDescription:(NSString*) description
                    withPaymentDialog:(AppotaPaymentLoginDialog*) pDialog
                withCompletionHandler:(AppotaPaymentHandler) handler;


-(void) checkTransactionInAppWithID:(NSString *)inApp_id
              withCompletionHandler:(AppotaResultHandler) handler;

- (void) checkUpdateFunction;

#pragma mark Game payment function
- (BOOL) validateCardCodeAndSerial:(NSString*) cardCode;

- (void) handleCardPaymentResultWithDict:(NSDictionary*) resultDict
                             withHandler:(AppotaPaymentHandler) handler;
@end
