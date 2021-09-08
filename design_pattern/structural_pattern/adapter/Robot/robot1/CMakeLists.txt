add_library(robot STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/robot1.c)
target_link_libraries(robot PUBLIC common)
target_include_directories(robot PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)