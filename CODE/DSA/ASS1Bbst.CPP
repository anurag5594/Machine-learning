#include<iostream>
// #include<bits/stdc++.h>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

Node *create_BST() {
    int val;
    cout<<"Enter val -:";
    cin>>val;

    if(val == -1) return NULL;
    Node *node = new Node(val);
    cout<<"Enter val for Left child less than "<<node->data<<endl;
    node->left = create_BST();
    cout<<"Enter val for Right child greater than"<<node->data<<endl;
    node->right = create_BST();
    return node;
}

void BFS(Node *root) {
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node *temp = q.front();
            q.pop();

            cout<<temp->data<<" ";

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

        }
        cout<<endl;
    }
}

bool search(Node *root , int val) {
    if(!root) return false;
    if(root->data == val) return true;
    else if(root->data > val) {
        if(search(root->left , val)) return true;
    }
    else {
        if(search(root->right , val)) return true;
    }
    return false;
}

    Node* deleteLeafNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->data) {
            root->left = deleteLeafNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteLeafNode(root->right, key);
        } else {
            // Node found
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
        }
        return root;
    }


int main() {
    Node* root = NULL;
    Node* newRoot = NULL;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Build Binery Search Tree\n";
        cout << "2. BFS of Tree\n";
        cout << "3. Search Node in Tree\n";
        cout << "4. Insert val into Tree\n";
        cout << "5. Delete leaf Node of Tree\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = create_BST();
                cout << "Tree built successfully.\n";
                break;
            case 2:
                cout << "Breadth First Traversal of Binary Search Tree: "<< endl;
                BFS(root);
                break;
            case 3:
                int val_search;
                cout << "Enter Node val to search in Tree:\n";
                cin>>val_search;
                if(search(root , val_search)) {
                    cout<<val_search<<" is Present in BST"<<endl;
                }
                else {
                    cout<<val_search<<" is Not Present in BST"<<endl;
                }
                break;
            case 4:
                int val_insert;
                cout << "Enter val to Insert in Tree.\n";
                cin>>val_insert;
                insert(root , val_insert);
                break;
            case 5:
                int val_leaf;
                cout<<"Enter leaf node val to delete";
                cin>>val_leaf;
                deleteLeafNode(root , val_leaf);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    // cout<<"Create a BST "<<endl;
    // Node *root = create_BST();

    // cout<<"Level Wise Traversal -:"<<endl;
    // BFS(root);

    // int to_find;
    // cout<<"Enter val to find in BST"<<endl;
    // cin>>to_find;

    // if(search(root , to_find)) {
    //     cout<<to_find<<" is Present in BST"<<endl;
    // }
    // else {
    //     cout<<to_find<<" is Not Present in BST"<<endl;
    // }
}