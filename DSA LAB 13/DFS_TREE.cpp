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

void dfsTraversal(Node* root) {
    if (root == nullptr) return; 
    cout << root->data << " ";
    dfsTraversal(root->left);
    dfsTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    root = insertNode(root,20);
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 6);
    insertNode(root, 8);
    
    dfsTraversal(root);
    return 0;
}