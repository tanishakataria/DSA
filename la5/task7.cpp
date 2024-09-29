#include <iostream>
using namespace std;

class Stack {
private:
    int top;        
    int capacity;  
    int* array;     

public:
    // Constructor to initialize the stack with a given size
    Stack(int size) {
        capacity = size; 
        top = -1;        
        array = new int[capacity]; 
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] array; 
    }

    // Push an item onto the stack
    void push(int item) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << item << endl;
            return;
        }
        array[++top] = item; 
        cout << item << " pushed onto stack" << endl;
    }

    // Pop an item off the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Nothing to pop" << endl;
            return -1; 
        }
        return array[top--]; 
    }

    // Get the top item without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return array[top]; 
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1; 
    }

    // Check if the stack is full
    bool isFull() {
        return top == capacity - 1; 
    }
};

int main() {
    Stack stack(5); // Create a stack with a capacity of 5

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60); // Attempt to push when the stack is full

    cout << stack.peek() << " is at the top of the stack" << endl; 

    cout << stack.pop() << " popped from the stack" << endl; 
    cout << stack.pop() << " popped from the stack" << endl; 

    cout << stack.peek() << " is at the top of the stack" << endl; 

    return 0;
}
