#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {} // Constructor to initialize the node
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack() : top(nullptr) {}

    // Destructor to free memory when stack is destroyed
    ~Stack() {
        while (!isEmpty()) {
            pop(); // Clean up all nodes
        }
    }

    // Push a new item onto the stack
    void push(int item) {
        Node* newNode = new Node(item); // Create a new node with the item
        newNode->next = top;            // Link the new node to the current top
        top = newNode;                  // Update top to the new node
        cout << item << " pushed onto stack" << endl;
    }

    // Pop an item from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Nothing to pop" << endl;
            return -1;
        }
        Node* temp = top;        // Temporarily store the current top
        int poppedValue = temp->data; // Get the data from the top node
        top = top->next;         // Update top to the next node
        delete temp;             // Delete the old top node
        return poppedValue;
    }

    // Peek at the top item without popping it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data; // Return the data of the top node
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr; // Return true if top is null
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << stack.peek() << " is at the top of the stack" << endl;

    cout << stack.pop() << " popped from the stack" << endl;
    cout << stack.pop() << " popped from the stack" << endl;

    cout << stack.peek() << " is at the top of the stack" << endl;

    return 0;
}
