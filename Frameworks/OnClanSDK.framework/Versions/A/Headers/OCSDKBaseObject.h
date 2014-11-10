//
//  ApplicationData.h
//  Appvn
//
//  Created by tuent on 2/6/14.
//  Copyright (c) 2014 Appota. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OCSDKBaseObject : NSObject <NSCoding>
@property (readwrite) BOOL objectState;
@property (nonatomic, copy) NSDictionary* objectDict;
- (NSString*)description;
- (id) initWithObjectDict:(NSDictionary*) applicationDict;
+ (NSArray*) createListDataFromListDict:(NSArray*) listDict;
- (id) objectForKey:(NSString*) key;
- (NSString*) getObjectMessage;

@end
