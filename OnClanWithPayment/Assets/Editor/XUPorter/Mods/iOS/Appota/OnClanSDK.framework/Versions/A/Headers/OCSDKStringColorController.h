//
//  OCSDKStringColorController.h
//  OnClanSDK
//
//  Created by TienLe on 8/11/14.
//
//

#import <Foundation/Foundation.h>

@interface OCSDKStringColorController : NSObject

+ (OCSDKStringColorController*) sharedInstance;
- (void)setColorToFirstCharacterWithStrinng: (NSString*)stringInput forView:(UIImageView*)imageView withUrlString:(NSURL*)urlString;
@end
