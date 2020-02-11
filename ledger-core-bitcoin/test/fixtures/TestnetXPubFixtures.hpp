#pragma once

#pragma once

#include <unordered_set>

#include <gtest/gtest.h>

#include <soci.h>

#include <async/QtThreadDispatcher.hpp>
#include <net/QtHttpClient.hpp>
#include <async/AsyncWait.hpp>

#include <NativePathResolver.hpp>
#include <CoutLogPrinter.hpp>

#include <core/database/DatabaseSessionPool.hpp>
#include <core/Services.hpp>
#include <core/api/DynamicObject.hpp>
#include <core/api/BigInt.hpp>
#include <core/api/Account.hpp>
#include <core/wallet/CurrencyBuilder.hpp>
#include <core/wallet/AccountDatabaseHelper.hpp>
#include <core/utils/JSONUtils.hpp>
#include <core/events/LambdaEventReceiver.hpp>

#include <bitcoin/BitcoinLikeWallet.hpp>
#include <bitcoin/BitcoinLikeAccount.hpp>
#include <bitcoin/api/BitcoinLikeOperation.hpp>
#include <bitcoin/api/BitcoinLikeTransaction.hpp>
#include <bitcoin/api/BitcoinLikeInput.hpp>
#include <bitcoin/api/BitcoinLikeAccount.hpp>
#include <bitcoin/api/BitcoinLikeOutput.hpp>
#include <bitcoin/database/BitcoinLikeWalletDatabase.hpp>
#include <bitcoin/database/BitcoinLikeTransactionDatabaseHelper.hpp>
#include <bitcoin/transactions/BitcoinLikeTransactionParser.hpp>

namespace ledger {
	namespace testing {
		namespace testnet_xpub {
			extern core::api::ExtendedKeyAccountCreationInfo XPUB_INFO;

			extern const std::string TX_1;
			extern const std::string TX_2;
			extern const std::string TX_3;
			extern const std::string TX_4;

			std::shared_ptr<core::BitcoinLikeAccount> inflate(const std::shared_ptr<core::Services>& services, const std::shared_ptr<core::AbstractWallet>& wallet);
		}
	}
}