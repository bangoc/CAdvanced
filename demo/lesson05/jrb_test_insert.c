#include "libfdr/jrb.h"
#include "libfdr/jval.h"

#include "DebugPrintf/debug_printf.h"

char label[2] = {'B', 'R'};

int main() {
  JRB tree = make_jrb();
  for (int i = 1; i <= 5; ++i) {
    jrb_insert_int(tree, i, (Jval){.i=0});
  }
  for(JRB ptr = jrb_first(tree); ptr != jrb_nil(tree); ptr = jrb_next(ptr)) {
    printfInfo("%d(%c)<-%d", ptr->key.i, label[ptr->red], ptr->parent->key.i);
  }
}