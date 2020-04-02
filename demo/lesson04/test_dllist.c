#include "DebugPrintf/debug_printf.h"
#include "libfdr/dllist.h"

int main() {
  Dllist p = new_dllist();
  printfDebug("%p", p);
  printfDebug("%p", p->flink);
  printfDebug("%p", p->blink);

  /*
  Giải phóng bộ nhớ bằng cách nào?
  */
  return 0;
}