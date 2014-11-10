//
//  OCSDKRecordPhotoSingleView.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/24/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseView.h"
typedef enum {
    OCSDKViewContentStatusHide,
    OCSDKViewContentStatusShow
}OCSDKViewContentStatus;

@class OCSDKPhotoObject;

@protocol OCSDKRecordPhotoSingleDeletePhoto <NSObject>
- (void)deletePhotoCell:(id)photoDict;
@end
@interface OCSDKRecordPhotoSingleView : OCSDKBaseView<UIAlertViewDelegate> {
    
    IBOutlet UIImageView *contentImageView;
    IBOutlet UIButton *uploadButton;
    IBOutlet UIButton *deleteButton;
    IBOutlet UIButton *editButton;
    IBOutlet UIView *viewContentUploadPhoto;
}
@property (assign, nonatomic) OCSDKViewContentStatus status;
@property (assign, nonatomic) id<OCSDKRecordPhotoSingleDeletePhoto> delegate;
- (IBAction)uploadButtonAction:(id)sender;
- (IBAction)pressEditPhoto:(id)sender;
- (IBAction)deletePhoto:(id)sender;

//- (void) loadViewWithPhotoDict:(NSDictionary*) photoDict;
- (void) loadViewWithPhotoObject:(OCSDKPhotoObject*) photoObject;
@end
