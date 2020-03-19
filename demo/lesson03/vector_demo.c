#include "c-vector/cvector.h"
#include "DebugPrintf/debug_printf.h"

int main() {
  cvector_vector_type(int) v = NULL;
  cvector_push_back(v, 5);
  cvector_push_back(v, 10);
  cvector_push_back(v, 20);

  printfDebug("v size = %d", cvector_size(v));
  for (int i = 0; i < cvector_size(v); ++i) {
    printfDebug("v[%d] = %d", i, v[i]);
  }

  cvector_free(v);
  return 0;
}