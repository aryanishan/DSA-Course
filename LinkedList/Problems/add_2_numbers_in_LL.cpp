#include <bits/stdc++.h>
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

    cout<<"Memory is free for node: "<<this -> data<<endl;
  }
};

Node* reverse(Node* &head){
  if(head == NULL){
    return head;
  }

  Node* prev = NULL;
  Node* curr = head;
  Node* forward = NULL;

  while(curr != NULL){
    forward = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = forward;
  }

  return prev;
}

Node* solve(Node* &head1, Node* &head2){
  if(head1 == NULL){
    return head2;
  }
  if(head2 == NULL){
    return head1;
  }

  head1 = reverse(head1);
  head2 = reverse(head2);

  Node* anshead = NULL;
  Node* anstail = NULL;
  int carry = 0;
  while(head1 != NULL && head2 != NULL){
    int sum = carry + head1 -> data + head2 -> data;
    int digit = sum % 10;
    carry = sum / 10;

    Node* newNode = new Node(digit);
    if(anshead == NULL){
      anshead = newNode;
      anstail = newNode;
    }else{
      anstail -> next = newNode;
      anstail = newNode;
    }
    head1 = head1 -> next;
    head2 = head2 -> next;
  }

  while(head1 != NULL){
    int sum = carry + head1 -> data;
    int digit = sum % 10;
    carry = sum / 10;

    Node* newNode = new Node(digit);
    anstail -> next = newNode;
    anstail = newNode;
    head1 = head1 -> next;
  }

  while(head2 != NULL){
    int sum = carry + head2 -> data;
    int digit = sum % 10;
    carry = sum / 10;

    Node* newNode = new Node(digit);
    anstail -> next = newNode;
    anstail = newNode;
    head2 = head2 -> next;
  }

  if(carry != 0){
    int sum = carry;
    int digit = sum % 10;
    carry = sum / 10;

    Node* newNode = new Node(digit);
    anstail -> next = newNode;
    anstail = newNode;
  }

  return reverse(anshead);
}

void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp -> data << " ";
    temp = temp -> next;
  }
}

int main(){
  Node* head1 = new Node(9);
  Node* second1 = new Node(9);
  head1 -> next = second1;

  Node* head2 = new Node(9);
  Node* second2 = new Node(9);
  Node* third2 = new Node(9);
  head2 -> next = second2;
  second2 -> next = third2;

  Node* answer = solve(head1, head2);
  print(answer);

  return 0;
}