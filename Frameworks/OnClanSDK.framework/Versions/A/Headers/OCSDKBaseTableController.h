//
//  ArrayTableController.h
//  objc.io example project (issue #1)
//

#import <Foundation/Foundation.h>
//#import "AppotaSegmentedControl.h"


//typedef void (^BaseTableViewCellConfigureBlog)(id cell, id item);
typedef enum {
    OCSDKBaseTableViewKindNormal = 0,
    OCSDKBaseTableViewKindSearch,
    OCSDKBaseTableViewKindHaveHeader,
    OCSDKBaseTableViewKindPushToChatView
} OCSDKBaseTableViewKind;

@interface OCSDKBaseTableController : NSObject <UITableViewDataSource, UITableViewDelegate> {
    
}

@property (nonatomic, strong) NSMutableArray *items;
//@property (nonatomic, strong) NSMutableArray *itemMe;
@property (nonatomic, retain) UITableView *targetTableView;
@property (nonatomic, assign) OCSDKBaseTableViewKind tableViewKind;
- (id) initWithTargetTable:(UITableView *)targetTable;

- (void) registerNibWithTable:(UITableView*)tableView;

- (id) initWithTargetTable:(UITableView *)targetTable andKind:(OCSDKBaseTableViewKind)tableKind;

- (id)initWithItems:(NSArray *)anItems
    withTargetTable:(UITableView*) targetTable;

- (id)initWithItems:(NSArray *)anItems
    withTargetTable:(UITableView*) targetTable
            andKind:(OCSDKBaseTableViewKind)tableKind;

- (id)itemAtIndexPath:(NSIndexPath *)indexPath;

- (NSString*) getCellIdentifierWithItem:(id) item;

- (void) updateTableCellAtIndexPath:(NSIndexPath*) indexPath;

- (void) updateTableCellAtIndexPath:(NSIndexPath*) indexPath
                      withTableView:(UITableView*) tableView;

- (void) updateTableViewWithListItem:(NSArray*) listItems;

- (void) insertTableViewWithListItem:(NSArray*) listItems;

- (void) reloadTableView;

-(NSArray*) getListItem;

@end
