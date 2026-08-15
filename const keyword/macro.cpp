#include <iostream>
using namespace std;

#define PI 3.14

float circle(float val){
  return PI * val * val;
}

int main(){
  
  cout<<circle(21)<<endl;

  return 0;
}