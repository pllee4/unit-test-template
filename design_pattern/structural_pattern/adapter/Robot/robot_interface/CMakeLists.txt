add_library(robot_interface STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/robot_interface.c)
target_link_libraries(robot_interface PRIVATE robot)
target_include_directories(robot_interface PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)