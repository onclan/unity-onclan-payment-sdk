//
//  UIApplication+WindowOverlay.h
//  AppotaSDK
//
//  Created by tuent on 10/31/13.
//
//

#import <UIKit/UIKit.h>

@interface UIApplication (OCSDKWindowOverlay)
@property (nonatomic, readonly) UIView *baseWindowView;
-(void)addWindowOverlay:(UIView *)view;
- (void) addWindowOverlay:(UIView *)view withIndex:(int) index;
- (void) addWindowOverlay:(UIView *)view belowView:(UIView*) view;
@end
