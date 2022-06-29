mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

add_executable(person_test
    test/person_unittest.cpp)

target_include_directories(person_test PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

find_package(Boost)

target_link_libraries(person_test 
    PRIVATE gtest gmock gtest_main ${Boost_LIBRARIES})
gtest_discover_tests(person_test XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)
add_test(NAME gtest_all COMMAND person_test)