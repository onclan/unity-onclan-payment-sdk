//
//  ELCShowVideoView.h
//  onClan
//
//  Created by Appota on 6/11/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <AVFoundation/AVFoundation.h>
@protocol ELCTakePictureDelegate
@optional
- (void)cancelTakePicture;
- (void)saveTakePicture;
@required
- (void)takePicture;
@end

@interface ELCShowVideoView : UIView {
    
}
@property (strong, nonatomic) IBOutlet UIButton *buttonTakePhoto;

@property (strong, nonatomic) AVCaptureSession *session;
@property (strong, nonatomic) id<ELCTakePictureDelegate>delegate;
- (void)showView;
- (IBAction)pressTakePhoto:(id)sender;

@end
