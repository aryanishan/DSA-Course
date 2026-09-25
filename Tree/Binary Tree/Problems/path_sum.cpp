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

bool solve(Node* root, int target, int sum){
  if(root == NULL){
    return false;
  }

  sum += root -> data;

  if(root -> left == NULL && root -> right == NULL){
    if(target == sum){
      return true;
    }else{
      return false;
    }
  }

  bool leftans = solve(root -> left, target, sum);
  bool rightans = solve(root -> right, target, sum);
  return leftans || rightans;
}

bool haspathsum(Node* root, int target){
  int sum = 0;
  bool ans = solve(root, target, sum);
  return ans;
}

int main(){
  Node* root = buildtree();
  int target;
  cout<<"Enter target sum : ";
  cin>>target;

  if(haspathsum(root, target)){
    cout<<"Target sum is in the tree!";
  }else{
    cout<<"Target sum is not in the tree!";
  }

  return 0;
}