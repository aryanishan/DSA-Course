#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(){
      data = 0;
      next = NULL;
    }

    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

Node* reverse(Node* head){
  Node* prev = NULL;
  Node* curr = head;
  Node* next = NULL;

  while(curr != NULL){
    next = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

bool checkPalindrome(Node* head){
  if(head == NULL || head -> next == NULL){
    return true;
  }

  Node* slow = head;
  Node* fast = head -> next;

  while(fast != NULL){
    fast = fast -> next;
    if(fast != NULL){
      fast = fast -> next;
      slow = slow -> next;
    }
  }

  Node* reversedNode = reverse(slow -> next);
  slow -> next = reversedNode;
  Node* temp1 = head;
  Node* temp2 = reversedNode;

  while(temp2 != NULL){
    if(temp1 -> data != temp2 -> data){
      return false;
    }
    temp1 = temp1 -> next;
    temp2 = temp2 -> next;
  }

  return true;
}

int main(){
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(20);
  Node* fifth = new Node(11);

  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = NULL;

  bool ispalidrome = checkPalindrome(head);
  if(ispalidrome){
    cout<<"Linked list is palindrome"<<endl;
  }else{
    cout<<"Linked list is not palindrome"<<endl;
  }

  return 0;
}