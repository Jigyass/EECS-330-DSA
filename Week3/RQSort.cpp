#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int A[], int low, int high) {
    int pivot = A[low]; // Pivot
    int i = low, j = high;

    while (i < j) {
        // Increment i while elements are less than or equal to pivot
        do {
            i++;
        } while (A[i] <= pivot);

        // Decrement j while elements are greater than pivot
        do {
            j--;
        } while (A[j] > pivot);

        if (i < j) {
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[low], &A[j]); // Swap pivot with element at j
    return j;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex); // Sort the left subarray
        quickSort(A, partitionIndex + 1, high); // Sort the right subarray
    }
}

// Function to print an array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);
    quickSort(A, 0, n);
    cout << "Sorted array: \n";
    printArray(A, n);
    return 0;
}

