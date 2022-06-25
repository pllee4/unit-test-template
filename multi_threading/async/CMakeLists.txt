mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

find_package (Threads REQUIRED)

add_executable(async_test
    test/async_unittest.cpp)

target_include_directories(async_test PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(async_test 
    PRIVATE gtest gmock gtest_main Threads::Threads)
gtest_discover_tests(async_test XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)
add_test(NAME gtest_all COMMAND async_test)