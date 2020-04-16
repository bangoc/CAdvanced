#include <stdio.h>
#include "cqueue.h"

int queue_state(Queue q, size_t sz, int f, int b) {
  return queue_size(q) == sz &&
         queue_front(q).i == f &&
         queue_back(q).i == b;
}

int failed(const char *msg) {
  printf("Test failed! %s\n", msg);
  return 1;
}

int main() {
  Queue q = queue_create();
  if (!queue_empty(q) || queue_pop(q)) {
    return failed("Empty start");
  }
  queue_push(q, (Jval){.i = 3});  // 3
  if (!queue_state(q, 1, 3, 3)) {
    return failed("State push 1");
  }
  queue_push(q, (Jval){.i = 5});  // 5 3
  if (!queue_state(q, 2, 3, 5)) {
    return failed("State push 2");
  }
  queue_push(q, (Jval){.i = 2});  // 2 5 3
  if (!queue_state(q, 3, 3, 2)) {
    return failed("State push 3");
  }
  if (!queue_pop(q)) {  // 2 5
    return failed("Return pop 1");
  }
  if (!queue_state(q, 2, 5, 2)) {
    return failed("State pop 1");
  }
  if (!queue_pop(q)) {  // 2
    return failed("Return pop 2");
  }
  if (!queue_state(q, 1, 2, 2)) {
    return failed("State pop 2");
  }
  if (!queue_pop(q)) {  // empty
    return failed("Return pop 3");
  }
  if (!queue_empty(q) || queue_pop(q)) {
    return failed("Empty end");
  }
  printf("Test Ok!");
  return 0;
}