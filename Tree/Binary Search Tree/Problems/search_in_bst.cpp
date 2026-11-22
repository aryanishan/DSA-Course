#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }
};

Node* buildBST(Node*root, int val){
  if(root == NULL){
    root = new Node(val);
    return root;
  }

  else{
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

bool searchBST(Node* root, int target){
  if(root == NULL){
    return false;
  }

  if(root -> data == target){
    return true;
  }
  else{
    if(target > root -> data){
      bool rightans = searchBST(root -> right, target);
      if(rightans == true){
        return true;
      }
    }
    if(target < root -> data){
      bool leftans = searchBST(root -> left, target);
      if(leftans == true){
        return true;
      }
    }
  }
  return false;
}

int main(){
  Node* root = NULL;
  root = createBST(root);

  int target;
  cout<<"Enter the element you want to search in BST : ";
  cin>>target;

  if(searchBST(root, target)){
    cout<<"Yes "<<target<<" is present in BST."<<endl;
  }else{
    cout<<"Not present!"<<endl;
  }
  return 0;
}