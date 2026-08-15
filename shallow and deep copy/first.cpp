#include<iostream>
#include<cstdio>
using namespace std;

class abc{
  public:
  int x;
  int *y;

  abc(int _x, int _y) : x(_x), y(new int(_y)) {}

  // This is basically known as deep copy, now it took the value of a's y and put it on a different location and then points it to b. 
  abc(const abc &a){
    x = a.x;
    y = new int(*a.y);
  }

  void print() const{
    cout << "X: " << x << ", Y: " << y << ", Content of Y: " << *y;
  }
};

int main(){
  abc a(10, 20);
  a.print();

  abc b = a; // it calls the copy constructor which is like a dumb copy constructor and that is also known as shallow copy--
  cout<<endl;
  b.print();

  *b.y = 99;
  cout<<endl;
  b.print();
  cout<<endl;
  a.print();

  return 0;
}