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
    y->height = max(chieu_cao(y->left), chieu_cao(y->right)) + 1;
    x->height = max(chieu_cao(x->left), chieu_cao(x->right)) + 1;
    return x;
}

Node* quay_trai(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(chieu_cao(x->left), chieu_cao(x->right)) + 1;
    y->height = max(chieu_cao(y->left), chieu_cao(y->right)) + 1;
    return y;
}


int main() {

    return 0;
}