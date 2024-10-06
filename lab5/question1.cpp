#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> mainStack, evenStack, oddStack;

    // Let's assume these are the n elements in the main stack
    mainStack.push(1);
    mainStack.push(2);
    mainStack.push(3);
    mainStack.push(4);
    mainStack.push(5);

    // Separate even and odd values
    while (!mainStack.empty()) {
        int value = mainStack.top();
        mainStack.pop();
        
        if (value % 2 == 0) {
            evenStack.push(value);
        } else {
            oddStack.push(value);
        }
    }

    // Display even stack
    cout << "Even Stack: ";
    while (!evenStack.empty()) {
        cout << evenStack.top() << " ";
        evenStack.pop();
    }
    cout << endl;

    // Display odd stack
    cout << "Odd Stack: ";
    while (!oddStack.empty()) {
        cout << oddStack.top() << " ";
        oddStack.pop();
    }
    cout << endl;

    return 0;
}
