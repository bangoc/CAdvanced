#ifndef CQUEUE_H_
#define CQUEUE_H_

#include "libfdr/dllist.h"
#include "libfdr/jval.h"

typedef Dllist Queue;

Queue queue_create();
void queue_push(Queue, Jval);
int queue_pop(Queue);
Jval queue_front(Queue);
Jval queue_back(Queue);
size_t queue_empty(Queue);
void queue_free(Queue);

#endif  // CQUEUE_H_