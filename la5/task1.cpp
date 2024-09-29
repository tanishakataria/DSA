#include <iostream>
using namespace std;

// Function to sort an array in ascending order using recursive bubble sort
void bubbleSort(int arr[], int size) {
    // Base case: if the array has only one element, it is already sorted
    if (size == 1) {
        return;
    }
    // Perform one pass of bubble sort
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    // Recursively sort the remaining elements
    bubbleSort(arr, size - 1);
}

int main() {
    int arr[] = {2, 9, 8, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Display the unsorted array
    cout << "\nUnsorted array:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }

    // Call the sorting function
    bubbleSort(arr, size);

    // Display the sorted array
    cout << "\nSorted array:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }

    return 0;
}
