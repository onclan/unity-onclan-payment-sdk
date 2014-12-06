//
//  Language.h
//  LanguageDemo
//
//  Created by Donly Chan on 12-7-21.
//  Copyright (c) 2012年 MAGICALBOY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Language : NSObject

+(void)initialize;
+(void)setLanguage:(NSString *)l;
+(NSString *)get:(NSString *)key alter:(NSString *)alternate;
+(NSString *)get:(NSString *)key;

#define OCSDKLog(fmt, ...) //NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)


@end
