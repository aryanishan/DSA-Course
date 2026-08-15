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
};

bool checkforloop(Node* &head){
  if(head == NULL){
    return false;
  };

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL){
    fast = fast -> next;

    if(fast != NULL){
      fast = fast -> next;
      slow = slow -> next;
    }

    if(slow == fast){
      return true;
    }
  }

  return false;
}

Node* startingpoint(Node* &head){
  if(head == NULL){
    return NULL;
  }

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL){
    fast = fast -> next;

    if(fast != NULL){
      fast = fast -> next;
      slow = slow -> next;
    }

    if(slow == fast){
      slow = head;
      break;
    }
  }
  while(slow != fast){
    fast = fast -> next;
    slow = slow -> next;
  }
  return slow;
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
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);
  Node* sixth = new Node(60);
  Node* seventh = new Node(70);
  Node* eighth = new Node(80);
  Node* ninth = new Node(90);

  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = seventh;
  seventh -> next = eighth;
  eighth -> next = ninth;
  ninth -> next = fourth;

  cout<<"is loop present in this linked list: "<<checkforloop(head);
  cout<<endl;

  Node* start = startingpoint(head);

  cout<<"Starting point of loop is : "<<start -> data<<endl;
  return 0;

}