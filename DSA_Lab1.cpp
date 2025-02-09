// Lab-1: Declare Variable and pointer and modifying the value of Pointer;

#include <iostream>
using namespace std;
int main(){
    int var = 10;
    int *ptr = &var;

    *ptr = 20;

    cout<<"Value of Variable = "<<var<<endl;
    cout<<"Varible address = "<<&var<<endl;
    cout<<"Address of The Pointer = "<<&ptr<<endl;
    cout<<"Address of Variable using pointer = "<<ptr<<endl;
    cout<<"value of that Variable using pinter = "<<*ptr<<endl;
}