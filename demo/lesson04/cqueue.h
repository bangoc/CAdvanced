#ifndef CQUEUE_H_
#define CQUEUE_H_

#include "libfdr/dllist.h"
#include "libfdr/jval.h"

/*

            ||
push(q, 1): | 1 |
push(q, 2): | 2 1 |
push(q, 3): | 3 2 1 |
pop(q):     | 3 2 |

Ví dụ một hướng triển khai dựa trên dllist:
  dll_insert_b(p->flink, val)
  dll_delete_node(p->blink)

*/

typedef Dllist Queue;

Queue queue_create();
void queue_push(Queue, Jval);
int queue_pop(Queue);
Jval queue_front(Queue);
Jval queue_back(Queue);
int queue_empty(Queue);
void queue_free(Queue);
size_t queue_size(Queue);

#endif  // CQUEUE_H_