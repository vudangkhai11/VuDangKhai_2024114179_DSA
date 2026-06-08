#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
    int height;
};

int chieu_cao(Node* n) {
    return n ? n->height : 0;
}

Node* new_Node(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

Node* quay_phai(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}



int main() {

    return 0;
}