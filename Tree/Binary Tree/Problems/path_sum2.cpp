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

Node *buildtree(){
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

void solve(Node* root, int target, int sum, vector<int> temp, vector<vector<int>>& ans){
  if(root == NULL){
    return ;
  }

  sum = sum + root -> data;
  temp.push_back(root->data);

  if(root -> left == NULL || root -> right == NULL){
    if(sum == target){
      ans.push_back(temp);
      return ;
    }
  }

  solve(root->left, target, sum, temp, ans);
  solve(root->right, target, sum, temp, ans);

  temp.pop_back();
}

vector<vector<int>> pathsum(Node* root, int target){
  int sum = 0;
  vector<int> temp;
  vector<vector<int>> ans;
  solve(root, target, sum, temp, ans);
  return ans;
}

int main(){
  Node* root = buildtree();
  int target;
  cout<<"Enter the value of target : ";
  cin>>target;
  vector<vector<int>> result = pathsum(root, target);

  for(int i = 0 ; i < result.size(); i++){
    for(int j = 0 ; j < result[0].size(); j++){
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}