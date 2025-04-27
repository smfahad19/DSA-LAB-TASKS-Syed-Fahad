#include <iostream>
using namespace std;
class queue;
class queue *first = nullptr;
class queue *last = nullptr;
class queue{
    public:
        int data;
        queue *next;

        queue() {
            data = 0;
            next = nullptr;
        }
    queue(int val){
        data = val;
        next = nullptr;
    }

    void enqueue(int val){
        queue *newNode = new queue(val);

        if(first == nullptr && last == nullptr){
          first = last = newNode;
          return;
        }

    last->next = newNode;
    last = newNode;
    }

    void dequeue(){
        if(first == nullptr && last == nullptr){
            cout<<"Empty list! noo deletion perform";
            return;
        }
        queue *temp = first;
        first = first->next;
        delete temp;
    }

    void display(){
        queue *temp = first;

        while(temp != nullptr){
            cout<<temp->data<<" - ";
            temp = temp->next;
        }
    }

};


int main(){

    queue q;
    q.enqueue(3);
    q.enqueue(2);
    q.display();
    cout<<endl;
    cout<<"AFter Dequeue the Number "<<endl;
    q.dequeue();
    q.display();
}