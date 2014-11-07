//
//  CHDraggableView.h
//  ChatHeads
//
//  Created by Matthias Hochgatterer on 4/19/13.
//  Copyright (c) 2013 Matthias Hochgatterer. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CHDraggableViewDelegate;
@interface OCSDKCHDraggableView : UIView

@property (nonatomic, assign) id<CHDraggableViewDelegate> delegate;

- (void)snapViewCenterToPoint:(CGPoint)point edge:(CGRectEdge)edge;

@end

@protocol CHDraggableViewDelegate <NSObject>

- (void)draggableViewHold:(OCSDKCHDraggableView *)view;
- (void)draggableView:(OCSDKCHDraggableView *)view didMoveToPoint:(CGPoint)point;
- (void)draggableViewReleased:(OCSDKCHDraggableView *)view;

- (void)draggableViewTouched:(OCSDKCHDraggableView *)view;

- (void)draggableViewNeedsAlignment:(OCSDKCHDraggableView *)view;

@end