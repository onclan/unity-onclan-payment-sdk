//
//  OCSDKSoundHelper.h
//  NewAppotaApp
//
//  Created by ToanDK on 3/5/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface OCSDKSoundHelper : NSObject<AVAudioPlayerDelegate> {
    AVAudioPlayer *_player;
    float audioVolume;
}

+(OCSDKSoundHelper *)sharedInstance;
- (void) playCapturePhoto;
- (void) playIncomingMessage;
- (void)volumeChanged:(NSNotification *)notification;

@end
