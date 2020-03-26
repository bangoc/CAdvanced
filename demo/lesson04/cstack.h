#ifndef CSTACK_H_
#define CSTACK_H_

#include "libfdr/dllist.h"
#include "libfdr/jval.h"

typedef Dllist Stack;

Stack stack_create();
void stack_push(Stack, Jval);
int stack_pop(Stack);
Jval stack_top(Stack);
int stack_empty(Stack);
void stack_free(Stack);

#endif  // CSTACK_H_