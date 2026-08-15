#include<bits/stdc++.h>
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
};

bool isCircular(Node* &head){
  if(head == NULL){
    return true;
  }

  Node* temp = head -> next;

  while(temp != NULL && temp != head){
    temp = temp -> next;
  }

  if(temp == head){
    return true;
  }

  return false;
}

void print(Node* &head){
  Node* temp = head;

  do{
    cout<<temp -> data<<" ";
    temp = temp -> next;
  }while(temp != head);
}

int main(){
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);

  head -> next = second ;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = NULL;

  // print(head);
  cout<<endl;

  if(isCircular(head)){
    cout<<"Linked List is circular"<<endl;
  }
  else{
    cout<<"Linked List is not circular"<<endl;
  }
  return 0;
}