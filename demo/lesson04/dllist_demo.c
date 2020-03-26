#include "DebugPrintf/debug_printf.h"
#include "libfdr/dllist.h"
#include "libfdr/jval.h"

int main() {
  Dllist p = new_dllist();
  for (int i = 0; i < 100; ++i) {
    dll_insert_b(p, (Jval){.i = i});
  }
  for (Dllist iter = p->flink; iter != p; iter = iter->flink) {
    printfInfo("%d", iter->val.i);
  }
  for (int i = 0; i < 10; ++i) {
    dll_delete_node(p->flink);
  }
  for (int i = 0; i < 3; ++i) {
    dll_delete_node(p->blink);
  }
  printfInfo("Nội dung danh sách sau khi xóa");
  for (Dllist iter = p->flink; iter != p; iter = iter->flink) {
    printfInfo("%d", iter->val.i);
  }
  free_dllist(p);
  return 0;
}
