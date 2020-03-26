#include "cstack.h"

Stack stack_create() {
  return new_dllist();
}

void stack_push(Stack s, Jval value) {
  dll_insert_b(s->flink, value);
}

int stack_pop(Stack s) {
  if (dll_empty(s)) {
    return 0;
  }
  dll_delete_node(s->flink);
  return 1;
}

Jval stack_top(Stack s) {
  return s->flink->val;
}

int stack_empty(Stack s) {
  return dll_empty(s);
}

void stack_free(Stack s) {
  free_dllist(s);
}