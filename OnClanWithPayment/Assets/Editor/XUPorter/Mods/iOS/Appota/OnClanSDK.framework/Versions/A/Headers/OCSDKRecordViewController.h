//
//  OCSDKRecordViewController.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/14/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import "OCSDKBaseMenuViewController.h"
#import "OCSDKTwoButtonSegmentView.h"
//#import "OCSDKRecordTopNavigationView.h"
#import "OCSDKRecordPhotoTable.h"

@interface OCSDKRecordViewController : OCSDKBaseMenuViewController {
    UIView *viewBottomButtonView;
    NSMutableArray *listSegment;
    
    //OCSDKRecordTopNavigationView *topView;
    OCSDKRecordPhotoTable *photoTable;
    
    IBOutlet UITableView *tableImage;
    
}

@end
