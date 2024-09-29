#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int value) : data(value), next(NULL) {}
    friend class SinglyLinkedList;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    // Method to add a new node at the end of the linked list
    void addAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method to print the linked list
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Recursive method to reverse the linked list
    Node* recursiveReverse(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node* newHead = recursiveReverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    // Public method to reverse the linked list
    void reverse() {
        head = recursiveReverse(head);
    }
};

int main() {
    SinglyLinkedList s;
    int numNodes;
    cout << "\nEnter the number of nodes to create: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        int value;
        cout << "\nEnter the value for node " << i + 1 << ": ";
        cin >> value;
        s.addAtEnd(value);
    }

    // Print the original linked list
    s.print();

    // Reverse the linked list
    s.reverse();

    // Print the reversed linked list
    s.print();

    return 0;
}
