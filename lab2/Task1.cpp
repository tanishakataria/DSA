#include<iostream>
using namespace std;

int main() {
    int *arr[3];
    int size[3];

    // Input to initialize the size of matrix
    for (int i = 0; i < 3; i++) {
        cout << "Row " << i + 1 << endl;
        cin >> size[i];
        arr[i] = new int[size[i]];
    }

    // Initialize the elements of each row
    for (int i = 0; i < 3; i++) {
        cout << "Enter the elements of row " << i + 1 << endl;
        for (int j = 0; j < size[i]; j++) {
            cin >> arr[i][j];
        }
    }

    // Print the initial array elements like a matrix
    cout << "INITIAL ARRAY ELEMENTS" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < size[i]; j++) {
            cout << arr[i][j] << " ";  // Print elements on the same line
        }
        cout << endl;  // Move to the next line after printing each row
    }

    // Resize the rows
    for (int i = 0; i < 3; i++) {
        int newsize = 10;
        int *newrow = new int[newsize];

        // Copy old data to new row
        for (int j = 0; j < size[i] && j < newsize; j++) {
            newrow[j] = arr[i][j];
        }

        // Initialize extra elements with zero
        for (int j = size[i]; j < newsize; j++) {
            newrow[j] = 0;
        }

        // Delete old row memory
        delete[] arr[i];

        // Update new size and row pointer
        arr[i] = newrow;
        size[i] = newsize;
    }

    // Print the resized array elements like a matrix
    cout << "RESIZED ARRAY ELEMENTS" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < size[i]; j++) {
            cout << arr[i][j] << " ";  // Print elements on the same line
        }
        cout << endl;  // Move to the next line after printing each row
    }

    // Deallocate memory
    for (int i = 0; i < 3; i++) {
        delete[] arr[i];
    }

    return 0;
}
