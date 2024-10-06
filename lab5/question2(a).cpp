#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-') 
        return 1;
    if(op == '*' || op == '/') 
        return 2;
    if(op == '^') 
        return 3;
    return 0;
}

// Function to convert infix to postfix expression
string infix_to_postfix(string infix) {
    stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If the character is ')', pop and output until '(' is found
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // pop '(' from the stack
        }
        // If the character is an operator
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Pop all the operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";
    cout << "Infix: " << infix << endl;
    string postfix = infix_to_postfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
//Algorthim of infix to postfix operation
//Operand: Append to the output directly.
// Operator: Pop from the stack to output until the top has less precedence, then push the operator.
// Parentheses: Push opening parentheses to the stack. Pop the stack to output until a closing parenthesis is found.
