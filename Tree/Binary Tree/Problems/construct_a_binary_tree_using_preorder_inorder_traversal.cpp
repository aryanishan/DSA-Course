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

int getIndex(int element, vector<int> ans){
  for(int i = 0 ; i < ans.size() ; i++){
    if(element == ans[i]){
      return i;
    }
  }
  return -1;
}

Node* buildTree(vector<int> preorder, vector<int> inorder, int &preorderindex, int inorderstart, int inorderend){
  if(preorderindex >= preorder.size()){
    return NULL;
  }
  if(inorderstart > inorderend){
    return NULL;
  }

  int element = preorder[preorderindex];
  preorderindex++;

  Node* root = new Node(element);
  int elemidx = getIndex(element, inorder);

  root->left = buildTree(preorder, inorder, preorderindex, inorderstart, elemidx - 1);
  root->right = buildTree(preorder, inorder, preorderindex, elemidx + 1, inorderend);

  return root;
}

Node* buildTree(vector<int> preorder, vector<int> inorder){
  int preorderindex = 0;
  int inorderstart = 0;
  int inorderend = inorder.size() - 1;
  Node* root = buildTree(preorder, inorder, preorderindex, inorderstart, inorderend);
  return root;
}

void print(Node* root){
  if(root == NULL){
    cout<<-1<<" ";
    return ;
  }

  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
}

int main(){
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  Node* root = buildTree(preorder, inorder);
  print(root);
  return 0;
}