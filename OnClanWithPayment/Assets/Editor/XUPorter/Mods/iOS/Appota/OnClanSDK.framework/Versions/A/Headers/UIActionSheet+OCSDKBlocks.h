//
//  UIActionSheet+Blocks.h
//  UIActionSheetBlocks
//
//  Created by Ryan Maxwell on 31/08/13.
//
//  The MIT License (MIT)
//
//  Copyright (c) 2013 Ryan Maxwell
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>

typedef void (^OCSDKUIActionSheetBlock) (UIActionSheet *actionSheet);
typedef void (^OCSDKUIActionSheetCompletionBlock) (UIActionSheet *actionSheet, NSInteger buttonIndex);

@interface UIActionSheet (OCSDKBlocks)

+ (instancetype)showFromTabBar:(UITabBar *)tabBar
                     withTitle:(NSString *)title
             cancelButtonTitle:(NSString *)cancelButtonTitle
        destructiveButtonTitle:(NSString *)destructiveButtonTitle
             otherButtonTitles:(NSArray *)otherButtonTitles
                      tapBlock:(OCSDKUIActionSheetCompletionBlock)tapBlock;

+ (instancetype)showFromToolbar:(UIToolbar *)toolbar
                      withTitle:(NSString *)title
              cancelButtonTitle:(NSString *)cancelButtonTitle
         destructiveButtonTitle:(NSString *)destructiveButtonTitle
              otherButtonTitles:(NSArray *)otherButtonTitles
                       tapBlock:(OCSDKUIActionSheetCompletionBlock)tapBlock;

+ (instancetype)showInView:(UIView *)view
                 withTitle:(NSString *)title
         cancelButtonTitle:(NSString *)cancelButtonTitle
    destructiveButtonTitle:(NSString *)destructiveButtonTitle
         otherButtonTitles:(NSArray *)otherButtonTitles
                  tapBlock:(OCSDKUIActionSheetCompletionBlock)tapBlock;

+ (instancetype)showFromBarButtonItem:(UIBarButtonItem *)barButtonItem
                             animated:(BOOL)animated
                            withTitle:(NSString *)title
                    cancelButtonTitle:(NSString *)cancelButtonTitle
               destructiveButtonTitle:(NSString *)destructiveButtonTitle
                    otherButtonTitles:(NSArray *)otherButtonTitles
                             tapBlock:(OCSDKUIActionSheetCompletionBlock)tapBlock;

+ (instancetype)showFromRect:(CGRect)rect
                      inView:(UIView *)view
                    animated:(BOOL)animated
                   withTitle:(NSString *)title
           cancelButtonTitle:(NSString *)cancelButtonTitle
      destructiveButtonTitle:(NSString *)destructiveButtonTitle
           otherButtonTitles:(NSArray *)otherButtonTitles
                    tapBlock:(OCSDKUIActionSheetCompletionBlock)tapBlock;

@property (copy, nonatomic) OCSDKUIActionSheetCompletionBlock tapBlock;
@property (copy, nonatomic) OCSDKUIActionSheetCompletionBlock willDismissBlock;
@property (copy, nonatomic) OCSDKUIActionSheetCompletionBlock didDismissBlock;

@property (copy, nonatomic) OCSDKUIActionSheetBlock willPresentBlock;
@property (copy, nonatomic) OCSDKUIActionSheetBlock didPresentBlock;
@property (copy, nonatomic) OCSDKUIActionSheetBlock cancelBlock;

@end
