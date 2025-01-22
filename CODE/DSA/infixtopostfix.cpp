#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check the precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char &c : infix) {
        // If the character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            st.push(c);
        }
        // If the character is ')', pop and output from the stack 
        // until an '(' is encountered
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Pop the '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
