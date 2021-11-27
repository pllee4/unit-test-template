mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

add_executable(grid_test test/grid_unittest.cpp)
target_include_directories(grid_test PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(grid_test PRIVATE gtest gmock gtest_main)
gtest_discover_tests(grid_test XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)
add_test(NAME gtest_all COMMAND grid_test)