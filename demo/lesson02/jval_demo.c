// cài lại void_demo sử dụng jval trong libfdr
#include <stdio.h>

#include "libfdr/jval.h"

// void display_i(int i) {
//   printf("i = %d\n", i);
// }

void display_i(Jval value) {
  printf("i = %d\n", value.i);
}

void display_d(double d) {
  printf("d = %lf\n", d);
}

void display_s(char *s) {
  printf("s = %s\n", s);
}

typedef enum {
  int_tag,
  double_tag,
  string_tag
} Tags;

void display(Jval value, Tags tag) {
  switch (tag) {
    case int_tag:
      // display_i(jval_i(value));
      display_i(value);
      break;
    case double_tag:
      display_d(jval_d(value));
      break;
    case string_tag:
      display_s(jval_s(value));
      break;
  }
}

int main() {
  // Jval i = new_jval_i(1000);
  Jval i = { .i = 1000 };
  Jval pi = new_jval_d(3.1415);
  Jval s = new_jval_s("Hello generic world!");
  display(i, int_tag);
  display(pi, double_tag);
  display(s, string_tag);

  // 2. Cảnh báo: trách nhiệm gửi đúng tham số thuộc về người gọi
  display(i, double_tag);
  return 0;
}