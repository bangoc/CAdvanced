#include <stdio.h>

// 1. Đếm số lượng số lẻ
//    như được định nghĩa ở
//    https://mathworld.wolfram.com/OddNumber.html
//    số có dạng 2k + 1
int count_odd(int n, int a[]) {
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) {  // Đếm vậy đúng hay sai
      ++cc;
    }
  }
  return cc;
}

// 2. Đếm số lượng số chẵn

// 3. Đếm số lượng số chia hết cho 3

// 4. Đếm số lượng số âm

// 5. Đếm số lượng số dương

int main() {
  int a[] = { -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Số lượng số lẻ bằng %d\n", count_odd(n, a));
}