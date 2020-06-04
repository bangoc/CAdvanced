project(CAdvanced C)
cmake_minimum_required(VERSION 2.8)
option(GPROF_FLAG "Bổ xung khóa để sử dụng với gprof" OFF)
option(USE_IGRAPH "Sử dụng igraph (xem hướng dẫn trong igraph.cmd)" OFF)
option(BUILD_DEMO "Biên dịch các ví dụ minh họa" ON)

set(CMAKE_C_STANDARD 99)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

if (GPROF_FLAG)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
endif (GPROF_FLAG)

add_subdirectory(DebugPrintf)
add_subdirectory(libfdr)
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/libfdr)

if (EXISTS "${CMAKE_SOURCE_DIR}/binaries/libigraph.a")
  set(USE_IGRAPH ON)
endif ()

if (USE_IGRAPH)
  add_library(igraph STATIC IMPORTED)
  set_target_properties(igraph PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/binaries/libigraph.a)
  set(IGRAPH_LIBS igraph m)
endif (USE_IGRAPH)

if (BUILD_DEMO)
  add_executable(demo_debug_printf demo/environment/demo_debug_printf.c)
  target_link_libraries(demo_debug_printf debug_printf)
  add_subdirectory(demo/lesson02)
  add_subdirectory(demo/lesson03)
  add_subdirectory(demo/lesson04)
  add_subdirectory(demo/lesson05)
  add_subdirectory(demo/lesson06)
  add_subdirectory(demo/lesson08)
endif (BUILD_DEMO)

# codes which use igraph go below this line
add_subdirectory(stud)