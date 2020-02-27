/*
 *
 * migrations.hpp
 *
 * Created by Dimitri Sabadie on 2019/07/04.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#pragma once

#include <core/api/DatabaseBackendType.hpp>
#include <core/database/Migrations.hpp>

#include <ripple/RippleLikeCoinID.hpp>

namespace ledger {
    namespace core {
        /// The Ripple tag type.
        struct XRPMigration {
          static int constexpr COIN_ID = RIPPLE_COIN_ID;
          static uint32_t constexpr CURRENT_VERSION = 5;
        };

        // migrations
        template <> void migrate<1, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void rollback<1, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void migrate<2, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void rollback<2, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void migrate<3, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void rollback<3, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void migrate<4, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void rollback<4, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void migrate<5, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
        template <> void rollback<5, XRPMigration>(soci::session& sql, api::DatabaseBackendType type);
  }
}
