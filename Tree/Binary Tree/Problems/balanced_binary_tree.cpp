#include <bits/stdc++.h>
using namespace std;

class Node {
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

int getHeight(Node* root){
  if(root == NULL){
    return 0;
  }

  int leftH = getHeight(root -> left);
  int rightH = getHeight(root -> right);
  int ans = max(leftH, rightH) + 1;

  return ans;
}

bool isbalance(Node* root){
  if(root == NULL){
    return true;
  }

  int leftH = getHeight(root -> left);
  int rightH = getHeight(root -> right);
  int diff =  abs(leftH - rightH);

  if(diff > 1){
    return false;
  }else{
    bool leftside = isbalance(root -> left);
    bool rightside = isbalance(root -> right);

    if(leftside == true && rightside == true){
      return true;
    }else{
      return false;
    }
  }
}

int main(){
  Node* root = buildtree();

  if(isbalance(root)){
    cout<<"The given tree is balance!"<<endl;
  }else{
    cout<<"The given tree is not balance!"<<endl;
  }
  return 0;
}