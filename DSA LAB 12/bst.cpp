#include <iostream>
using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

   
};

class BST {
public:
    BSTNode* root;

    BST() {
        root = nullptr;
    }

   
    void insert(int value) {
        BSTNode* newNode = new BSTNode(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        BSTNode* current = root;

        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                } else {
                    current = current->left;
                }
            } else if (value > current->data) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                } else {
                    current = current->right;
                }
            } else {
                delete newNode;
                return;
            }
        }
    }

    void inorder(BSTNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
};

int main() {
    BST bst;
    int values[] = {30, 20, 40, 10, 25};

    for (int i = 0; i < 5; i++) {
        bst.insert(values[i]);
    }

    cout << "BST Inorder Traversal: ";
    bst.inorder(bst.root);
    cout << endl;

    return 0;
}
