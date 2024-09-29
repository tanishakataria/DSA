#include <iostream>
using namespace std;

// Function to calculate factorial using tail recursion
int tailRecursiveFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * tailRecursiveFactorial(n - 1);
    }
}

// Function to calculate factorial using non-tail recursion
int nonTailRecursiveFactorial(int n) {
    if (n >= 1) {
        return n * nonTailRecursiveFactorial(n - 1);
    } else {
        return 1;
    }
}

int main() {
    int num;
    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    cout << "Factorial using tail recursion: " << tailRecursiveFactorial(num) << endl;
    cout << "Factorial using non-tail recursion: " << nonTailRecursiveFactorial(num) << endl;

    return 0;
}
