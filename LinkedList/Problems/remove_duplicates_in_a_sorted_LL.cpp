# include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(){
    this -> data = 0;
    this -> next = NULL;
  }

  Node(int data){
    this -> data = data;
    this -> next = NULL;
  }

  ~Node(){
    if(this -> next != NULL){
      delete next;
      this -> next = NULL;
    }
    cout<<"Memory is free for node with data: "<<this -> data<<endl;
  }
};

void remove(Node* &head){
  if(head == NULL){
    return;
  }
  if(head -> next == NULL){
    return ;
  }

  Node* curr = head;

  while(curr != NULL){
    if((curr -> next != NULL) && (curr -> data == curr -> next -> data)){
      Node* temp = curr -> next;
      curr -> next = curr -> next -> next;
      temp -> next = NULL;
      delete temp;
    }
    else{
      curr = curr -> next;
    }
  }
}

void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp -> data<<" ";
    temp = temp -> next;
  }
}

int main(){

  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(2);
  Node* fourth = new Node(3);
  Node* fifth = new Node(4);
  Node* sixth = new Node(4);

  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = NULL;

  cout<<"Before removing duplicates: "<<endl;
  print(head);
  cout<<endl;
  cout<<"After removing duplicates: "<<endl;
  remove(head);
  print(head);
  return 0;
}