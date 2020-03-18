#include <stdio.h>

/*Displays the array, passed to this method*/
void display(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}