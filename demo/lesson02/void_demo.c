#include <stdio.h>

void display_i(int i) {
  printf("i = %d\n", i);
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

void display(void *data, Tags tag) {
  switch (tag) {
    case int_tag:
      display_i(*(int*)data);
      break;
    case double_tag:
      display_d(*(double*)data);
      break;
    case string_tag:
      display_s((char*)data);
      break;
  }
}

int main() {
  // 1. Truyền dữ liệu cho hàm
  int i = 1000;
  double pi = 3.1415;
  char s[] = "Hello generic world!";
  display((void*)&i, int_tag);
  display((void*)&pi, double_tag);
  display((void*)s, string_tag);

  // 2. Cảnh báo: trách nhiệm gửi đúng tham số thuộc về người gọi
  // display((void*)&i, double_tag);
  return 0;
}