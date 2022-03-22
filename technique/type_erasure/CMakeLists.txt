mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

add_executable(type_erasure 
    test/object_wrapper_unittest.cpp)

target_include_directories(type_erasure PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(type_erasure PRIVATE gtest gmock gtest_main)
gtest_discover_tests(type_erasure XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)
add_test(NAME gtest_all COMMAND type_erasure)