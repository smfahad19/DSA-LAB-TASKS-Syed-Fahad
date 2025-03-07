#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    void insertFirst(int value) {
        Node* newNode = new Node;
        newNode->val = value;
        
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertLast(int value) {
        Node* newNode = new Node;
        newNode->val = value;
        
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertNth(int value, int n) {
        if (n < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->val = value;

        if (n == 1) {
            insertFirst(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < n - 1; i++) {
            if (temp->next == head) {
                cout << "Position exceeds list size!" << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertCenter(int value) {
        if (head == nullptr) {
            insertFirst(value);
            return;
        }

        Node* cur = head;
        Node* skip = head;
        
        while (skip->next != head && skip->next->next != head) {
            skip = skip->next->next;
            cur = cur->next;
        }

        Node* newNode = new Node;
        newNode->val = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        Node* last = nullptr;
        do {
            last = temp;
            temp = temp->next;
        } while (temp != head);

        temp = last;
        do {
            cout << temp->val << " ";
            Node* prev = head;
            while (prev->next != temp) {
                prev = prev->next;
            }
            temp = prev;
        } while (temp != last);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insertFirst(1);
    list.insertLast(3);
    list.insertNth(5, 3);
    list.insertCenter(6);

    cout << "List in order: ";
    list.display();

    cout << "List in reverse order: ";
    list.displayReverse();

    return 0;
}
