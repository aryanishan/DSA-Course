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
    }else{
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

void preorder(Node* root){
  if(root == NULL){
    return ;
  }

  cout<<root -> data << " ";
  preorder(root -> left);
  preorder(root -> right);
}

void inorder(Node* root){
  if(root == NULL){
    return ;
  }

  inorder(root -> left);
  cout<<root -> data<< " ";
  inorder(root -> right);
}

void postorder(Node* root){
  if(root == NULL){
    return ;
  }

  postorder(root -> left);
  postorder(root -> right);
  cout<<root -> data<<" ";
}

void lvlorder(Node* root){
  queue<Node*> q;
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
      cout<<front -> data <<" ";  
      if(front -> left){
        q.push(front -> left);
      }
      if(front -> right){
        q.push(front -> right);
      }
    }
  }
}

int main(){
  Node* root = NULL;

  root = createBST(root);

  cout<<"Printing preorder : "<<endl;
  preorder(root);

  cout<<endl<<"Inorder preorder : "<<endl;
  inorder(root);

  cout<<endl<<"Printing postorder : "<<endl;
  postorder(root);

  cout<<endl<<"Printing level order : "<<endl;
  lvlorder(root);
  return 0;
}