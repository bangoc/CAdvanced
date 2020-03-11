#include <stdio.h>

// Khai báo hàm,
int fi() {
  return 100;
}
int *fip() {
  return 0;
}
int (*pfi)(); // 1
int (*apfi[3])(int *x, int *y); // 2

int (*fpfi(int (*)(long), int))(int, int); // 1

// Định nghĩa (đặt tên) kiểu
// typedef T type_ident;
// type_ident D;
typedef int fi_t(int, int); // 1
typedef int (*pfi_t)(int, int); // 2
typedef int fil_t(long); // 3
typedef int (*pfil_t)(long); // 4
int sum(int x, int y) {
  return 20;
}
int fil(long x) {
  return 1000;
}
fi_t *fpfi2(fil_t* p1, int p2) {
  printf("%s called with %d\n", __func__, p2);
  return sum;
}
pfi_t fpfi3(pfil_t p1, int p2) {
  printf("%s called with %d\n", __func__, p2);
  return sum;
}

int (*(*pfpfi2)(int (*)(long), int))(int, int);// 1
pfi_t (*pfpfi3)(pfil_t, int);                // vs 2

typedef pfi_t (*pfpfi_t)(pfil_t, int);

int main() {
  int (*pf)(int, int);

  pf = fpfi2(fil, 200);
  pf = fpfi3(fil, 300);

  pfpfi_t pfpfi2 = fpfi2;
  pf = pfpfi2(fil, 500);
  pfpfi_t pfpfi3 = fpfi3;
  pf = pfpfi3(fil, 600);

  pfpfi_t apfpfi[2] = {fpfi2, fpfi3};
  for (int i = 0; i < 2; ++i) {
    apfpfi[i](fil, (i + 1) * 1000);
  }
  pfpfi2 = fpfi2;
  pfpfi3 = fpfi3;
  pf = pfpfi2(fil, 20000);
  pf = pfpfi3(fil, 30000);
  printf("10 + 20 = %d\n", pf(10, 20));
  return 0;
}