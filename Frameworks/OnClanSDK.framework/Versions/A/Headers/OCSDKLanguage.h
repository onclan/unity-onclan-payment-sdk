//
//  OCSDKLanguage.h
//  OnClanSDK
//
//  Created by Tue Nguyen on 7/8/14.
//  Copyright (c) 2014 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCSDKLanguage : NSObject
+(void)initialize;
+(void)setLanguage:(NSString *)l;
+(NSString*) getLanguage;
+(NSString *)get:(NSString *)key alter:(NSString *)alternate;
+(NSString *)get:(NSString *)key;
//+(NSString*)getCurrentLanguage;
//+(void)setLanguageBundle:(NSString*)filePath;
@end
