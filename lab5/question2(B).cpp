#include <algorithm>  // For reverse
#include <cctype>     // For isalnum

// Function to reverse a string and swap parentheses
string reverse_and_swap(string expr) {
    reverse(expr.begin(), expr.end());
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            expr[i] = ')';
        } else if (expr[i] == ')') {
            expr[i] = '(';
        }
    }
    return expr;
}

// Function to convert infix to prefix expression
string infix_to_prefix(string infix) {
    // Step 1: Reverse the infix expression and swap parentheses
    string reversed_infix = reverse_and_swap(infix);

    // Step 2: Get postfix of the reversed expression
    string reversed_postfix = infix_to_postfix(reversed_infix);

    // Step 3: Reverse the postfix to get prefix
    reverse(reversed_postfix.begin(), reversed_postfix.end());
    return reversed_postfix;
}

int main() {
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";
    cout << "Infix: " << infix << endl;
    
    // Testing infix to postfix conversion
    string postfix = infix_to_postfix(infix);
    cout << "Postfix: " << postfix << endl;

    // Testing infix to prefix conversion
    string prefix = infix_to_prefix(infix);
    cout << "Prefix: " << prefix << endl;

    return 0;
}
//Reverse the input string.
// Swap parentheses ( with ).
// Convert the reversed infix to postfix.
// Reverse the postfix result to get the prefix expression.
