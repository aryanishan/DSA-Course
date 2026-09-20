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

Node* buildtree(){
  int val;
  cin>>val;

  if(val == -1){
    return NULL;
  }else{
    Node* root = new Node(val);
    root -> left = buildtree();
    root -> right = buildtree();
    return root;
  }
}

Node* lca(Node* root, int p, int q){
  if(root == NULL){
    return NULL;
  }

  if(root -> data == p || root -> data == q){
    return root;
  }

  Node* leftans = lca(root -> left, p, q);
  Node* rightans = lca(root -> right, p, q);

  if(leftans != NULL && rightans != NULL){
    return root;
  }

  if(leftans != NULL){
    return leftans;
  }

  return rightans;
}

int main(){
  Node* root = buildtree();
  int p, q;
  cout<<"Enter the left data : ";
  cin>>p;
  cout<<"Enter the right data : ";
  cin>>q;
  Node* ans = lca(root, p, q);

  if(ans == NULL){
    cout<<"Invalid, there is no descendent node!..."<<endl;
  }else{
    cout<<"LCA is : "<<ans -> data<<endl;
  }

  return 0;
}