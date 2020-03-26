#include "c-vector/cvector.h"

int main() {
  cvector_vector_type(int) v;
  v = NULL;
  cvector_push_back(v, 5);
  cvector_free(v);
  return 0;
}