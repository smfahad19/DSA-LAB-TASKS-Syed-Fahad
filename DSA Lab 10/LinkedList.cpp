#include <iostream>
using namespace std;
class stack *top = nullptr;
class stack{
    public:
        int data;
        stack *next;

        stack(int val){
            data = val;
            next = nullptr;
        }

        void push_stack(int val){
            stack *newNode = new stack(val);
            newNode->next = top;
            top = newNode;
        }
        void pop_stack(){
            stack *temp = top;
            top = top->next;
            delete temp;
            temp = nullptr;
        }

        void push_start(int d){
            stack *newNode = new stack(d);
            if(top != nullptr){
                newNode->next = top;
                top = newNode;
                return;
            }

        }
        void pop_start(){
            stack *temp = top;
            top = top->next;
            delete temp;

        }
        void display(){
            stack* temp = top;
            while(temp != nullptr){
                cout<<temp->data<<" - ";
                temp = temp->next;
            }
        }

};

int main(){
    stack st(2);
    st.push_stack(22);
    st.push_stack(12);
    st.push_start(2);
    st.push_start(4);
    st.push_stack(18);
    st.pop_start();
    st.display();
}
