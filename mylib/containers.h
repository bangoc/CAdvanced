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

#endif  // CONTAINERS_H_