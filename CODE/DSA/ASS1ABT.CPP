#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


Node *create_BT() {
    int val;
    cout<<"Enter val -:";
    cin>>val;

    if(val == -1) return NULL;
    Node *node = new Node(val);
    cout<<"Enter val for Left child OF "<<val<<endl;
    node->left = create_BT();
    cout<<"Enter val for Right child OF "<<val<<endl;
    node->right = create_BT();
    return node;
}

void inorder(Node *root) {
    if(!root) return;
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}
void preorder(Node *root) {
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int deapth(Node *root) {
        if(!root) return 0;
        int left = deapth(root->left);
        int right = deapth(root->right);
        return 1 + max(left , right);
}

void Leaf_Node(Node *root) {
    if(!root) return;
    if(!root->left && !root->right) {
        cout<< root->data<<" ";
    }
    else {
        Leaf_Node(root->left);
        Leaf_Node(root->right);
    }
}

Node *copy_Tree(Node *root) {
    if(!root) return NULL;

    Node *newNode = new Node(root->data);
    newNode->left = copy_Tree(root->left);
    newNode->right = copy_Tree(root->right);
    return newNode;
}

int main() {

    Node* root = NULL;
    Node* newRoot = NULL;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Build Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Display Depth of Tree\n";
        cout << "6. Display Leaf Nodes\n";
        cout << "7. Copy Tree\n";
        cout << "8. Inorder Traversal of Copied Tree\n";
        cout << "9. Preorder Traversal of Copied Tree\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = create_BT();
                cout << "Tree built successfully.\n";
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Depth of Binary Tree: " << deapth(root) << endl;
                break;
            case 6:
                cout << "Leaf Nodes:\n";
                Leaf_Node(root);
                break;
            case 7:
                newRoot = copy_Tree(root);
                cout << "Tree copied successfully.\n";
                break;
            case 8:
                if (newRoot) {
                    cout << "Inorder Traversal of Copied Tree: ";
                    inorder(newRoot);
                    cout << endl;
                } else {
                    cout << "Copied tree does not exist.\n";
                }
                break;
            case 9:
                if (newRoot) {
                    cout << "Preorder Traversal of Copied Tree: ";
                    preorder(newRoot);
                    cout << endl;
                } else {
                    cout << "Copied tree does not exist.\n";
                }
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);
    // cout<<"Create BT -:"<<endl;
    // Node *root = create_BT();
    // cout<<"Inorder Traversal of BT -:"<<endl;
    // inorder(root);

    // cout<<"Deapth of BT -:"<<endl;
    // cout<<deapth(root)<<endl;

    // cout<<"Leaf Nodes of BT -:"<<endl;
    // Leaf_Node(root);
}
