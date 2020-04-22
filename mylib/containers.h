#ifndef CONTAINERS_H_
#define CONTAINERS_H_

#define vec_iter(type) type *
#define vec_begin(vec) cvector_begin(vec)
#define vec_end(vec) cvector_end(vec)
#define vec_move(iter) ++iter

#define dli_iter Dllist
#define dli_begin(dli) (dli->flink)
#define dli_end(dli) (dli)
#define dli_move(iter) iter = iter->flink

#define jrb_iter JRB
#define jrb_begin(jtr) (jtr->flink)
#define jrb_end(jtr) (jtr)
#define jrb_move(iter) iter = iter->flink

/*
  Traverse functions return:
    1 - to break the traversing
    0 - to continue
*/

typedef int (*traverse_func_t)(void*, // vector element
                               void* // user data
                               );

typedef int(*kv_traverse_func_t)(void*, // key
                                 void*, // value
                                 void*  // user data
                                 );

#define vec_foreach(v, f, u) \
  do {   \
    long n = cvector_size(v); \
    for (long i = 0; i < n; ++i) {  \
      if (f(v + i, u)) { \
        break;  \
      } \
    } \
  } while (0)

#define dli_foreach(d, f, u) \
  do {  \
    for (dli_iter iter = dli_begin(d); iter != dli_end(d); dli_move(iter)) {  \
      if (f(&iter->val, u)) {  \
        break;  \
      }  \
    }  \
  } while (0)

#define jrb_foreach(j, f, u) \
  do { \
    for (jrb_iter iter = jrb_begin(t); iter != jrb_end(t); jrb_move(iter)) { \
      if (f(&iter->key, &iter->val, u)) { \
        break; \
      } \
    } \
  } while (0)

#endif  // CONTAINERS_H_