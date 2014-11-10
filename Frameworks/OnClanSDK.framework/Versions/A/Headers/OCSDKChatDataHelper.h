//
//  ChatDataHelper.h
//  NewAppotaApp
//
//  Created by ToanDK on 3/3/14.
//  Copyright (c) 2014 kiennt. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCSDKChatDataHelper : NSObject

+(NSString *)getFilePathFromPhoto:(UIImage *)photo;

+(void)saveStickyList:(NSArray*)list;

+(NSArray *)getSavedStickyList;

+(void)saveStickyListFromDict:(NSDictionary*)dict;

+(NSDictionary*)getStickyDictWithId:(NSString*)stickyId;

@end
