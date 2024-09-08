#include <iostream>
#include <climits>

using namespace std;

// Define the Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Merge function for Merge Sort
Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    
    if (left->data < right->data) {
        left->next = merge(left->next, right);
        left->next->prev = left;
        left->prev = nullptr;
        return left;
    } else {
        right->next = merge(left, right->next);
        right->next->prev = right;
        right->prev = nullptr;
        return right;
    }
}

// Function to split the list into two halves
void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;
    
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

// Merge Sort for doubly linked list
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (head == nullptr || head->next == nullptr) return;

    Node* front;
    Node* back;
    split(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = merge(front, back);
}

// Function to remove duplicates from a sorted doubly linked list
void removeDuplicates(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            if (current->next != nullptr) {
                current->next->prev = current;
            }
            delete duplicate;
        } else {
            current = current->next;
        }
    }
}

int main() {
    Node* head = nullptr;
    
    // Example: Insert some data into the list
    insertEnd(head, 5);
    insertEnd(head, 3);
    insertEnd(head, 8);
    insertEnd(head, 1);
    insertEnd(head, 3);
    insertEnd(head, 8);
    insertEnd(head, 5);
    
    cout << "Original List: ";
    printList(head);
     mergeSort(&head);

    cout << "Sorted List: ";
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;

}
