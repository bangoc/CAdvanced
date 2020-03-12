#include <stdio.h>

union MyVal {
  long l;
  double d;
  char *s;
  void *v;
  int ai[2];
  char ac[8];
};

typedef union MyVal MyVal_t;

int main() {
  // 1. Khai báo biến
  // union MyVal val;
  // MyVal_t val2;

  // 2. Kiểm tra các kích thước kiểu
  // printf("sizeof(long) = %ld\n"
  //        "sizeof(double) = %ld\n"
  //        "sizeof(char*) = %ld\n"
  //        "sizeof(void*) = %ld\n"
  //        "sizeof(int) = %ld\n"
  //        "sizeof(char) = %ld\n"
  //        "sizeof(MyVal_t) = %ld\n",
  //        sizeof(long), sizeof(double),
  //        sizeof(char*), sizeof(void*),
  //        sizeof(int), sizeof(char),
  //        sizeof(union MyVal));

  // 3. Kiểm tra địa chỉ biến thành viên
  // MyVal_t val;
  // printf("Addresses of: \n"
  //        "l:\t%p\n"
  //        "d:\t%p\n"
  //        "s:\t%p\n"
  //        "v:\t%p\n"
  //        "ai:\t%p\n"
  //        "ac:\t%p\n"
  //        "val:\t%p\n",
  //        &val.l, &val.d, &val.s, &val.v,
  //        &val.ai, &val.ac, &val);

  // 4. Sử dụng union
  // MyVal_t val = {.l = 1000000};
  // printf("val.l = %ld\n", val.l);

  // 5. Cảnh báo sử dụng union
  // MyVal_t val = {.l = 1000000};
  // printf("val.d = %lf\n", val.d);

  // 6. Sử dụng union (2)
  // union {
  //   unsigned char c;
  //   struct {
  //     unsigned char b7: 1;
  //     unsigned char b6: 1;
  //     unsigned char b5: 1;
  //     unsigned char b4: 1;
  //     unsigned char b3: 1;
  //     unsigned char b2: 1;
  //     unsigned char b1: 1;
  //     unsigned char b0: 1;
  //   };
  // } val = { .c = 'A' };
  // printf("sizeof(val) = %ld\n", sizeof(val));
  // printf("val.c = %c (%d-%d%d%d%d%d%d%d%d)\n",
  //   val.c, val.c, val.b0, val.b1, val.b2,
  //   val.b3, val.b4, val.b5, val.b6, val.b7);

  return 0;
}