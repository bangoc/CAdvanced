#include "c-vector/cvector.h"
#include "libfdr/dllist.h"
#include "libfdr/jrb.h"
#include "libfdr/jval.h"

#include "DebugPrintf/debug_printf.h"
#include "mylib/containers.h"

#include <stdio.h>

int print_i(void *value, void *user_data) {
  printfInfo("%p: %d", value, *((int*)value));
  return 0;
}

int print_jvali(void *value, void *user_data) {
  printfInfo("%d", ((Jval*)value)->i);
  return 0;
}

int fsum_i(void *value, void *user_data) {
  (*(int*)user_data) += (*(int*)value);
  return 0;
}

int fsum_jvali(void *value, void *user_data) {
  (*(int*)user_data) += ((Jval*)value)->i;
  return 0;
}

int kv_print_jvali(void* key, void *value, void *user_data) {
  return print_jvali(value, user_data);
}

int fkv_sum_jvali(void *key, void *value, void *user_data) {
  return fsum_jvali(value, user_data);
}

int main(int argc, char *argv[]) {
  cvector_vector_type(int) v = NULL;
  Dllist d = new_dllist();  // stack, queue ...
  JRB t = make_jrb();
  int asw = 0;
  for (int i = 0; i < 10; ++i) {
    cvector_push_back(v, i);
    dll_insert_b(d, (Jval){.i = i});
    jrb_insert_int(t, i, (Jval) {.i = i});
    asw += i;
  }

  // --- phong cách duyệt tuần tự
  vec_foreach(v, print_i, NULL);
  dli_foreach(d, print_jvali, NULL);
  jrb_foreach(t, kv_print_jvali, NULL);

  int sum_v = 0, sum_d = 0, sum_t = 0;
  vec_foreach(v, fsum_i, &sum_v);
  dli_foreach(d, fsum_jvali, &sum_d);
  jrb_foreach(t, fkv_sum_jvali, &sum_t);
  if (sum_v != sum_d || sum_v != sum_t || sum_v != asw) {
    printfError("There is a bug!");
  } else {
    printfInfo("Sum of [0..10) is: %d", sum_v);
  }

  return 0;
}