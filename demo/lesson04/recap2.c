#include "c-vector/cvector.h"

int count1(int* v) {
  // ..
}

int count2(cvector_vector_type(int) v) {
  //...
}

int main() {
  cvector_vector_type(int) v = NULL;
  // ...
  count1(v);
  count2(v);
  // ...

  // ...
  int *a = (int*)calloc(100, sizeof(int));
  count1(a);
  count2(a);

  // ....

  return 0;
}