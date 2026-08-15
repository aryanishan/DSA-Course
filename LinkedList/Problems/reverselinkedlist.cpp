#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(){
    this->data = 0;
    this->next = NULL;
  }

  Node(int data){
    this->data = data;
    this->next = NULL;
  }

  ~Node(){
    int value = this->data;
    // if(this->next != NULL){
    //   delete next;
    //   this->next = NULL;
    // }
    cout<<"Memory is free for node with data "<<value<<endl;
  }
};

Node* reverselinkedlist(Node* &previous, Node* &current){
  if(current == NULL){
    return previous;
  }
  Node* forward = current -> next;
  current -> next = previous;

  return reverselinkedlist(current, forward);
}

void insertAtTail(Node* &head, Node* &tail, int data){
  if(head == NULL){
    Node* temp = new Node(data);
    head = temp;
    tail = temp;
    return ;
  }
  Node* temp = new Node(data);
  tail->next = temp;
  tail = temp;

}

void insertAtHead(Node* &head, Node* &tail, int data){
  if(head == NULL){
    Node* temp = new Node(data);
    head = temp;
    tail = temp;
    return;
  }
  Node* temp = new Node(data);
  temp->next = head;
  head = temp;
}

int findLength(Node* &head){
  int len = 0;
  Node* temp = head;
  while(temp != NULL){
    len++;
    temp = temp->next;
  }
  return len;
}

void insertAtPosition(int data, Node* &head, Node* &tail, int pos){
  if(head == NULL){
    Node* temp = new Node(data);
    head = temp;
    tail = temp;
    return ;
  }

  if(pos == 1){
    insertAtHead(head, tail, data);
    return ;
  }

  int len = findLength(head);

  if(pos >= len){
    insertAtTail(head, tail, data);
    return ;
  }

  int i = 1;
  Node* prev = head;
  while(i < pos){
    prev = prev->next;
    i++;
  }

  Node* curr = prev->next;

  Node* temp = new Node(data);

  temp->next = curr;
  prev->next = temp;

}

void print(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

void deleteNode(int pos, Node* &head, Node* &tail){
  if(head == NULL){
    cout<<"LL is empty, cannot delete"<<endl;
    return;
  }

  if(pos == 1){
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
    return;
  }

  int len = findLength(head);

  
  if(pos == len){
    int i = 1;
    Node* prev = head;
  
    while(i < pos - 1){
      prev = prev -> next;
      i++;
    }

    Node* temp = head;
    prev -> next = NULL;
    tail = prev;
    delete temp;
    return ;
  }

  Node* prev = head;

  int i = 1;

  while(i < pos - 1){
    prev = prev -> next;
    i++;
  }

  Node* curr = prev -> next;
  prev -> next = curr -> next;
  curr -> next = NULL;
  delete curr;
}

Node* reverseloop(Node* &head){
  Node* prev = NULL;
  Node* curr = head;

  while(curr != NULL){
    Node* forward = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = forward;
  }

  return prev;
}

int main(){
  Node* head = NULL;
  Node* tail = NULL;
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 30);
  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 50);

  insertAtTail(head, tail, 10);

  // cout<<"Printing the linked list : "<<endl;
  // print(head);
  // cout<<endl;

  // insertAtPosition(25, head, tail, 5);

  // cout<<"Printing the head: "<<head->data<<endl;
  // cout<<"Printing the tail: "<<tail->data<<endl;

  // cout<<"Printing the linked list : "<<endl;
  // print(head);
  // cout<<endl;

  // deleteNode(4, head, tail);

  // cout<<"Printing the head: "<<head->data<<endl;

  print(head);
  cout<<endl;
  Node* previous = NULL;
  Node* current = head;
  head = reverselinkedlist(previous, current);
  print(head);

  cout<<endl;


  head = reverseloop(head);
  print(head);
  return 0;
}