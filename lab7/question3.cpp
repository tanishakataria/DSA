#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
};

void insertStudent(Student*& head, const string& name, int score) {
    Student* newStudent = new Student{name, score, nullptr};
    
    if (!head) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void displayStudents(Student* head) {
    Student* temp = head;
    while (temp) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }
}

int getMaxScore(Student* head) {
    int maxScore = 0;
    Student* temp = head;
    while (temp) {
        if (temp->score > maxScore) {
            maxScore = temp->score;
        }
        temp = temp->next;
    }
    return maxScore;
}

Student* countingSort(Student* head, int exp) {
    vector<Student*> bucket[10];
    Student* temp = head;

    while (temp) {
        int digit = (temp->score / exp) % 10;
        bucket[digit].push_back(temp);
        temp = temp->next;
    }

    Student* newHead = nullptr;
    Student* tail = nullptr;
    
    for (int i = 0; i < 10; ++i) {
        for (Student* student : bucket[i]) {
            if (!newHead) {
                newHead = student;
                tail = student;
            } else {
                tail->next = student;
                tail = student;
            }
        }
    }

    if (tail)
        tail->next = nullptr;

    return newHead;
}

void radixSort(Student*& head) {
    int maxScore = getMaxScore(head);

    for (int exp = 1; maxScore / exp > 0; exp *= 10) {
        head = countingSort(head, exp);
    }
}

int main() {
    Student* head = nullptr;
    
    insertStudent(head, "Alice", 85);
    insertStudent(head, "Bob", 75);
    insertStudent(head, "Charlie", 93);
    insertStudent(head, "Daisy", 88);
    insertStudent(head, "Eve", 100);

    cout << "Before Sorting:" << endl;
    displayStudents(head);

    radixSort(head);

    cout << "\nAfter Sorting by Score:" << endl;
    displayStudents(head);

    return 0;
}
