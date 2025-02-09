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

class linked_List
{
public:
    Node *head;

    linked_List()
    {
        head = nullptr;
    }

    void insert_at_position(int val, int pos)
    {
        Node *newNode = new Node(val);

        if (pos <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        int count = 1;

        while (temp != nullptr && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    linked_List ll;
    int pos, range, num;

    cout << "How Many Positions Do You Want to Enter: ";
    cin >> range;

    for (int i = 1; i <= range; i++)
    {
        cout << "Enter Position: ";
        cin >> pos;
        cout << "Enter Number: ";
        cin >> num;

        ll.insert_at_position(num, pos);
    }

    ll.display();

    return 0;
}
