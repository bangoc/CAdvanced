set(CMAKE_C_STANDARD 99)

add_executable(demo_function_declarator function_declarator.c foo.c)
add_executable(fp_demo fp_demo.c)
add_executable(union_demo union_demo.c)
add_executable(void_demo void_demo.c)
add_executable(fp_demo_generic fp_demo_generic.c)

add_executable(jval_demo jval_demo.c)
target_link_libraries(jval_demo fdr)