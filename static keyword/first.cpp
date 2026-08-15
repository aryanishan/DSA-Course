#include <bits/stdc++.h>
using namespace std;

class abc {
  public:
  // static int x, y;
  int x, y ;
  abc(): x(0), y(0) {}

  static void print() {
    cout<<"I am static function "<<__FUNCTION__<<endl;
  }
};

// int abc::x;
// int abc::y;

int main(){
  abc obj1;
  // abc::x = 10;
  // abc::y = 20;
  abc::print();
  abc obj2;
  // abc::x = 30;
  // abc::y = 40;

  abc::print();
  abc::print();

  return 0;
}