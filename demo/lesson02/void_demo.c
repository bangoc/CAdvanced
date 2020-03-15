#include <stdio.h>

void display_i(void* data) {
  printf("i = %d\n", *(int*)data);
}

void display_d(void* data) {
  printf("d = %lf\n", *(double*)data);
}

void display_s(void* data) {
  printf("s = %s\n", (char*)data);
}

typedef enum {
  int_tag,
  double_tag,
  string_tag
} Tags;

struct {
  Tags tag;
  void (*handler)(void*);
} displays[] = {{int_tag, display_i}, {double_tag, display_d}, {string_tag, display_s}};

void display(void *data, Tags tag) {
  int n = sizeof(displays)/sizeof(displays[0]);
  for (int i = 0; i < n; ++i) {
    if (tag == displays[i].tag) {
      displays[i].handler(data);
      break;
    }
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