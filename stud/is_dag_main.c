/*
 * Mục đích của mã nguồn này là để minh họa cách tạo các
 * chương trình (executable) mới
 *
 * Đây có thể là một lời giải đúng cho bài tập 9.1 nhưng
 * không hẳn đã là một lời giải hay.
 */

#include "c-vector/cvector.h"
#include <stdio.h>
#include "DebugPrintf/debug_printf.h"
#include "igraph/igraph.h"

int main(int argc, char *argv[]) {
  FILE *f = fopen("inp.txt", "r");
  cvector_vector_type(int) from = NULL;
  cvector_vector_type(int) to = NULL;
  int n = 0;
  while (!feof(f)) {
    int i, j;
    fscanf(f, "%d%d ", &i, &j);
    cvector_push_back(from, i);
    cvector_push_back(to, j);
    if (i > n) {
      n = i;
    }
    if (j > n) {
      n = j;
    }
  }
  n += 1;
  int m = cvector_size(from);
  fclose(f);

  igraph_t g;
  igraph_small(&g, n, 1, -1);
  for (int i = 0; i < m; ++i) {
    igraph_add_edge(&g, from[i], to[i]);
  }
  printfInfo("n = %d; #vertices = %d", n, igraph_vcount(&g));
  printfInfo("m = %d; #edges = %d", n, igraph_ecount(&g));
  igraph_bool_t dag;
  igraph_is_dag(&g, &dag);
  if (dag) {
    printf("Y");
  } else {
    printf("N");
  }

  FILE *out = fopen(argc > 1? argv[1]: "dag.dot", "w");;
  igraph_write_graph_dot(&g, out);
  fclose(out);
  igraph_destroy(&g);
  return 0;
}