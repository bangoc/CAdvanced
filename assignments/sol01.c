#include <stdio.h>

// 1. Chèn tệp tiêu đề của mylib

int main(int argc, char* argv[]) {
  FILE* inp = fopen(argv[1], "r");
  int n;
  fscanf(inp, "%d", &n);
  int* a = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; ++i) {
    fscanf(inp, "%d", a + i);
  }

  // 2. Gọi hàm quickSort

  display(a, n);
  free(a);
  fclose(inp);
}