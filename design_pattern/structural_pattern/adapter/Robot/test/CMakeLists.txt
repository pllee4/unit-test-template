add_executable(robotTest robotTest.cpp)

target_link_libraries(robotTest PRIVATE robot_interface gtest gmock gtest_main)

gtest_discover_tests(robotTest XML_OUTPUT_DIR ${PROJECT_BINARY_DIR}/test-reports)
add_test(NAME gtest_all COMMAND robotTest)