//
//  OCSDKSaveHightScore.h
//  OnClanSDK
//
//  Created by TienLe on 12/22/14.
//
//

#import <Foundation/Foundation.h>

@interface OCSDKSaveHighScore : NSObject

+ (OCSDKSaveHighScore*) sharedInstance;

- (void) initializeDatabase;

- (void)saveHightScore:(unsigned int)score inCategoryId:(NSString*)category;

- (unsigned int)getScoreOfUserWithLeaderboardId:(NSString*)leaderboardId;

- (NSMutableArray *)getListScoreOfUserInAllLeaderboardId;
@end
