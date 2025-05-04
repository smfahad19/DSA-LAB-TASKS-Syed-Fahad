#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* node, int value) {
    if (node == nullptr) {
        return createNode(value);
    }
    
    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else {
        node->right = insertNode(node->right, value);
    }
    
    return node;
}

void bfsTraversal(Node* root) {
    if (root == nullptr) return;
    
    Node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        Node* current = queue[front++];
        cout << current->data << " ";
        
        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }
        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    bfsTraversal(root);
    return 0;
}