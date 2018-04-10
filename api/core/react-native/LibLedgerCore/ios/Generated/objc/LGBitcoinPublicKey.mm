// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_public_key_provider.djinni

#import "LGBitcoinPublicKey.h"


@implementation LGBitcoinPublicKey

- (nonnull instancetype)initWithPublicKey:(nonnull NSData *)publicKey
                                chainCode:(nonnull NSData *)chainCode
{
    if (self = [super init]) {
        _publicKey = [publicKey copy];
        _chainCode = [chainCode copy];
    }
    return self;
}

+ (nonnull instancetype)BitcoinPublicKeyWithPublicKey:(nonnull NSData *)publicKey
                                            chainCode:(nonnull NSData *)chainCode
{
    return [[self alloc] initWithPublicKey:publicKey
                                 chainCode:chainCode];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p publicKey:%@ chainCode:%@>", self.class, (void *)self, self.publicKey, self.chainCode];
}

@end
