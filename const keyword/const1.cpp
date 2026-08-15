#include<bits/stdc++.h>
using namespace std;

int main(){
    // const int *a = new int (10); // This is the const data with non const pointer

    // cout<<*a<<endl;

    // int b = 20;

    // a = &b;

    // cout<<*a<<endl;

    // int *const a = new int(10); // This is the const pointer with non const data

    // cout<<*a<<endl;

    // *a = 20;

    // cout<<*a<<endl;
    const int *const a = new int (10); // This is the const pointer with const data

    cout<<*a <<endl;

    
    return 0;
}