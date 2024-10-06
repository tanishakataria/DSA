class Node {
public:
    int passengerID;
    Node* next;

    Node(int id) {
        passengerID = id;
        next = nullptr;
    }
};

class LinkedListQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add a passenger to the queue
    void enqueue(int passengerID) {
        Node* newNode = new Node(passengerID);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Passenger " << passengerID << " added to the queue." << endl;
    }

    // Function to remove a passenger from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No passengers to remove." << endl;
        } else {
            Node* temp = front;
            cout << "Passenger " << front->passengerID << " purchased the ticket and removed from queue." << endl;
            front = front->next;
            delete temp;
            if (front == nullptr) {  // If the queue becomes empty
                rear = nullptr;
            }
        }
    }

    // Function to display the current queue status
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Current queue: ";
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->passengerID << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
