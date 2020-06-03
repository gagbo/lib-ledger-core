cmake_minimum_required(VERSION 3.12)
project(ledger-core)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(lib)
add_subdirectory(src)

if(BUILD_TESTS)
    message(STATUS "ledger-core tests are enabled")
    enable_testing()
    add_subdirectory(test/lib/qt-host)
    add_subdirectory(test)
else()
    message(STATUS "ledger-core tests are disabled")
endif()
