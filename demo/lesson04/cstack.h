#ifndef CSTACK_H_
#define CSTACK_H_

#include "libfdr/dllist.h"
#include "libfdr/jval.h"
/*

---

 1  push(stack, 1)
---

 2  push(stack, 2)
 1
---

 1  pop(stack)
---


Ví dụ một hướng triển khai dựa trên dllist
  push: dll_insert_b(p->flink, value)
  pop: dll_delete_node(p->flink)
*/

// Tương tự như đối với kiểu vector, bạn hoàn toàn có khả năng
// mắc lỗi theo cách truyền một biến dllist không phải Stack
// cho các hàm xử lý Stack
typedef Dllist Stack;

Stack stack_create();
void stack_push(Stack, Jval);
int stack_pop(Stack);
Jval stack_top(Stack);
int stack_empty(Stack);
void stack_free(Stack);

#endif  // CSTACK_H_