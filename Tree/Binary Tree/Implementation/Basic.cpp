#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

Node* buildtree(){
  int val;
  cin>>val;

  if(val == -1){
    return NULL;
  }
  else{
    Node* root = new Node(val);
    root -> left = buildtree();
    root -> right = buildtree();
    return root;
  }
}

void preOrderTraversal(Node* root){
  if(root == NULL){
    return ;
  }

  cout<<root->data<<" ";

  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
  if(root == NULL){
    return ;
  }

  inOrderTraversal(root -> left);

  cout<<root->data <<" ";

  inOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root){
  if(root == NULL){
    return ;
  }

  postOrderTraversal(root -> left);
  postOrderTraversal(root -> right);

  cout<<root -> data<<" ";
}

void levelOrderTraversal(Node* root){
  if(root == NULL){
    return ;
  }

  queue<Node* > q;

  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* front = q.front();

    q.pop();
    if(front == NULL){
      cout<<endl;

      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout<<front->data<<" ";
      if(front->left != NULL){
        q.push(front->left);
      }
      if(front->right != NULL){
        q.push(front->right);
      }
    }
  }
}

int main(){
  Node* root = buildtree();

  cout<<endl;

  cout<<"Printing Pre-Order Traversal: "<<endl;
  preOrderTraversal(root);
  cout<<endl;

  cout<<"Printing In-Order Traversal: "<<endl;
  inOrderTraversal(root);
  cout<<endl;

  cout<<"Printing Pre-Order Traversal: "<<endl;
  postOrderTraversal(root);
  cout<<endl;

  cout<<"Printing Level-Order Traversal: "<<endl;
  levelOrderTraversal(root);
  cout<<endl;

  return 0;
}