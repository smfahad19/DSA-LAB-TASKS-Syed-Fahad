#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
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
        newNode->next = head;
        head = newNode;
    }

    void insert_last(int val)
    {
        Node *temp = head;
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = temp;
            return;
        }
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void specific_location(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;

        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void DeleteAt(int num)
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        if (num == 1)
        {
            head = head->next;
            delete temp;
            temp = head;
            return;
        }
        Node *prev = NULL;

        while (temp != NULL && num > 1)
        {
            prev = temp;
            temp = temp->next;
            num--;
        }

        if (temp == NULL)
        {
            cout << "big number" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;

        return;
    }

    void Delete_first()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

   void deleteCenterNode()
    {
        if (head == nullptr || head->next == nullptr)
        {
            cout << "small List" << endl;
            return;
        }
        Node *cur = head;
        Node *mov = head;
        Node *pre = nullptr;

        while (mov != nullptr && mov->next != nullptr)
        {
            mov = mov->next->next;
            pre = cur;
            cur = cur->next;
        }

        pre->next = cur->next;
        delete cur;
    }


    void Delete_last()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
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
};

int main()
{
    linked_list ll;
    ll.insert_first(2);
    ll.insert_first(3);
    ll.insert_last(4);
    ll.specific_location(3, 1);
    // ll.deleteCenterNode();
    // ll.DeleteAt(1);
    // ll.Delete_first();
    // ll.Delete_last();
    ll.display();
}


