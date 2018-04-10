// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_like_wallet.djinni

#import "LGBitcoinLikeCurrencyDescription.h"


@implementation LGBitcoinLikeCurrencyDescription

- (nonnull instancetype)initWithBIP44CoinType:(int32_t)BIP44CoinType
                          P2PKHAddressVersion:(nonnull NSData *)P2PKHAddressVersion
                           P2SHAddressVersion:(nonnull NSData *)P2SHAddressVersion
                           XPUBAddressVersion:(nonnull NSData *)XPUBAddressVersion
                                    shortName:(nonnull NSString *)shortName
{
    if (self = [super init]) {
        _BIP44CoinType = BIP44CoinType;
        _P2PKHAddressVersion = [P2PKHAddressVersion copy];
        _P2SHAddressVersion = [P2SHAddressVersion copy];
        _XPUBAddressVersion = [XPUBAddressVersion copy];
        _shortName = [shortName copy];
    }
    return self;
}

+ (nonnull instancetype)BitcoinLikeCurrencyDescriptionWithBIP44CoinType:(int32_t)BIP44CoinType
                                                    P2PKHAddressVersion:(nonnull NSData *)P2PKHAddressVersion
                                                     P2SHAddressVersion:(nonnull NSData *)P2SHAddressVersion
                                                     XPUBAddressVersion:(nonnull NSData *)XPUBAddressVersion
                                                              shortName:(nonnull NSString *)shortName
{
    return [[self alloc] initWithBIP44CoinType:BIP44CoinType
                           P2PKHAddressVersion:P2PKHAddressVersion
                            P2SHAddressVersion:P2SHAddressVersion
                            XPUBAddressVersion:XPUBAddressVersion
                                     shortName:shortName];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p BIP44CoinType:%@ P2PKHAddressVersion:%@ P2SHAddressVersion:%@ XPUBAddressVersion:%@ shortName:%@>", self.class, (void *)self, @(self.BIP44CoinType), self.P2PKHAddressVersion, self.P2SHAddressVersion, self.XPUBAddressVersion, self.shortName];
}

@end
