mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

add_executable(RungeKuttaTest src/RungeKutta.c test/RungeKuttaTest.cpp)
target_include_directories(RungeKuttaTest PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(RungeKuttaTest PRIVATE gtest gmock gtest_main)
gtest_discover_tests(RungeKuttaTest XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)
add_test(NAME gtest_all COMMAND RungeKuttaTest)