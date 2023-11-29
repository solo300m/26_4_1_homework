cmake_minimum_required (VERSION 3.8)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable (Task_1 "Task_1.cpp" "${MY_INCLUDE_DIR}/Task_1.h" "${MY_INCLUDE_DIR}/Track.h" "${MY_INCLUDE_DIR}/Player.h")
target_include_directories(Task_1 PUBLIC ${MY_INCLUDE_DIR})