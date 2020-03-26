#include "demo/lesson04/cstack.h"

int main() {
  Stack s = stack_create();

  stack_push(s, (Jval){.i = 1});
  stack_push(s, (Jval){.i = 2});
  stack_push(s, (Jval){.i = 3});

  printf("%d\n", stack_top(s).i);
  stack_pop(s);
  printf("%d\n", stack_top(s).i);
  stack_pop(s);
  printf("%d\n", stack_top(s).i);
  stack_free(s);
}