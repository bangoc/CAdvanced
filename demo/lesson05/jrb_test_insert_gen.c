#include "libfdr/jrb.h"
#include "libfdr/jval.h"

#include "DebugPrintf/debug_printf.h"

char label[2] = {'B', 'R'};

int cmp_i(Jval v1, Jval v2) {
  if (v1.i < v2.i) {
    return -1;
  } else if (v1.i > v2.i) {
    return 1;
  }
  return 0;
}

int main() {
  JRB tree = make_jrb();
  for (int i = 1; i < 10; ++i) {
    jrb_insert_gen(tree, (Jval){.i=i}, (Jval){.i=0}, cmp_i);
  }
  for(JRB ptr = jrb_first(tree); ptr != jrb_nil(tree); ptr = jrb_next(ptr)) {
    printfInfo("%d(%c)<-%d", ptr->key.i, label[ptr->red], ptr->parent->key.i);
  }
}