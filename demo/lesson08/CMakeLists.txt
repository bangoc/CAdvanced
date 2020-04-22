project(lesson08 C)

add_executable(containers2 containers2.c)
target_link_libraries(containers2 fdr debug_printf)

if (USE_IGRAPH)
  add_executable(graph_basics graph_basics.c)
  target_link_libraries(graph_basics ${IGRAPH_LIBS})
endif (USE_IGRAPH)