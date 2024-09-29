#include <iostream>
using namespace std;

void printFibonacci(int n, int a = 0, int b = 1) {
    if (n < 0) return; // Base case: if negative, stop
    if (n == 0) {
        cout << a << " "; // Print the first number in the sequence
        return;
    }
    if (n == 1) {
        cout << a << " " << b << " "; // Print the first two numbers in the sequence
        return;
    }

    cout << b << " "; // Print the next Fibonacci number
    printFibonacci(n - 1, b, a + b); // Recursive call with updated values
}

int main() {
    int N;
    cout << "Enter the number of Fibonacci numbers to generate: ";
    cin >> N;

    cout << "The first " << N << " Fibonacci numbers are: " << endl;
    printFibonacci(N);

    return 0;
}
