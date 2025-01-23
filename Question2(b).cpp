#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int key) {
    Node* newNode = new Node(key);
    if (!root) return newNode;

    Node* parent = nullptr;
    Node* current = root;


    while (current) {
        parent = current;
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }


    if (key < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}


void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


int height(Node* root) {
    if (!root) return 0;


    int leftHeight = height(root->left);
    int rightHeight = height(root->right);


    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int main() {
    Node* root = nullptr;


    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);


    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;


    cout << "Height of BST: " << height(root) << endl;

    return 0;
}
