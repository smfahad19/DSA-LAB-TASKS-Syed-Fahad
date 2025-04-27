#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if(rear == 99) {
            cout <<"Queue is Full\n";
            return;
        }
        if(front == -1){
            front = 0;
        } 
        rear++;
        arr[rear] = value;
    }

    void dequeue() {
        if(front == -1) {
            cout <<"Queue is Empty\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        front++;
    }

    void display() {
        if(front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue: ";
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
