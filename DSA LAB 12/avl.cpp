#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    int height;
    
    TreeNode(int val) {
        value = val;
        left = right = nullptr;
        height = 1;
    }
};

class SimpleAVL {
private:
    TreeNode* root;
    
    int nodeHeight(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        return node->height;
    }
    
    int checkBalance(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        return nodeHeight(node->left) - nodeHeight(node->right);
    }
    
    TreeNode* rotateLeft(TreeNode* node) {
        TreeNode* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        
        node->height = max(nodeHeight(node->left), nodeHeight(node->right)) + 1;
        newRoot->height = max(nodeHeight(newRoot->left), nodeHeight(newRoot->right)) + 1;
        
        return newRoot;
    }
    
    TreeNode* rotateRight(TreeNode* node) {
        TreeNode* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        
        node->height = max(nodeHeight(node->left), nodeHeight(node->right)) + 1;
        newRoot->height = max(nodeHeight(newRoot->left), nodeHeight(newRoot->right)) + 1;
        
        return newRoot;
    }
    
    TreeNode* insertValue(TreeNode* node, int val) {
        if(node == nullptr) {
            return new TreeNode(val);
        }
        
        if(val < node->value) {
            node->left = insertValue(node->left, val);
        }
        else if(val > node->value) {
            node->right = insertValue(node->right, val);
        }
        else {
            return node;
        }
        
        node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));
        
        int balance = checkBalance(node);
        
        if(balance > 1 && val < node->left->value) {
            return rotateRight(node);
        }
        
        if(balance < -1 && val > node->right->value) {
            return rotateLeft(node);
        }
        
        if(balance > 1 && val > node->left->value) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        
        if(balance < -1 && val < node->right->value) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        
        return node;
    }
    
    void printTree(TreeNode* node) {
        if(node == nullptr) {
            return;
        }
        printTree(node->left);
        cout << node->value << " ";
        printTree(node->right);
    }
    
public:
    SimpleAVL() { 
        root = nullptr; 
    }
    
    void insert(int val) {
        root = insertValue(root, val);
    }
    
    void display() {
        cout << "Tree contents: ";
        printTree(root);
        cout << endl;
    }
};

int main() {
    SimpleAVL tree;
    
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    
    tree.display();
    
    return 0;
}