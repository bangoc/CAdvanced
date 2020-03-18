cmake_minimum_required(VERSION 2.8)
project(CAdvanced)
add_subdirectory(DebugPrintf)
include_directories(${CMAKE_SOURCE_DIR})
add_executable(demo_debug_printf hello/demo_debug_printf.c)
target_link_libraries(demo_debug_printf debug_printf)
add_library(mylib STATIC mylib/qsort.c)
add_executable(qsort_demo resources/Quick_Sort.c)
target_link_libraries(qsort_demo debug_printf mylib)

# 3. thêm chương trình tên là sol01 bằng cách biên dịch mã nguồn sol01.c
# 4. liên kết thư viện mylib vào sol01