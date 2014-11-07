//
//  TextFormatter.h
//  AppotaApp
//
//  Created by Anh Toan on 11/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OCSDKOHAttributedLabel.h"

@interface TextFormatter : NSObject

+(UILabel *)formatedTimeLabel:(CGRect )rect withText:(NSString *)text;
+(NSMutableAttributedString *)formatedStatusLabel:(NSString *)txt;
+(NSString *)timeToString:(int)time;
+(NSString *)timeToShortString:(int)time;
+(NSDate *)dateFromTimeStamp:(NSString *)timeStamp;
+(NSString *)timeStampFromDate:(NSDate *)date;
+(NSString *)slowTimeStampFromDate:(NSDate *)date;

@end
