//
//  UIBubbleTableView.h
//
//  Created by Alex Barinov
//  Project home page: http://alexbarinov.github.com/UIBubbleTableView/
//
//  This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
//  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
//

#import <UIKit/UIKit.h>

#import "OCSDKChatTableViewDataSource.h"

#define TYPING_CELL_HEIGHT 40
#define HEADER_CELL_HEIGHT 28

typedef enum
{
    AMChatTypingTypeNobody = 0,
    AMChatTypingTypeMe = 1,
    AMChatTypingTypeSomebody = 2
} AMChatTypingType;

@class OCSDKChatViewController;
@interface OCSDKChatTableView : UITableView <UITableViewDelegate, UITableViewDataSource> {
    BOOL isHideView;
}

@property (nonatomic, weak) id<OCSDKChatTableViewDataSource> amChatDataSource;
@property (nonatomic) NSTimeInterval snapInterval;
@property (nonatomic) AMChatTypingType typingType;
@property (nonatomic) BOOL showAvatars;
@property (nonatomic) BOOL isFirstTimeShowThisChat;
@property (nonatomic, strong) OCSDKChatViewController *chatViewController;

- (void)initialDelegateAndDatasource:(OCSDKChatViewController *)viewcontroller2;
-(id)objectAtIndexPath:(NSIndexPath*)indexPath;

@end
