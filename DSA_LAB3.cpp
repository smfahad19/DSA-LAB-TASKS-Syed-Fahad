// Lab 3 - Singly Linked List (Insert at End, Insert at Start)  

#include <iostream>
using namespace std;

class Node
{
public:
    int num;
    Node *next;

    Node(int n)
    {
        num = n;
        next = nullptr;
    }
};

class Insert_data
{
public:
    Node *head;

    Insert_data()
    {
        head = nullptr;
    }

    void insert_at_first(int num)
    {
        Node *newNode = new Node(num);
        newNode->next = head;
        head = newNode;
    }

    void insert_at_last(int num)
    {
        Node *newNode = new Node(num);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->num << " - ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main()
{
    int num, num1;
    Insert_data in;
    cout << "Enter Number To insert At first ";
    cin >> num;
    in.insert_at_first(num);
    in.display();

    cout << "Enter Number to Insert At Last ";
    cin >> num1;
    in.insert_at_last(num1);
    in.display();
}
