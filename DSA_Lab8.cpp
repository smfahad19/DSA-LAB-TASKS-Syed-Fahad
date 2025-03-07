// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         data = 0;
//         next = nullptr;
//     }
// };

// class SinglyLinkedList
// {
// public:
//     Node *head;

//     SinglyLinkedList()
//     {
//         head = nullptr;
//     }

//     void insert(int value)
//     {
//         Node *newNode = new Node();
//         newNode->data = value;
//         newNode->next = nullptr;

//         if (!head)
//         {
//             head = newNode;
//         }
//         else
//         {
//             Node *temp = head;
//             while (temp->next)
//                 temp = temp->next;
//             temp->next = newNode;
//         }
//     }

//     void print()
//     {
//         Node *temp = head;
//         while (temp)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// Node *mergeSinglyLinkedLists(Node *list1, Node *list2)
// {
//     if (list1 == nullptr)
//     {
//         return list2;
//     }
//     if (list2 == nullptr)
//     {
//         return list1;
//     }

//     if (list1->data < list2->data)
//     {
//         list1->next = mergeSinglyLinkedLists(list1->next, list2);
//         return list1;
//     }
//     else
//     {
//         list2->next = mergeSinglyLinkedLists(list1, list2->next);
//         return list2;
//     }
// }

// int main()
// {
//     SinglyLinkedList list1;
//     list1.insert(1);
//     list1.insert(3);

//     SinglyLinkedList list2;
//     list2.insert(2);
//     list2.insert(4);
//     list2.insert(6);

//     Node *mergedHead = mergeSinglyLinkedLists(list1.head, list2.head);

//     Node *temp = mergedHead;
//     while (temp)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     return 0;
// }




                                                                        // TASK 2
#include <iostream>
using namespace std;

class DNode
{
public:
    int val;
    DNode *next;
    DNode *prev;
};

class DoublyLinkedList
{
public:
    DNode *head;

    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        DNode *newNode = new DNode();
        newNode->val = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (!head)
        {
            head = newNode;
        }
        else
        {
            DNode *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void print()
    {
        DNode *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

DNode *mergeDoublyLinkedLists(DNode *list1, DNode *list2)
{
    if (list1 == nullptr){
        return list2;
    }
    if (list2 == nullptr){
        return list1;
    }

    if (list1->val < list2->val)
    {
        list1->next = mergeDoublyLinkedLists(list1->next, list2);
        if (list1->next)
        {
            list1->next->prev = list1;
        }
        return list1;
    }
    else
    {
        list2->next = mergeDoublyLinkedLists(list1, list2->next);
        if (list2->next)
        {
            list2->next->prev = list2;
        }
        return list2;
    }
}

int main()
{
    DoublyLinkedList list1;
    list1.insert(1);
    list1.insert(8);
    list1.insert(4);

    DoublyLinkedList list2;
    list2.insert(2);
    list2.insert(6);
    list2.insert(7);

    DNode *mergedHead = mergeDoublyLinkedLists(list1.head, list2.head);

    DNode *temp = mergedHead;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
