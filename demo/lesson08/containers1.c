#include "libfdr/dllist.h"

#include "DebugPrintf/debug_printf.h"
#include "mylib/containers.h"

int main() {
  Dllist d = new_dllist();
  for (int i = 0; i < 10; ++i) {
    dll_insert_b(d, (Jval){.i = i});
  }

  for (dli_iter iter = dli_begin(d); iter != dli_end(d); dli_move(iter)) {
    printfInfo("+dllist: %d", iter->val.i);
  }

  int sum = 0;
  for (dli_iter iter = dli_begin(d); iter != dli_end(d); dli_move(iter)) {
    sum += iter->val.i;
  }
  printfInfo("sum = %d", sum);

  return 0;
}