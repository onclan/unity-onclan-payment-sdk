//
//  MyPhotosVC.h
//  NewAppotaApp
//
//  Created by ToanDK on 7/29/13.
//  Copyright (c) 2013 ToanDK's Mac. All rights reserved.
//

#import "OCSDKBaseViewController.h"
//#import "MHFacebookImageViewer.h"

@interface MyPhotosVC : OCSDKBaseViewController<UITableViewDataSource, UITableViewDelegate> {
    __weak IBOutlet UITableView *tableView;
    NSMutableArray *listPhotos;
}
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *photoType;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil withUser:(NSString *)userId;

@end
