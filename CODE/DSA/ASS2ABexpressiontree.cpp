#include <iostream>
#include <stack>
#include <string>
#include <cctype> // For isdigit function

using namespace std;

class Node {
    public:
    string data;
    Node* left;
    Node* right;

    Node(string& val) : data(val), left(nullptr), right(nullptr) {}
};


bool isOperator(string& c) {
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

Node* constructExpressionTree(string& postfix) {
    stack<Node*> st;
    string token;
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        
        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            token = "";
       
            while (i < postfix.length() && isdigit(postfix[i])) {
                token += postfix[i];
                i++;
            }
            i--;
            st.push(new Node(token));
        }
        else {

            token = string(1, ch);
            if (isOperator(token)) {
                Node* node = new Node(token);
                node->right = st.top(); st.pop();
                node->left = st.top(); st.pop();
                st.push(node);
            }
        }
    }

    return st.top();
}


void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


void postOrderTraversal(Node* root) {
    if (root == nullptr) return;

    std::stack<Node*> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        Node* current = stack1.top();
        stack1.pop();
        stack2.push(current);

        if (current->left) stack1.push(current->left);
        if (current->right) stack1.push(current->right);
    }

    while (!stack2.empty()) {
        Node* current = stack2.top();
        stack2.pop();
        std::cout << current->data << " ";
    }
}

void preOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    std::stack<Node*> stack;
    stack.push(root);
    
    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();
        std::cout << current->data << " ";
        
        if (current->right) stack.push(current->right);
        if (current->left) stack.push(current->left);
    }
}

void inOrderTraversal(Node* root) {
    std::stack<Node*> stack;
    Node* current = root;
    
    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        
        current = stack.top();
        stack.pop();
        std::cout << current->data << " ";
        
        current = current->right;
    }
}

int main() {
    string postfix = "5 6 2 + * 12 4 / -"; 

    Node* root = constructExpressionTree(postfix);

    cout << "In-order traversal of the expression tree: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal of the expression tree: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal of the expression tree: ";
    postOrderTraversal(root);
    cout << endl;
    
    deleteTree(root);
    return 0;
}


