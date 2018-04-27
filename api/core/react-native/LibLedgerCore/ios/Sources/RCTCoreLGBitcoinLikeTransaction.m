// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_like_wallet.djinni

#import "RCTCoreLGBitcoinLikeTransaction.h"


@implementation RCTCoreLGBitcoinLikeTransaction
//Export module
RCT_EXPORT_MODULE(RCTCoreLGBitcoinLikeTransaction)

-(instancetype)init
{
    self = [super init];
    //Init Objc implementation
    if(self)
    {
        self.objcImpl = [[LGBitcoinLikeTransaction alloc] init];
    }
    return self;
}

/** Get the hash of the transaction. */
RCT_REMAP_METHOD(getHash,getHashWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getHash]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getHash", nil);
    }
}

/** Get the input of the transaction */
RCT_REMAP_METHOD(getInputs,getInputsWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getInputs]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getInputs", nil);
    }
}

/** Get the output of the transaction */
RCT_REMAP_METHOD(getOutputs,getOutputsWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getOutputs]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getOutputs", nil);
    }
}

/** Get the block in which the transaction is inserted if the transaction is confirmed. */
RCT_REMAP_METHOD(getBlock,getBlockWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getBlock]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getBlock", nil);
    }
}

/** Get the lock time of the transaction. */
RCT_REMAP_METHOD(getLockTime,getLockTimeWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :@([self.objcImpl getLockTime])};if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getLockTime", nil);
    }
}

/** Get the amount of fees of the transaction. */
RCT_REMAP_METHOD(getFees,getFeesWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getFees]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getFees", nil);
    }
}

/**
 * Get the time when the transaction was issued or the time of the block including
 * this transaction
 */
RCT_REMAP_METHOD(getTime,getTimeWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getTime]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getTime", nil);
    }
}

/** Get the timestamps serialized in the raw transaction if the underlying currency handles it. */
RCT_REMAP_METHOD(getTimestamp,getTimestampWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getTimestamp]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getTimestamp", nil);
    }
}

/** Serialize the transaction to its raw format. */
RCT_REMAP_METHOD(serialize,serializeWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl serialize]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::serialize", nil);
    }
}

/** Serialize outputs of the raw transaction into a byte array using the bitcoin transaction format. */
RCT_REMAP_METHOD(serializeOutputs,serializeOutputsWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl serializeOutputs]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::serializeOutputs", nil);
    }
}

/** Get the witness if the underlying transaction is a segwit transaction. */
RCT_REMAP_METHOD(getWitness,getWitnessWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getWitness]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getWitness", nil);
    }
}

/**
 * Estimate the size of the raw transaction in bytes. This method returns a minimum estimated size and a maximum estimated
 * size.
 */
RCT_REMAP_METHOD(getEstimatedSize,getEstimatedSizeWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getEstimatedSize]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeTransaction::getEstimatedSize", nil);
    }
}
@end
