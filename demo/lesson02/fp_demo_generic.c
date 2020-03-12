#include <stdio.h>

// 1. Đếm số lượng số lẻ
//    như được định nghĩa ở
//    https://mathworld.wolfram.com/OddNumber.html
//    số có dạng 2k + 1
int abs_i(int value) {
  if (value < 0) {
    return -value;
  }
  return value;
}
int is_odd(int value) {
  if (abs_i(value) % 2 == 1) {
    return 1;
  }
  return 0;
}

int is_even(int value) {
  if (abs_i(value) % 2 == 0) {
    return 1;
  }
  return 0;
}

int is_divided3(int value) {
  if (abs_i(value) % 3 == 0) {
    return 1;
  }
  return 0;
}

int is_negative(int value) {
  if (value < 0) {
    return 1;
  }
  return 0;
}
int is_positive(int value) {
  if (value > 0) {
    return 1;
  }
  return 0;
}

typedef int (*predicate_t)(int);

int count_if(int n, int a[], predicate_t p) {
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (p(a[i])) {  // Đếm vậy đúng hay sai
      ++cc;
    }
  }
  return cc;
}

int main() {
  int a[] = { -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Số lượng số lẻ bằng %d\n", count_if(n, a, is_odd));
  printf("Số lượng số chẵn bằng %d\n", count_if(n, a, is_even));
  printf("Số lượng số chia hết cho 3 bằng %d\n", count_if(n, a, is_divided3));
  printf("Số lượng số âm bằng %d\n", count_if(n, a, is_negative));
  printf("Số lượng số dương bằng %d\n", count_if(n, a, is_positive));
}