add_executable(test_dllist test_dllist.c)
target_link_libraries(test_dllist debug_printf fdr)

add_executable(test_dllist_insert_b test_dllist_insert_b.c)
target_link_libraries(test_dllist_insert_b debug_printf fdr)

add_executable(dllist_demo dllist_demo.c)
target_link_libraries(dllist_demo debug_printf fdr)

add_executable(stack_demo examples/cstack_example.c cstack.c)
target_link_libraries(stack_demo fdr)
