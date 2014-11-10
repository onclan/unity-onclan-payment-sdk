//
//  AwesomeMenu.h
//  AwesomeMenu
//
//  Created by Levey on 11/30/11.
//  Copyright (c) 2011 Levey & Other Contributors. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKAwesomeMenuItem.h"

@protocol OCSDKAwesomeMenuDelegate;


@interface OCSDKAwesomeMenu : UIView <OCSDKAwesomeMenuItemDelegate>

@property (nonatomic, copy) NSArray *menusArray;
@property (nonatomic, getter = isExpanding) BOOL expanding;
@property (nonatomic, weak) id<OCSDKAwesomeMenuDelegate> delegate;

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIImage *highlightedImage;
@property (nonatomic, strong) UIImage *contentImage;
@property (nonatomic, strong) UIImage *highlightedContentImage;

@property (nonatomic, assign) CGFloat nearRadius;
@property (nonatomic, assign) CGFloat endRadius;
@property (nonatomic, assign) CGFloat farRadius;
@property (nonatomic, assign) CGPoint startPoint;
@property (nonatomic, assign) CGFloat timeOffset;
@property (nonatomic, assign) CGFloat rotateAngle;
@property (nonatomic, assign) CGFloat menuWholeAngle;
@property (nonatomic, assign) CGFloat expandRotation;
@property (nonatomic, assign) CGFloat closeRotation;
@property (nonatomic, assign) CGFloat animationDuration;
@property (nonatomic, assign) BOOL    rotateAddButton;

- (id)initWithFrame:(CGRect)frame startItem:(OCSDKAwesomeMenuItem*)startItem optionMenus:(NSArray *)aMenusArray;

@end

@protocol OCSDKAwesomeMenuDelegate <NSObject>
- (void)awesomeMenu:(OCSDKAwesomeMenu *)menu didSelectIndex:(NSInteger)idx;
@optional
- (void)awesomeMenuDidFinishAnimationClose:(OCSDKAwesomeMenu *)menu;
- (void)awesomeMenuDidFinishAnimationOpen:(OCSDKAwesomeMenu *)menu;
- (void)awesomeMenuWillAnimateOpen:(OCSDKAwesomeMenu *)menu;
- (void)awesomeMenuWillAnimateClose:(OCSDKAwesomeMenu *)menu;
@end