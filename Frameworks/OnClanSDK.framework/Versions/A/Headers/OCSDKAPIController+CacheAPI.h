//
//  OCSDKAPIController+CacheAPI.h
//  OnClanSDK
//
//  Created by TienLe on 10/25/14.
//
//

#import "OCSDKAPIController.h"
#import "OCSDKFMDatabase.h"

@interface OCSDKAPIController (CacheAPI)

- (void)objectFromJSonString:(NSString *)jsonString withCompletionBlock:(void (^)(id jsonObject))jsonDecompressionHandler;

- (void) saveApiCacheInThreadWithParam     :(NSDictionary*) params
                                    withURL:(NSString*) url
                                 withMethod:(NSString*) method
                              withXmlString:(NSString*)xmlString
                       withCompleteionBlock:(void(^)(bool isCacheOnly))completeBlock;

- (NSDictionary*)readDataWithUrl:(NSString*)url atColumn:(NSString*)columnName;

- (NSString*)getXMLStringFromDataWithUrl:(NSString*)url;

- (BOOL) checkApiExists    :(NSString*) apiURL
                  withParam:(NSDictionary*) params
                 withMethod:(NSString *)method;

- (void)deleteAPICachedWithUrl:(NSString *)url withDatabase:(OCSDKFMDatabase*)database;

@end
