#include "cjset.h"

#include "mylib/containers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  int val;
} SKeyVal;

SKeyVal tests[] = {
      {"A", 0},
      {"B", 1},
      {"C", 2},
      {"D", 3},
      {"E", 4},
      {"F", 5}
};

int jinsert(JRB j, int id) {
  char *buff = (char*)malloc(strlen(tests[id].key) + 1);
  strcpy(buff, tests[id].key);
  int status = jset_insert_str(j, buff, (Jval){.i = tests[id].val});
  free(buff);
  return status;
}
int jupdate(JRB j, char *key, int val) {
  int status = jset_update_str(j, key, (Jval){.i = val});
  return status;
}

int jset_state(JRB j, SKeyVal *seq, int sz) {
  if (jset_size(j) != sz) {
    return 0;
  }
  int id = 0;
  for (JRB iter = jrb_begin(j); iter != jrb_end(j); jrb_move(iter)) {
    if (strcmp(iter->key.s, seq[id].key) != 0 || iter->val.i != seq[id].val) {
      return 0;
    }
    ++id;
  }
  return 1;
}

int failed(const char *msg) {
  printf("Test failed! %s\n", msg);
  return 1;
}

int main() {
  JRB j = make_jrb();
  if (jinsert(j, 0) != 1) {
    return failed("JInsert return on new.");
  }
  if (jinsert(j, 0) != 0) {
    return failed("JInsert return on existing or state.");
  }
  SKeyVal t1[] = {tests[0]};
  if (!jset_state(j, t1, 1)) {
    return failed("JInsert 1");
  }
  for (int id = 1; id < 6; ++id) {
    jinsert(j, id);
  }
  if (!jset_state(j, tests, 6)) {
    return failed("JInsert 6");
  }
  if (jupdate(j, "XO", 10) != 0) {
    return failed("JUpdate XO");
  }
  for (int id = 0; id < 6; ++id) {
    tests[id].val *= 10;
    if (jupdate(j, tests[id].key, tests[id].val) != 1) {
      return failed("JUpdate tests");
    }
  }
  if (!jset_state(j, tests, 6)) {
    return failed("JUpdate states after");
  }

  // clean up
  for (JRB iter = jrb_begin(j); iter != jrb_end(j); jrb_move(iter)) {
    free(iter->key.s);
  }
  jrb_free_tree(j);
  printf("Test Ok!");
  return 0;
}