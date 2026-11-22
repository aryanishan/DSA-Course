#include <bits/stdc++.h>
using namespace std;

class Node{
  public :
  int data;
  Node* left ;
  Node* right ;

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
    cout<<"Enter the value for node : ";
    cin>>val;
  }
  return root;
}

int getmax(Node* root){
  if(root == NULL){
    return -1;
  }

  while(root -> right != NULL){
    root = root -> right;
  }

  return root -> data;
}

int main(){

  Node* root = NULL;
  root = createBST(root);

  cout<<"Maximum value among all the node is : "<<getmax(root)<<endl;

  return 0;
}