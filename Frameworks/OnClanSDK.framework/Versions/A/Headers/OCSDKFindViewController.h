//
//  FindViewController.h
//  AppstoreVN
//
//  Created by Anh Toan on 9/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIView (OCSDKFindUIViewController)
- (UIViewController *) firstAvailableUIViewController;
- (id) traverseResponderChainForUIViewController;
@end
