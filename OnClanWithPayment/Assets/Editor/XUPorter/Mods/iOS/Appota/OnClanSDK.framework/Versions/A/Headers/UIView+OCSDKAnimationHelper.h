//
//  UIView+AnimationHelper.h
//  TatTay
//
//  Created by ToanDK on 7/11/13.
//  Copyright (c) 2013 ToanDK's Mac. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (OCSDKAnimationHelper)

-(void)rotateViewForever:(float)speed;
-(void)startScaleBouncing:(float)value duration:(float)duration repeatForever:(BOOL)loop;
-(void)startScaleBouncing:(float)value duration:(float)duration;
-(void)stopRotation;
-(void)stopScaling;
-(void) setAnimationWithScaleValue:(float) value duration:(float)duration repeatForever:(BOOL)loop;
-(void) scaleViewWithValue:(float) value duration:(float)duration bounces:(int)bounces;

- (void)shakeView:(UIView *)viewToShake;

- (void)shakeView:(UIView *)v originalX:(float)originalX;
+ (void)setShawdowView: (UIView*)view withRadius:(float)radius shawdowOffset: (CGSize)size shawdowRadius: (float)shawdowRadius shawdowOpacity: (float)opacity andMasksToBounds: (BOOL)bounds;



@end
