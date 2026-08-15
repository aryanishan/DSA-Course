#include <bits/stdc++.h>
using namespace std;

class Node{
  public: 
  int data ;
  Node* next;

  Node() {
    this -> data = 0;
    this -> next = NULL;
  }

  Node(int data){
    this -> data = data;
    this -> next = NULL;
  }

  ~Node() {
    if(this -> next != NULL){
      delete next;
      this -> next = NULL;
    }
    cout<<"Memory is free for node with data: "<<this -> data<<endl;
  }
};


// Using unordered_set to remove duplicates from unsorted linked list--
// Node* removeDuplicates(Node* &head){
//   if(head == NULL){
//     return head;
//   }

//   unordered_set<int> seen;
//   Node* curr = head;
//   Node* prev = NULL;

//   while(curr != NULL){
//     if(seen.find(curr -> data) != seen.end()){
//       prev -> next = curr -> next;
//       curr -> next = NULL;
//       delete curr;
//       curr = prev -> next;
//     }
//     else{
//       seen.insert(curr -> data);
//       prev = curr;
//       curr = curr -> next;
//     }
//   }
//   return head;
// }

// Now Using unordered_map to remove duplicates from unsorted linked list --
Node* removeDuplicates(Node* &head){
  if(head == NULL){
    return head;
  }

  unordered_map<int, bool> seen;
  Node* curr = head;
  Node* prev = NULL;

  while(curr != NULL){
    if(seen[curr -> data] == true){
      prev -> next = curr -> next;
      Node* temp = curr;
      curr = curr -> next;
      temp -> next = NULL;
      delete temp ;
    }
    else{
      seen[curr -> data] = true;
      prev = curr;
      curr = curr -> next;
    }
  }

  return head;
}

void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp -> data<<" ";
    temp = temp -> next;
  }
}

int main(){
  Node* head = new Node(10);
  Node* second = new Node(40);
  Node* third = new Node(10);
  Node* fourth = new Node(20);
  Node* fifth = new Node(40);
  Node* sixth = new Node(30);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = NULL;

  cout<<"Before removing duplicates: ";
  print(head);
  cout<<endl;
  head = removeDuplicates(head);
  cout<<"After removing duplicates: ";
  print(head);

  return 0;
}

