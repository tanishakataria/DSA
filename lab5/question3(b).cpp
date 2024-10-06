class CircularQueue {
private:
    int front, rear;
    int queue[10];
    int capacity = 10;

public:
    // Constructor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add a passenger to the queue
    void enqueue(int passengerID) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more passengers." << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % capacity;
            queue[rear] = passengerID;
            cout << "Passenger " << passengerID << " added to the queue." << endl;
        }
    }

    // Function to remove a passenger from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No passengers to remove." << endl;
        } else {
            cout << "Passenger " << queue[front] << " purchased the ticket and removed from queue." << endl;
            if (front == rear) { // Queue becomes empty after this dequeue
                front = rear = -1;
            } else {
                front = (front + 1) % capacity;
            }
        }
    }

    // Function to display the current queue status
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Current queue: ";
            int i = front;
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << queue[rear] << endl;  // Print the rear element
        }
    }
};
