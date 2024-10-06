#include <iostream>
using namespace std;

class TicketQueue {
private:
    int front, rear;
    int queue[10];
    int capacity = 10;  // Queue capacity

public:
    // Constructor
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Function to add a passenger to the queue
    void enqueue(int passengerID) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more passengers." << endl;
        } else {
            if (isEmpty()) {
                front = 0;  // Set front to 0 when queue is initially empty
            }
            queue[++rear] = passengerID;
            cout << "Passenger " << passengerID << " added to the queue." << endl;
        }
    }

    // Function to remove a passenger from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No passengers to remove." << endl;
        } else {
            cout << "Passenger " << queue[front++] << " purchased the ticket and removed from queue." << endl;
            if (front > rear) {
                front = rear = -1;  // Reset the queue when all passengers are removed
            }
        }
    }

    // Function to display the current queue status
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Current queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TicketQueue tq;

    // Adding 10 passengers to the queue
    for (int i = 1; i <= 10; i++) {
        tq.enqueue(i);
    }

    tq.displayQueue();

    // Removing the first 5 passengers
    for (int i = 0; i < 5; i++) {
        tq.dequeue();
    }

    tq.displayQueue();

    // Attempting to add 5 more passengers
    for (int i = 11; i <= 15; i++) {
        tq.enqueue(i);
    }

    tq.displayQueue();

    return 0;
}
