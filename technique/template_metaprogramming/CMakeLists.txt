mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

## function traits
add_executable(function_traits 
    test/function_traits_unittest.cpp)

target_include_directories(function_traits PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(function_traits PRIVATE gtest gmock gtest_main)
gtest_discover_tests(function_traits XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)

## variadic_overloading
add_executable(variadic_overloading 
    test/variadic_overloading_unittest.cpp)

target_include_directories(variadic_overloading PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(variadic_overloading PRIVATE gtest gmock gtest_main)
gtest_discover_tests(variadic_overloading XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)


add_test(NAME gtest_all COMMAND function_traits variadic_overloading)