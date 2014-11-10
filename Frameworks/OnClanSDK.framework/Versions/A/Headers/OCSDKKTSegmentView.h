//
//  KTSegmentView.h
//  NewAppotaApp
//
//  Created by Kien Nguyen on 8/2/13.
//  Copyright (c) 2013 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OCSDKBaseNibLoadedView.h"

@protocol KTSegmentViewDelegate
-(void) didSelectSegmentViewButtonAtIndex:(int) index;
@end


@interface OCSDKKTSegmentView : OCSDKBaseNibLoadedView {
    NSMutableArray *listButtons;
    UIView *viewBottom;
    int selectedIndex;
}
@property (nonatomic, assign) NSObject<KTSegmentViewDelegate> *delegate;
@property (nonatomic) BOOL isSmallView;
-(void) setListTitleArray:(NSArray *) array;
- (NSMutableArray*)getListTitleArray;

-(IBAction) didPressButton:(id) sender;
-(IBAction) touchDownButton:(id) sender;
-(void) setSelectedButtonIndex:(int) index;

@end
