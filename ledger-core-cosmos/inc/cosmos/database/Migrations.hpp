#pragma once

#include <core/database/Migrations.hpp>

namespace ledger {
    namespace core {
        /// Tag type.
        struct CosmosMigration {
          static int constexpr COIN_ID = 99999; // TODO: edit
          static uint32_t constexpr CURRENT_VERSION = 1; // TODO: edit
        };

        // migrations
        template <> void migrate<1, CosmosMigration>(soci::session& sql);
        template <> void rollback<1, CosmosMigration>(soci::session& sql);
  }
}
