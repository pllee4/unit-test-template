mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

add_executable(VersionEnquiryManagerTest src/VersionEnquiryManager.c test/VersionEnquiryManagerTest.cpp)

target_include_directories(VersionEnquiryManagerTest PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(VersionEnquiryManagerTest PRIVATE gtest gmock gtest_main)

gtest_discover_tests(VersionEnquiryManagerTest XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)
add_test(NAME gtest_all COMMAND VersionEnquiryManagerTest)