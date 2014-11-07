//
//  OCSDKCHCoordinator.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 8/8/14.
//
//

#import "OCSDKCHDraggingCoordinator.h"

@protocol CHDraggableViewDelegate;

@interface OCSDKCHCoordinator : OCSDKCHDraggingCoordinator <CHDraggableViewDelegate>
{
    
}
- (CGRect) _dropAreaWithReleasePoint:(CGPoint) releasePoint;
@end
