//
//  ImagePickerCrop.h
//  NewAppotaApp
//
//  Created by Appota on 5/27/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppotaImagePickerController.h"
//#import "MyPhotoPicker.h"
#import "PECropViewController.h"
//#import "LanguagePicker.h"

typedef void (^ImagePickerCropBlock)(id object, NSError* error, BOOL fromMyPhoto);

@interface ImagePickerCrop : NSObject <UINavigationControllerDelegate, UIImagePickerControllerDelegate> {
    UIViewController *myVC;
    ImagePickerCropBlock completionBlock;
    BOOL singleSelection;
    BOOL showMyPhotoPicker;
    NSString *photoType;
}

+(void)showInViewController:(UIViewController*)viewController
          withMyPhotoPicker:(BOOL)showMyPhotoPicker
              withPhotoType:(NSString*)photoType
        withCompletionBlock:(ImagePickerCropBlock)block;
@end
