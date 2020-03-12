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
int count_odd(int n, int a[]) {
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (abs_i(a[i]) % 2 == 1) {  // Đếm vậy đúng hay sai
      ++cc;
    }
  }
  return cc;
}

// 2. Đếm số lượng số chẵn
int count_even(int n, int a[]) {
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (abs_i(a[i]) % 2 == 0) {  // Đếm vậy đúng hay sai
      ++cc;
    }
  }
  return cc;
}

// 3. Đếm số lượng số chia hết cho 3
int count_divided3(int n, int a[]) {
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (abs_i(a[i]) % 3 == 0) {  // Đếm vậy đúng hay sai
      ++cc;
    }
  }
  return cc;
}

// 4. Đếm số lượng số âm
int count_negative(int n, int a[]) {
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {  // Đếm vậy đúng hay sai
      ++cc;
    }
  }
  return cc;
}

// 5. Đếm số lượng số dương
int count_positive(int n, int a[]) {
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {  // Đếm vậy đúng hay sai
      ++cc;
    }
  }
  return cc;
}

int main() {
  int a[] = { -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Số lượng số lẻ bằng %d\n", count_odd(n, a));
  printf("Số lượng số chẵn bằng %d\n", count_even(n, a));
  printf("Số lượng số chia hết cho 3 bằng %d\n", count_divided3(n, a));
  printf("Số lượng số âm bằng %d\n", count_negative(n, a));
  printf("Số lượng số dương bằng %d\n", count_positive(n, a));
}