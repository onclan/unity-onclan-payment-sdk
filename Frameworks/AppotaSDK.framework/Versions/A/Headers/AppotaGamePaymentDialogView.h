//
//  AppotaGamePaymentDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/31/13.
//
//

#import "AppotaGameView.h"

@interface AppotaGamePaymentDialogView : AppotaGameView <UITableViewDataSource, UITableViewDelegate> {
    __unsafe_unretained IBOutlet UIButton *profileViewButton;
    __unsafe_unretained IBOutlet UILabel *titleLabel;
    __unsafe_unretained IBOutlet UIImageView *tabBarIconImageView;    
    __unsafe_unretained IBOutlet UILabel *userNameLabel;
}
- (IBAction)goProfileAction:(id)sender;
@property (unsafe_unretained, nonatomic) IBOutlet UITableView *paymentMethodTableView;

@end
