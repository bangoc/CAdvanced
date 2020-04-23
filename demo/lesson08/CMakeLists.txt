project(lesson08 C)

add_executable(containers1 containers1.c)
add_executable(containers2 containers2.c)
foreach (p containers1 containers2)
  target_link_libraries(${p} fdr debug_printf)
endforeach (p)

if (USE_IGRAPH)
  add_executable(graph_basics graph_basics.c)
  target_link_libraries(graph_basics ${IGRAPH_LIBS})
endif (USE_IGRAPH)