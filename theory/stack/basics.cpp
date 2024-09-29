#include <iostream>
using namespace std;

class Stack {
    int top;        
    int *arr;       
    int maxSize;    

public:
    // Constructor with an optional size parameter
    Stack(int size = 1) {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Resize the stack to a new capacity
    void resize(int newMaxSize) {
        int *newArr = new int[newMaxSize];
        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];  // Copy elements to the new array
        }
        delete[] arr;  // Free old array memory
        arr = newArr;
        maxSize = newMaxSize;
    }

    // Push an element onto the stack, resizing if necessary
    void push(int x) {
        if (top >= maxSize - 1) {  // Resize if stack is full
            resize(maxSize + 1);
        }
        arr[++top] = x;  // Add element to the stack
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Get the current number of elements in the stack
    int getSize() {
        return top + 1;
    }
};

int main() {
    Stack s;
    cout << "\nInitial stack size: " << s.getSize();
    
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "\nStack size after pushing elements: " << s.getSize();
    
    return 0;
}
