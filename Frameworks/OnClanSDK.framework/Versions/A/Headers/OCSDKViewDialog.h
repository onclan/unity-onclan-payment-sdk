//
//  OCSDKViewDialog.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/4/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseDialog.h"
#import "OCSDKConst.h"

@interface OCSDKViewDialog : OCSDKBaseDialog
/**
 *  Show view in center with view name (get xib with name)
 *
 *  @param viewName must link with a xib
 */
+ (UIView*) showViewWithName:(NSString*) viewName;
+ (UIView*) showViewWithName:(NSString*) viewName withTag:(int) tag;
+ (OCSDKViewDialog*) showView:(UIView*) view withAnimation:(BOOL) animated;
//- (void) showView:(id) view
//      withHandler:(OCSDKViewHandler) handler;
@end
