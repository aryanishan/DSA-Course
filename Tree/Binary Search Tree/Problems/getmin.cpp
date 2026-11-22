#include <bits/stdc++.h>
using namespace std;

class Node{
  public :
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }
};

Node* buildBST(Node* root, int val){
  if(root == NULL){
    root = new Node(val);
    return root;
  }else{
    if(val > root -> data){
      root -> right = buildBST(root -> right, val);
    }else{
      root -> left = buildBST(root -> left, val);
    }
    return root;
  }
}

Node* createBST(Node* root){
  cout<<"Enter the value for node : ";
  int val;
  cin>>val;

  while(val != -1){
    root = buildBST(root, val);
    cout<<"Enter the value for node :";
    cin>>val;
  }

  return root;
}


int getmin(Node* root){
  if(root == NULL){
    return -1;
  }

  while(root -> left != NULL){
    root = root -> left;
  }

  return root -> data;
}

int main(){

  Node* root = NULL;
  root = createBST(root);

  cout<<getmin(root)<<endl;

  return 0;
}