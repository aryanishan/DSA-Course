#include <iostream>
using namespace std;

class abc{
  mutable int x; // mutable is used to modify the value even if it is constant but do not use mutable because it is not a good practice and it is only used for the debugging purpose.
  int *y;
  int z;
  public:
  // 
  // this constructor is old style--
  // abc(int _x, int _y, int _z = 89){
  //   x = _x;
  //   y = new int(_y);
  //   z = _z;
  // }

  // this constructor is new style or we can say it the initialization list --

  abc(int _x, int _y, int _z = 89): x(_x), y(new int(_y)), z(_z) {}

  int getX() const{
    x = 1000;
    return x;
  }

  void setX(int val){
    x = val;
  }

  int getY() const{
    return *y;
  }

  void setY(int val){
    *y = val;
  }

  int getZ() const{
    return z;
  }

};

void print(const abc &a){
  cout<<a.getX()<<" "<<a.getY()<<" "<<a.getZ()<<endl;
}

int main(){
  abc a(1,3);
  print(a);
  return 0;
}