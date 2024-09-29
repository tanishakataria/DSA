#include <iostream>
using namespace std;

// Function to perform binary search in a sorted array
int binarySearch(int arr[], int x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        
        // If the element is found at the middle
        if (arr[mid] == x) {
            return mid;  // Return the index where the element is found
        }

        // If the element is smaller than mid, search the left subarray
        else if (arr[mid] > x) {
            return binarySearch(arr, x, low, mid - 1);
        }

        // If the element is larger than mid, search the right subarray
        else {
            return binarySearch(arr, x, mid + 1, high);
        }
    }

    // Return -1 if the element is not present in the array
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the array
    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\n";

    // Input the element to be searched
    int x;
    cout << "\nEnter the element you want to find in the array: ";
    cin >> x;

    // Perform binary search
    int result = binarySearch(arr, x, 0, n - 1);

    // Output the result
    if (result == -1) {
        cout << "Element is not present in the array.\n";
    } else {
        cout << "Element is present at index " << result << ".\n";
    }

    return 0;
}
