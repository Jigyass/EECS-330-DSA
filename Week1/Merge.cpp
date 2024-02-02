#include <stdio.h>

// Function prototypes
void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main() {
  int array[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6 };
  int length = 10;

  merge_sort(array, length);

  // Print sorted array
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  
  return 0;
}

// Initiates merge sort
void merge_sort(int a[], int length) {
  merge_sort_recursion(a, 0, length - 1);
}

// Recursive merge sort function
void merge_sort_recursion(int a[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);
    merge_sorted_arrays(a, l, m, r);
  }
}

// Merges two sorted subarrays
void merge_sorted_arrays(int a[], int l, int m, int r) {
  int left_length = m - l + 1;
  int right_length = r - m;

  // Temporary arrays
  int temp_left[left_length], temp_right[right_length];

  // Copy data to temp arrays
  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];
  for (int j = 0; j < right_length; j++)
    temp_right[j] = a[m + 1 + j];

  // Merge temp arrays back into a
  int i = 0, j = 0, k = l;
  while (i < left_length && j < right_length) {
    if (temp_left[i] <= temp_right[j]) {
      a[k] = temp_left[i++];
    } else {
      a[k] = temp_right[j++];
    }
    k++;
  }

  // Copy remaining elements of temp_left, if any
  while (i < left_length) {
    a[k++] = temp_left[i++];
  }

  // Copy remaining elements of temp_right, if any
  while (j < right_length) {
    a[k++] = temp_right[j++];
  }
}

