#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum value in the array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr)
        if (num > maxVal)
            maxVal = num;
    return maxVal;
}

// Counting sort based on the current digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);  // Output array
    int count[10] = {0};    // Count array for digits (0-9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count[] to reflect positions in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix sort implementation
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);  // Find the maximum number

    // Perform counting sort for each digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Function to reverse the array for descending order
void reverseArray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - i - 1]);
}

// Function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original Array:" << endl;
    displayArray(arr);

    // Sort the array in ascending order using Radix Sort
    radixSort(arr);
    cout << "\nArray Sorted in Ascending Order:" << endl;
    displayArray(arr);

    // Reverse the array to sort in descending order
    reverseArray(arr);
    cout << "\nArray Sorted in Descending Order:" << endl;
    displayArray(arr);

    return 0;
}
