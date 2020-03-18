
/*Swap function to swap two values*/
void swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}

/*Partition method which selects a pivot
  and places each element which is less than the pivot value to its left
  and the elements greater than the pivot value to its right
  arr[] --- array to be partitioned
  lower --- lower index
  upper --- upper index
*/
int partition(int arr[], int lower, int upper) {
  int i = (lower - 1);
  int pivot = arr[upper]; // Selects last element as the pivot value
  int j;
  for (j = lower; j < upper; j++) {
    if (arr[j] <= pivot) { // if current element is smaller than the pivot
      i++; // increment the index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[upper]); // places the last element i.e, the pivot to its correct position
  return (i + 1);
}

/*This is where the sorting of the array takes place
  arr[] --- Array to be sorted
  lower --- Starting index
  upper --- Ending index
*/
void quickSort(int arr[], int lower, int upper) {
  if (upper > lower) {
    // partitioning index is returned by the partition method , partition element is at its correct poition
    int partitionIndex = partition(arr, lower, upper);
    // Sorting elements before and after the partition index
    quickSort(arr, lower, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, upper);
  }
}