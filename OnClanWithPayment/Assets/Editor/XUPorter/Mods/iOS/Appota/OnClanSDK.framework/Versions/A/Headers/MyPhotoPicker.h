//
//  MyPhotoPicker.h
//  NewAppotaApp
//
//  Created by ToanDK on 8/6/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import "OCSDKBaseViewController.h"
#import "MyPhotosVC.h"

@protocol MyPhotoPickerDelegate <NSObject>

@optional
    -(void)myPhotoPickerDidSelectPhoto:(NSDictionary *)dictionary;
    -(void)myPhotoPickerDidCancel;

@end

@interface MyPhotoPicker : MyPhotosVC {
    
}
@property (nonatomic, assign) id<MyPhotoPickerDelegate> delegate;

@end
