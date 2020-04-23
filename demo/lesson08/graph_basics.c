#include <stdio.h>

#include "igraph/igraph.h"

void print_edges(igraph_vector_t *v) {
  printf("Danh sách các cạnh là:\n");
  for (long int i = 0; i < igraph_vector_size(v)/2; ++i) {
    printf("%li %li\n", (long int)VECTOR(*v)[2 * i],
                        (long int)VECTOR(*v)[2 * i + 1]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  igraph_t g;
  igraph_small(&g, 0, IGRAPH_DIRECTED,
                0, 1,
                1, 2,
                2, 3,
                -1);
  printf("Số lượng đỉnh: %d \n", igraph_vcount(&g));
  printf("Số lượng cạnh: %d\n", igraph_ecount(&g));
  igraph_vector_t v;
  igraph_vector_init(&v, 0);
  igraph_get_edgelist(&g, &v, 0);
  printf("#elements of v: %li\n", igraph_vector_size(&v));
  print_edges(&v);

  FILE *out = fopen(argc > 1? argv[1]: "graph_basics.dot", "w");;
  igraph_write_graph_dot(&g, out);
  fclose(out);

  igraph_vector_destroy(&v);
  igraph_destroy(&g);
}