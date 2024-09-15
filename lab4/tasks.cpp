#include<iostream>
using namespace std;

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int size){
    int tmp;
    bool swapped;
    for(int i = 0; i < size; i++){
        swapped = false;
        for(int j = 0; j < (size - 1 - i); j++){
            if(arr[j + 1] < arr[j]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Function to perform selection sort on an array
void selectionSort(int arr[], int size){
    int tmp;
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            tmp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = tmp;
        }
    }
}

// Function to perform insertion sort on an array
void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform shell sort on an array
void shellSort(int arr[], int size){
    for(int gap = size / 2; gap > 0; gap /= 2){
        for(int i = gap; i < size; i++){
            int key = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > key; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
        }
    }
}

// Function to perform comb sort on an array
void combSort(int arr[], int size){
    int gap = size;
    const double shrink = 0.769;
    bool sorted = false;
    while(gap > 1){
        gap = (int)(gap * shrink);
        if(gap < 1){
            gap = 1;
            sorted = true;
        }
        for(int i = 0; i + gap < size; i++){
            if(arr[i + gap] < arr[i]){
                int tmp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = tmp;
                sorted = false;
            }
        }
    }
}

// Function to perform linear search in an array
int linearSearch(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target){
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

// Function to perform interpolation search on a sorted array
int interpolationSearch(int arr[], int size, int target){
    int low = 0;
    int high = size - 1;
    while(low <= high && target >= arr[low] && target <= arr[high]){
        if(low == high){
            if(arr[low] == target){
                return low;
            }
            return -1;
        }
        int pos = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]));
        if(arr[pos] == target){
            return pos;
        }
        if(arr[pos] < target){
            low = pos + 1;
        }
        else{
            high = pos - 1;
        }
    }
    return -1;
}

// Function to print the array
void printArray(int arr[], int size){
    cout << "{";
    for(int i = 0; i < size; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << "}";
}

// Main function to demonstrate sorting and searching algorithms
int main(){
    int arr[6] = {12, 3, 4, 13, 14, 5};
    cout << "\nUnsorted Array\n";
    printArray(arr, 6);

    bubbleSort(arr, 6);
    cout << "\nArray Sorted by Bubble Sort\n";
    printArray(arr, 6);

    selectionSort(arr, 6);
    cout << "\nArray Sorted by Selection Sort\n";
    printArray(arr, 6);

    insertionSort(arr, 6);
    cout << "\nArray Sorted by Insertion Sort\n";
    printArray(arr, 6);

    shellSort(arr, 6);
    cout << "\nArray Sorted by Shell Sort\n";
    printArray(arr, 6);

    combSort(arr, 6);
    cout << "\nArray Sorted by Comb Sort\n";
    printArray(arr, 6);

    cout << "\nLinear Search\n";
    int x = linearSearch(arr, 6, 13);
    if(x == -1){
        cout << "Target not found";
    } else {
        cout << "The index is: " << x;
    }

    cout << "\nBinary Search\n";
    int y = binarySearch(arr, 6, 13);
    if(y == -1){
        cout << "Target not found";
    } else {
        cout << "The index is: " << y;
    }

    cout << "\nInterpolation Search\n";
    int z = interpolationSearch(arr, 6, 13);
    if(z == -1){
        cout << "Target not found";
    } else {
        cout << "The index is: " << z;
    }
}
