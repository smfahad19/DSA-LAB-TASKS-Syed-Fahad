#include <iostream>
using namespace std;
class stack{
    public:
        int arr[100];
        int top;

        stack(){
            top = -1;
        }

        void push_stack(int d){
            if(top == 99){
                cout<<"stack is full ";
                return;
            }
            top++;
            arr[top] = d;
        }
        void pop_stack(){
            if(top == -1){
                cout<<"Stack is Empty ";
                return;
            }
            cout<<"Before delete -";
            cout<<arr[top]<<endl;
            cout<<"Now successfully deleted "<<arr[top] <<endl;
            arr[top] = 0;
            top--;
        }

        void display(){
            for(int i = 0; i<=top; i++){
             cout<<arr[i]<<" - ";
            }
        }
};
int main(){
    stack s;
    s.push_stack(2);
    s.push_stack(4);
    s.display();
    cout<<endl;
    s.pop_stack();
    s.display();

}