#include "igraph/igraph.h"

void vector_print(const char *name, igraph_vector_t *v) {
    long int i;
    printf(name);
    for (i = 0; i < igraph_vector_size(v); i++) {
        printf(" %li", (long int) VECTOR(*v)[i]);
    }
    printf("\n");
}

int main(int argc, char * argv[]) {
  igraph_t g;
  igraph_matrix_t mat;
  int m[7][7] = {
    {0, 1, 1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
  };

  igraph_matrix_init(&mat, 7, 7);
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 7; ++j) {
      MATRIX(mat, i, j) = m[i][j];
    }
  }

  igraph_weighted_adjacency(&g, &mat, IGRAPH_ADJ_UPPER, 0, /*loops=*/ 1);
  printf("Số lượng đỉnh: %d \n", igraph_vcount(&g));
  printf("Số lượng cạnh: %d\n", igraph_ecount(&g));

  igraph_vector_t order, rank, father, pred, succ, dist;
  igraph_vector_init(&order, 0);
  igraph_vector_init(&rank, 0);
  igraph_vector_init(&father, 0);
  igraph_vector_init(&pred, 0);
  igraph_vector_init(&succ, 0);
  igraph_vector_init(&dist, 0);

  igraph_bfs(&g, /*root=*/0, /*roots=*/ 0, /*neimode=*/ IGRAPH_ALL,
               /*unreachable=*/ 1, /*restricted=*/ 0,
               &order, &rank, &father, &pred, &succ, &dist,
               /*callback=*/ 0, /*extra=*/ 0);

  vector_print("order: ", &order);
  vector_print("father: ", &father);
  vector_print("dist: ", &dist);

  FILE *out = fopen(argc > 1? argv[1]: "graph_adjacency.dot", "w");;
  igraph_write_graph_dot(&g, out);
  fclose(out);

  igraph_matrix_destroy(&mat);
  igraph_destroy(&g);
  return 0;
}