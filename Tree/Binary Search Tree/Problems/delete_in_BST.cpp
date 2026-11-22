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

Node* buildBST(Node* root, int val){
  if(root == NULL){
    root = new Node(val);
    return root;
  }
  else{
    if(val > root -> data){
      root -> right = buildBST(root -> right, val);
    }
    else{
      root -> left = buildBST(root -> left, val);
    }

    return root;
  }
}

Node* createBST(Node* root){
  cout<<"Enter the value of node : ";
  int val;
  cin>>val;

  while(val != -1){
    root = buildBST(root, val);
    cout<<"Enter the value of node : ";
    cin>>val;
  }

  return root;
}

void lvlorder(Node* root){
  if(root == NULL){
    return;
  }

  queue<Node* > q;

  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* front = q.front();
    q.pop();
    if(front == NULL){
      cout<<endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      cout<<front -> data<<" ";

      if(front -> left){
        q.push(front -> left);
      }
      if(front -> right){
        q.push(front -> right);
      }
    }
  }
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

Node* deleteNode(Node* root, int key){
  if(root == NULL){
    return NULL;
  }

  if(root -> data == key){
    if(root -> left == NULL && root -> right == NULL){
      Node* temp = root;
      delete temp;
      return NULL;
    }
    if(root -> left != NULL && root -> right == NULL){
      Node* temp = root;
      Node* child = root -> left;
      temp -> left = NULL;
      delete temp;
      return child;
    }
    if(root -> left == NULL && root -> right != NULL){
      Node* temp = root;
      Node* child = root -> right;
      temp -> right = NULL;
      delete temp;
      return child;
    }
    if(root -> left != NULL && root -> right != NULL){
      int rval = getmax(root -> left);
      root -> data = rval;
      root -> left = deleteNode(root -> left, rval);
      return root;
    }
  }
  else{
    if(key > root -> data){
      root -> right = deleteNode(root -> right, key);
    }else{
      root -> left = deleteNode(root -> left, key);
    }
  }

  return root;
}

int main(){
  Node* root = NULL;
  root = createBST(root);

  cout<<"Level order printing the BST : "<<endl;
  lvlorder(root);

  int key;
  cout<<"Enter the node value you want to delete : ";
  cin>>key;

  deleteNode(root, key);

  cout<<"Now printing BST after deletion : "<<endl;
  lvlorder(root);

  return 0;
}