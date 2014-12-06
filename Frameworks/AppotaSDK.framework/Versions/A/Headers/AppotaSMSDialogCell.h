//
//  AppotaSMSDialogCell.h
//  AppotaSDK
//
//  Created by tuent on 10/16/13.
//
//

#import <UIKit/UIKit.h>
#import "AppotaOHAttributedLabel.h"

@class AppotaPayment;
@interface AppotaSMSDialogCell : UIButton {
    NSDictionary *smsDict;
    NSString *inAppID;
    AppotaPayment *paymentItem;
}

+ (id) getDialogCell;
@property (unsafe_unretained, nonatomic) IBOutlet UILabel *sendLabel;

@property (unsafe_unretained, nonatomic) IBOutlet UILabel *smsNumberLabel;
@property (unsafe_unretained, nonatomic) IBOutlet AppotaOHAttributedLabel *smsMoneyLabel;
@property (unsafe_unretained, nonatomic) IBOutlet AppotaOHAttributedLabel *smsCoinLabel;
@property (unsafe_unretained, nonatomic) IBOutlet UIImageView *coinImageView;
@property (unsafe_unretained, nonatomic) IBOutlet UIImageView *backGroundImageView;
@property (unsafe_unretained, nonatomic) IBOutlet UIImageView *coinBackGroundImageView;


- (void) setUpCellWithSMSDict:(NSDictionary*) smsDict_
                  withInAppID:(NSString*) inAppID_;

- (void) setUpCellWithPaymentItem:(AppotaPayment*) pItem;

- (NSDictionary *)smsDict;

- (void)setSmsDict:(NSDictionary *)newValue;

- (NSString *)inAppID;

- (void)setInAppID:(NSString *)newValue;

- (AppotaPayment *)paymentItem;

- (void)setPaymentItem:(AppotaPayment *)newValue;

@end
