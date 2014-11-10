//
//  BNSImagePicker.h
//  Mua&Ban
//
//  Created by ToanDK on 5/20/14.
//  Copyright (c) 2014 apolo2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppotaImagePickerController.h"
#import "MyPhotoPicker.h"
#import "ELCAssetSelectionDelegate.h"
#import <AssetsLibrary/AssetsLibrary.h>
//@class BNSImagePicker;
//@protocol ELCImagePickerControllerDelegate <UINavigationControllerDelegate>
//- (void)elcImagePickerController:(BNSImagePicker*)picker didFinishPickingMediaWithInfo:(NSArray *)info;
//- (void)elcImagePickerControllerDidCancel:(BNSImagePicker *)picker;
//@end

typedef void (^OCSDKBNSImagePickerBlock)(NSArray *listImages, NSError* error);

@interface OCSDKBNSImagePicker : NSObject<UIImagePickerControllerDelegate, MyPhotoPickerDelegate, ELCAssetSelectionDelegate, UINavigationControllerDelegate> {
    UIViewController *ownerVC;
    OCSDKBNSImagePickerBlock completionBlock;
    BOOL singleSelection;
    BOOL showMyPhotoPicker;
}

@property (nonatomic, retain) NSMutableArray *assetGroups;
@property (nonatomic, strong) NSMutableArray *tempAssetGroups;
//@property (nonatomic, strong) id<ELCImagePickerControllerDelegate> delegate;

+(void)showInViewController:(UIViewController*)viewController
        withSingleSelection:(BOOL)singleSelection_
//          withMyPhotoPicker:(BOOL)showMyPhotoPicker
        withCompletionBlock:(OCSDKBNSImagePickerBlock)block;

-(void)takePhotoFromCamera;

@end
