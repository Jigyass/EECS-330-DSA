#include <iostream>
using namespace std;

// Recursive helper function for binary search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (high < low) {
        return -1; // Base case: target not found
    }

    int mid = low + (high - low) / 2; // Prevent integer overflow

    if (arr[mid] == target) {
        return mid; // Target found
    } else if (arr[mid] > target) {
        return binarySearchRecursive(arr, low, mid - 1, target); // Search in left half
    } else {
        return binarySearchRecursive(arr, mid + 1, high, target); // Search in right half
    }
}

// Public binary search function that the user calls
int binarySearch(int arr[], int n, int target) {
    return binarySearchRecursive(arr, 0, n - 1, target);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example sorted array
    int target = 7; // Target value to search for
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}

