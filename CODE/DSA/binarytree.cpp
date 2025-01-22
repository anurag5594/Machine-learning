#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    struct Node * left;
    struct Node * right;
    Node(int val){
        data = val;
        left = right = NULL;

    }
};

void Inorder(Node*root)
{
    if(root == NULL)
        return;
    Inorder(root -> left);
    cout<<root -> data;
    Inorder(root -> right);

}

void Preorder(Node*root)
{
    if(root == NULL)
        return;
    cout<<root -> data<<""<<endl;
    Preorder(root -> left);
    Preorder(root -> right);

}

void Postorder(Node*root)
{
    Postorder(root->left);
    Postorder(root->right);
    cout<<root -> data<<""<<endl;

}

void create_tree(){
    int val;
    cout<<"Enter a value:-";
    cin>>val;

    if(val == -1) 
        return ;
    Node*node = new Node(val);
    cout<<"Enter a val of left child :- "<<endl;
    Node -> left=create_tree;

    cout<<"Enter a val of right child :- "<<endl;
    Node -> right=create_tree; 

    return Node;

}

int main(){

   cout<<"create a binary tree "<<endl;
   Node*root = create_tree;

   cout<<"Inoreder traversal binary tree";
   Inorder(root)

   cout<<"Preoder traversal binary tree";
   Preorder(root)

   cout<<"Postorder traversal binary tree";
   Postorder(root)


}
