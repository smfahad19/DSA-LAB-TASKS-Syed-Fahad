#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class linked_list
{
public:
    Node *head;

    linked_list()
    {
        head = nullptr;
    }

    void insert_first(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insert_last(int val)
    {
        Node *newNode = new Node(val);
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
        newNode->prev = temp;
    }

    void specific_location(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos == 1)
        {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " - ";
            temp = temp->next;
        }
        cout << endl;
    }

    void display_reverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        while (temp != nullptr)
        {
            cout << temp->data << " <---> ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    linked_list ll;
    ll.insert_first(2);
    ll.insert_first(3);
    ll.insert_last(4);
    ll.specific_location(5, 2);
    ll.display();
    ll.display_reverse();
    
    
}
