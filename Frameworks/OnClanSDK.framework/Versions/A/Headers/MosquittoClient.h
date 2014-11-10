//
//  MosquittoClient.h
//
//  Copyright 2012 Nicholas Humfrey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MosquittoOperation.h"
#import "AMMessage.h"

@class MosquittoClient;

typedef void (^ConnectBlock)(BOOL status, int code);
typedef void (^SubcribleBlock)(BOOL status, int messageId);


@protocol MosquittoClientDelegate
- (void) didConnect: (NSUInteger)code;
- (void) didDisconnect;
- (void) didPublish: (NSUInteger)messageId;

// FIXME: create MosquittoMessage class

- (void) didSubscribe: (NSUInteger)messageId grantedQos:(NSArray*)qos;
- (void) didUnsubscribe: (NSUInteger)messageId;

@optional
//- (void) didReceiveMessage: (NSString*)message topic:(NSString*)topic;
- (void) didSendMessageFailed:(NSString *)messageId topic:(NSString *)topic;

-(void)didReceiveAMMessage:(AMMessage *)message topic:(NSString *)topic;

@end


@interface MosquittoClient : NSObject {
    struct mosquitto *mosq;
    NSString *host;
    unsigned short port;
    NSString *username;
    NSString *password;
    unsigned short keepAlive;
    BOOL cleanSession;
    NSMutableArray *listTopics;

//    id<MosquittoClientDelegate> __unsafe_unretained delegate;
    NSMutableArray *listDelegate;
    NSTimer *timer, *connectTimer;
    ConnectBlock connectBlock;
    SubcribleBlock subcribleBlock;
    NSMutableArray *listOperations;
}

@property (readwrite, strong) NSString *host;
@property (readwrite, unsafe_unretained) unsigned short port;
@property (readwrite, strong) NSString *username;
@property (readwrite, strong) NSString *password;
@property (readwrite, unsafe_unretained) unsigned short keepAlive;
@property (readwrite, unsafe_unretained) BOOL cleanSession;
@property (nonatomic, strong) NSMutableArray *listDelegate;
@property (nonatomic, assign) BOOL connected;
//@property (readwrite, unsafe_unretained) id<MosquittoClientDelegate> delegate;

+ (void) initialize;
+ (NSString*) version;

+(MosquittoClient *)sharedClient;
//- (MosquittoClient*) initWithClientId: (NSString *)clientId;
//- (MosquittoClient*) initWithClientId: (NSString*) clientId;
- (void) setMessageRetry: (NSUInteger)seconds;
- (void) connect;
- (void) connectToHost: (NSString*)host;
- (void) reconnect;
- (void) disconnect;

-(void)setupTLS:(BOOL)usingTLS;

-(void)addNewDelegate:(id)obj;
-(void)removeDelegate:(id)obj;

- (int)publishString: (NSString *)payload toTopic:(NSString *)topic withQos:(NSUInteger)qos retain:(BOOL)retain;
-(void)publishMessage:(AMMessage*)msg toTopic:(NSString*)topic withCompleteBlock:(AMMessageResponseBlock)completionBlock;

- (void)reSubcrible;
- (void)subscribe: (NSString *)topic;
- (void)subscribe: (NSString *)topic withQos:(NSUInteger)qos;
-(void)setupWillOptionForTopic:(NSString *)topic withQos:(NSUInteger)qos withPayload:(NSString *)payload;
- (void)unsubscribe: (NSString *)topic;

// This is called automatically when connected
- (void) loop: (NSTimer *)timer;

// ToanDK added
-(void)connectWithCompletionBlock:(ConnectBlock)handler;
-(void)subscribe:(NSString *)topic withCompletionBlock:(SubcribleBlock)handler;
-(void) reconnectWithCompletionBlock:(ConnectBlock)handler;
- (void)onConnect:(int)rc;
- (void)onSubcrible:(int)msgId;
@end
