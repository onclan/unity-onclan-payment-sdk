//
//  ShowImageViewController.h
//  AppotaMessager
//
//  Created by Appota on 7/1/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#import "OCSDKBaseView.h"

@interface OCSDKShowImageViewController : OCSDKBaseView<UIScrollViewDelegate, UIGestureRecognizerDelegate> {
    
}
@property (strong, nonatomic) UIImageView *showImageImageView;
@property (strong, nonatomic) NSURL *imageUrl;
@property (strong, nonatomic) UIScrollView *scrollView;

- (id)initWithFrame:(CGRect)frame andImageLink:(NSURL*)urlString;
- (void)displayImage;

+ (void) showFullScreenImageWithURLString:(NSString*) urlString;
+ (void) showLocalFullScreenImage:(NSString*) imageFilePath;
@end
