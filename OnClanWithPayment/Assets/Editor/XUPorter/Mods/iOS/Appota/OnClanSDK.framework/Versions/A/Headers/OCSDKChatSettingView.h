//
//  ChatSettingView.h
//  AppotaApp
//
//  Created by ToanDK's Mac on 2/4/13.
//
//

#import <UIKit/UIKit.h>
#import "MyPhotoPicker.h"
#import "PECropViewController.h"
#import "OCSDKChatSettingUserTableView.h"
#import "OCSDKBaseMenuViewController.h"

@class OCSDKChatViewController;

@interface OCSDKChatSettingView : OCSDKBaseMenuViewController<UITextFieldDelegate, UIActionSheetDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, MyPhotoPickerDelegate, UIScrollViewDelegate> {
    
    IBOutlet OCSDKChatSettingUserTableView *tablePeople;
    
    OCSDKNavigationCustom *customView;
    NSMutableDictionary *chatSettings;
    NSMutableArray *listPeople;
    NSString *photoId;
}
@property (nonatomic, assign) OCSDKChatViewController *parentVC;

- (id)initWithSetting:(NSMutableDictionary *)settings withPeople:(NSMutableArray *)people;

@end
