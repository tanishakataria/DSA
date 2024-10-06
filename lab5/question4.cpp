#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1, stack2;

public:
    // Function to enqueue an element into the queue
    void enqueue(int x) {
        // Push the element into stack1
        stack1.push(x);
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        // If both stacks are empty, the queue is empty
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        // If stack2 is empty, move all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Pop the top element from stack2, which is the front of the queue
        int frontElement = stack2.top();
        stack2.pop();
        return frontElement;
    }

    // Function to get the front element of the queue without dequeueing
    int front() {
        // If both stacks are empty, the queue is empty
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        // If stack2 is empty, move all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // The front element is the top of stack2
        return stack2.top();
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // Should print 10

    cout << "Dequeued: " << q.dequeue() << endl;   // Should print 10
    cout << "Dequeued: " << q.dequeue() << endl;   // Should print 20

    q.enqueue(40);
    cout << "Front element: " << q.front() << endl; // Should print 30

    cout << "Dequeued: " << q.dequeue() << endl;   // Should print 30
    cout << "Dequeued: " << q.dequeue() << endl;   // Should print 40

    // Queue is now empty
    cout << "Dequeued: " << q.dequeue() << endl;   // Should print "Queue is empty!"

    return 0;
}
