//
//  MKBlockAdditions.h
//  UIKitCategoryAdditions
//
//  Created by Mugunth on 21/03/11.
//  Copyright 2011 Steinlogic All rights reserved.
//

typedef void (^OCSDKVoidBlock)();
typedef void (^OCSDKDismissBlock)(int buttonIndex);
typedef void (^OCSDKCancelBlock)();
typedef void (^OCSDKPhotoPickedBlock)(UIImage *chosenImage);

#define kPhotoActionSheetTag 10000