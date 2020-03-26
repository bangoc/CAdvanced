#include "DebugPrintf/debug_printf.h"
#include "libfdr/dllist.h"
#include "libfdr/jval.h"

int main() {
  Dllist p = new_dllist();
  dll_insert_b(p, (Jval){.i = 1});
  dll_insert_b(p, (Jval){.i = 2});
  printfDebug("_(p) %p", p);
  Dllist newnode = p->blink;
  Dllist node1 = newnode->blink;
  printfDebug("newnode %p", newnode);
  printfDebug("node1 %p", node1);
  printfDebug("node1->blink %p", node1->blink);
  printfDebug("p->flink %p", p->flink);
  printfDebug("node1->flink %p", node1->flink);
  printfDebug("newnode->flink %p\n", newnode->flink);
  free_dllist(p);
  return 0;
}