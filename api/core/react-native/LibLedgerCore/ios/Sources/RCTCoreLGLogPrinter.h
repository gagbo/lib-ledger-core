// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from logger.djinni

#import "../Generated/objc/LGExecutionContext.h"
#import "../Implementation/LGLogPrinterImpl.h"
#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>


/**
 *Class representing a printer of errors, warnings, infos ... (at runtime)
 *Printed logs are stored in path set by PathResolver::resolveLogFilePath
 */
@interface RCTCoreLGLogPrinter : NSObject <RCTBridgeModule>
@property (nonatomic, strong) LGLogPrinterImpl *objcImpl;
@end
