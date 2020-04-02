add_executable(jrb_strsort jrb_strsort.c)
target_link_libraries(jrb_strsort fdr)

add_executable(jrb_strsort_file jrb_strsort_file.c)
target_link_libraries(jrb_strsort_file fdr)

add_executable(jrb_strsort_pipe jrb_strsort_pipe.c)
target_link_libraries(jrb_strsort_pipe fdr)

add_executable(jrb_ni_sort1 jrb_ni_sort1.c)
target_link_libraries(jrb_ni_sort1 fdr)

add_executable(jrb_test_insert jrb_test_insert.c)
target_link_libraries(jrb_test_insert fdr debug_printf)

add_executable(jrb_test_insert_gen jrb_test_insert_gen.c)
target_link_libraries(jrb_test_insert_gen fdr debug_printf)