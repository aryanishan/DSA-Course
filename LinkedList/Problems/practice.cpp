// Reverse Linked List under a range --

#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data ;
  Node* next;

  Node (){
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

Node* reverse(Node* &head, int left, int right){
  if(head == NULL){
    return head;
  }

  if(head -> next == NULL){
    return head;
  }

  Node* dummy = new Node(0);
  dummy -> next = head;
  Node* prev = dummy;

  for(int i = 0 ; i < left - 1 ; i++){
    prev = prev -> next;
  }

  Node* curr = prev -> next;

  for(int i = 0 ; i < right - left ; i++){
    Node* temp = curr -> next;
    curr -> next = temp -> next;
    temp -> next = prev -> next;
    prev -> next = temp;
  }

  return dummy -> next;
}

void print(Node* &head){
  Node* temp = head;
  
  while(temp != NULL){
    cout<<temp -> data << " ";
    temp = temp -> next;
  }
}

int main(){
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);

  head -> next = second;
  second -> next = third; 
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = NULL;

  Node* reversedLL = reverse(head, 2, 4);
  print(reversedLL);
  return 0;
}