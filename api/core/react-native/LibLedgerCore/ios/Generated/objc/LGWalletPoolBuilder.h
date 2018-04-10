// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet_pool.djinni

#import <Foundation/Foundation.h>
@class LGDatabaseBackend;
@class LGDynamicObject;
@class LGWalletPoolBuilder;
@protocol LGHttpClient;
@protocol LGLogPrinter;
@protocol LGPathResolver;
@protocol LGRandomNumberGenerator;
@protocol LGThreadDispatcher;
@protocol LGWalletPoolCallback;
@protocol LGWebSocketClient;


/**Class representing a wallet pool builder (to instanciate a wallet pool) */
@interface LGWalletPoolBuilder : NSObject

/**
 *Set http client to be used for wallet pool build
 *@param client, HttpClient
 *@return WalletPoolBuilder object, instance with wallet pool http client set
 */
- (nullable LGWalletPoolBuilder *)setHttpClient:(nullable id<LGHttpClient>)client;

/**
 *Set web socket client, through which wallet pool will listen and get notified (by explorers, DBs...)
 *@param client, WebSocketClient object
 *@reutnr WalletPoolBuilder object, instance with wallet pool web socket client set
 */
- (nullable LGWalletPoolBuilder *)setWebsocketClient:(nullable id<LGWebSocketClient>)client;

/**
 *Set path resolver that will be used for wallet pool creation to resolve wallet pool's (DB's, logs, preferences ...) paths
 *@param pathResolver, Pathresolver object
 *@param WalletPoolBuilder object, instance with wallet pool path resolver set
 */
- (nullable LGWalletPoolBuilder *)setPathResolver:(nullable id<LGPathResolver>)pathResolver;

/**
 *Set log printer that will be used for wallet pool creation to dump wallet pool's logs (for debug purposes)
 *@param printer, LogPrinter object
 *@param WalletPoolBuilder object, instance with wallet pool logger set
 */
- (nullable LGWalletPoolBuilder *)setLogPrinter:(nullable id<LGLogPrinter>)printer;

/**
 *Set thread dispatcher that will be used for wallet pool creation to dispatch wallet pool's tasks through different threads
 *@param dispatcher, ThreadDispatcher object
 *@param WalletPoolBuilder object, instance with wallet pool thread dispatcher set
 */
- (nullable LGWalletPoolBuilder *)setThreadDispatcher:(nullable id<LGThreadDispatcher>)dispatcher;

/**
 *Set name that will be used for wallet pool creation
 *@param name, string
 *@return WalletPoolBuilder object, instance with wallet pool name set
 */
- (nullable LGWalletPoolBuilder *)setName:(nonnull NSString *)name;

/**
 *Set password that will be used for wallet pool creation
 *@param password, string
 *@return WalletPoolBuilder object, with wallet pool password set
 */
- (nullable LGWalletPoolBuilder *)setPassword:(nonnull NSString *)password;

/**
 *Set random number generator that will be used for wallet pool creation
 *@param rng, RandomNumberGenerator object
 *@return WalletPoolBuilder object, with wallet pool random number generator set
 */
- (nullable LGWalletPoolBuilder *)setRandomNumberGenerator:(nullable id<LGRandomNumberGenerator>)rng;

/**
 *Set database that will be used for wallet pool creation, it will store all wallet pool's data (created wallets, accounts, preferences ...)
 *@param backend, DatabaseBackend object
 *@return WalletPoolBuilder object, with wallet pool database set
 */
- (nullable LGWalletPoolBuilder *)setDatabaseBackend:(nullable LGDatabaseBackend *)backend;

/**
 *Set configuration that will be used for wallet pool creation
 *@param configuration, DynamicObject object
 *@return WalletPoolBuilder object, with wallet pool configuration set
 */
- (nullable LGWalletPoolBuilder *)setConfiguration:(nullable LGDynamicObject *)configuration;

/**
 *Create wallet pool
 *@param callback, Callback object returning a WalletPool instance
 */
- (void)build:(nullable id<LGWalletPoolCallback>)listener;

/**
 *Create an instance of the wallet pool builder
 *@return WalletPoolBuilder object
 */
+ (nullable LGWalletPoolBuilder *)createInstance;

@end
