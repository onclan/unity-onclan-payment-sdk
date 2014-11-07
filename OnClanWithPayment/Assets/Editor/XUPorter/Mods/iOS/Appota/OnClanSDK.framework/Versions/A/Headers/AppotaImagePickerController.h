//
//  AppotaImagePickerController.h
//  NewAppotaApp
//
//  Created by ToanDK on 9/6/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^AppotaPickerBlock)(NSArray *listImages, NSError* error);

@interface AppotaImagePickerController : UIImagePickerController<UIImagePickerControllerDelegate, UINavigationControllerDelegate> {
    AppotaPickerBlock completionBlock;
}

+ (AppotaImagePickerController *)customizedNavigationController;

-(void)setCompletionBlock:(AppotaPickerBlock)block;

@end
