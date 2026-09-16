#include <bits/stdc++.h>
using namespace std;

class Node {
  public :
  int data;
  Node* left;
  Node* right;

  Node (int val){
    data = val;
    left = NULL;
    right = NULL;
  }
};

Node* buildTree(){
  int n;
  cin>>n;

  if(n == -1){
    return NULL;
  }else{
    Node* root = new Node(n);
    root -> left = buildTree();
    root -> right = buildTree();
    return root;
  }
}

// 10 20 30 -1 -1 40 -1 -1 50 -1 60 -1 -1

int maxDepth(Node* root){
  if(root == NULL){
    return 0;
  }

  int leftH = maxDepth(root -> left) + 1;
  int rightH = maxDepth(root -> right) + 1;
  int ans = max(leftH, rightH);

  return ans;
}

int main(){
  Node* root = buildTree();

  int val = maxDepth(root);
  cout<<"The maximum depth of the tree is : "<<val<<endl;
  return 0;
}