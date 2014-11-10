//
//  OCSDKBaseView.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/4/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "OCSDKConst.h"

#define DEFAULT_FRAME_WIDTH_IPHONE 300
#define DEFAULT_FRAME_WIDTH_IPAD 512

@class OCSDKViewDialog;

@interface OCSDKBaseView : UIView
+ (id) initViewFromXib;
@property (nonatomic, strong) OCSDKViewDialog* dialog;
@property (nonatomic, strong) OCSDKViewHandler handler;

#pragma mark - Move view fuction (apply for text field delegate)

typedef enum
{
    OCSDKViewMoveOrientationUp,
    OCSDKViewMoveOrientationDown,
} OCSDKViewMoveOrientation;

/**
 *  Derived to custom lenght
 *
 *  @return Default view move lenght, customize for each
 */
- (float) getViewMoveUpdateLengthWithTextField:(UITextField*) textField;

- (void) moveViewOrientation:(OCSDKViewMoveOrientation) orientation;

- (void) moveViewOrientation:(OCSDKViewMoveOrientation) orientation withTextField:(UITextField*) textField;

- (void) closeView;

//- (float) getDefaultFrameWidth;
- (void) loadContentsFromNib;
- (void) loadContentsFromNibNamed:(NSString*)nibName;
//+ (UINib*) _nibLoadingAssociatedNibWithName:(NSString*)nibName;
@end
