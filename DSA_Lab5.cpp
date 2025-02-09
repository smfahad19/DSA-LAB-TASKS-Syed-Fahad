#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class insert_data {
public:
    Node *head;

    insert_data() {
        head = nullptr;
    }

    void insert_at_first(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insert_at_last(int val) {
        Node *newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display_center() {
        if (head == nullptr) return;
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << " - ";
    }

    void nth_time(int val, int pos) {
        if (pos <= 0) return;
        Node *newNode = new Node(val);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " - ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void display_last() {
        if (head == nullptr) return;
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << temp->data << " - ";
    }
};

int main() {
    int num, index;
    insert_data id;
    id.insert_at_first(4);
    id.insert_at_first(3);
    id.insert_at_last(5);

    cout << "Enter index: ";
    cin >> index;
    cout << "Enter number to insert: ";
    cin >> num;
    id.nth_time(num, index);

    id.display();
    id.display_center();
    id.display_last();

    return 0;
}
