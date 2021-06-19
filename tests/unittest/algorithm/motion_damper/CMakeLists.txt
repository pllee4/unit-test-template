mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

add_executable(motion_damper_test motion_damper.c motion_damper_unittest.cpp)
target_link_libraries(motion_damper_test PRIVATE gtest gmock gtest_main)
gtest_discover_tests(motion_damper_test)
add_test(NAME gtest_all COMMAND motion_damper_test)