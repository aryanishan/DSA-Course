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

Node* buildTree(){
  int val;
  cin>>val;

  if(val == -1){
    return NULL;
  }else{
    Node* root = new Node(val);
    root -> left = buildTree();
    root -> right = buildTree();
    return root;
  }
}
int maxD = 0;
int maxDepth(Node* root){
  if(root == NULL){
    return 0;
  }

  int leftH = maxDepth(root -> left);
  int rightH = maxDepth(root -> right);
  maxD = max(maxD, leftH + rightH);

  return max(rightH, leftH) + 1;
}

int diameterOfTree(Node* root){
  // if(root == NULL){
  //   return 0;
  // }

  // int n1 = maxDepth(root -> left) + maxDepth(root -> right);
  // int n2 = diameterOfTree(root -> left);
  // int n3 = diameterOfTree(root -> right);

  // int ans = max(n1, max(n2, n3));

  // return ans;

  maxDepth(root);
  return maxD;
}

int main(){
  Node* root = buildTree();

  int ans = diameterOfTree(root);

  cout<<"Maximum diameter of a tree is : "<<ans<<endl;

  return 0;
}