#include "c-vector/cvector.h"
#include "libfdr/dllist.h"
#include "libfdr/jrb.h"
#include "libfdr/jval.h"

#include "DebugPrintf/debug_printf.h"
#include "mylib/containers.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
  cvector_vector_type(int) v = NULL;
  Dllist d = new_dllist();  // stack, queue ...
  JRB t = make_jrb();
  for (int i = 0; i < 10; ++i) {
    cvector_push_back(v, i);
    dll_insert_b(d, (Jval){.i = i});
    jrb_insert_int(t, i, (Jval) {.i = 1});
  }

  for (size_t i = 0; i < cvector_size(v); ++i) {
    printfInfo("vec: %d", v[i]);
  }

  for (Dllist iter = d->flink; iter != d; iter = iter->flink) {
    printfInfo("dllist: %d", iter->val.i);
  }

  for (JRB iter = t->flink; iter != t; iter = iter->flink) {
    printfInfo("jrb: %d", iter->key.i);
  }

  // --- phong cách duyệt tuần tự
  for (vec_iter(int) iter = vec_begin(v); iter != vec_end(v); vec_move(iter)) {
    printfInfo("+vec: %d", *iter);
  }

  for (dli_iter iter = dli_begin(d); iter != dli_end(d); dli_move(iter)) {
    printfInfo("+dllist: %d", iter->val.i);
  }

  for (jrb_iter iter = jrb_begin(t); iter != jrb_end(t); jrb_move(iter)) {
    printfInfo("+jrb: %d", iter->key.i);
  }
  return 0;
}