//
//  OCSDKCHCoordinator+Animation.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/8/14.
//
//

#import "OCSDKCHCoordinator.h"

@interface OCSDKCHCoordinator (Animation)
- (CGRect) getDragFrame;
- (CGPoint)_destinationPointForReleasePoint:(CGPoint)releasePoint
                               withEdgeType:(CHSnappingEdge) edgeType;
- (CGRectEdge) getEdgeWithReleasePoint:(CGPoint) point;
@end
