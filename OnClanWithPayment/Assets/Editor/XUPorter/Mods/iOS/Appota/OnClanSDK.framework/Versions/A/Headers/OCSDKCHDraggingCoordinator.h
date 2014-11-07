//
//  CHDraggingCoordinator.h
//  ChatHeads
//
//  Created by Matthias Hochgatterer on 4/19/13.
//  Copyright (c) 2013 Matthias Hochgatterer. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OCSDKCHDraggableView.h"

typedef enum {
    CHSnappingEdgeBoth,
    CHSnappingEdgeRight,
    CHSnappingEdgeLeft,
    CHSnappingEdgeFourth,
} CHSnappingEdge;

typedef enum {
    CHInteractionStateNormal,
    CHInteractionStateConversation
} CHInteractionState;

@protocol OCSDKCHDraggingCoordinatorDelegate;
@interface OCSDKCHDraggingCoordinator : NSObject <CHDraggableViewDelegate>

@property (nonatomic) CHSnappingEdge snappingEdge;
@property (nonatomic, weak) id<OCSDKCHDraggingCoordinatorDelegate> delegate;
@property (nonatomic, assign) CGRect draggableViewBounds;
@property (nonatomic, assign) CHInteractionState state;

- (id)initWithWindow:(UIWindow *)window draggableViewBounds:(CGRect)bounds;
#pragma mark - Extended function for subclass
- (CGRect)_dropArea;
- (CGRect)_conversationArea;
- (CGRectEdge)_destinationEdgeForReleasePointInCurrentState:(CGPoint)releasePoint;
- (CGPoint)_destinationPointForReleasePoint:(CGPoint)releasePoint;

@end

@protocol OCSDKCHDraggingCoordinatorDelegate <NSObject>

- (UIViewController *)draggingCoordinator:(OCSDKCHDraggingCoordinator *)coordinator viewControllerForDraggableView:(OCSDKCHDraggableView *)draggableView;

@end
