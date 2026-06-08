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

int getBalance(Node* n) {
    return n ? chieu_cao(n->left) - chieu_cao(n->right) : 0;
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

Node* chen_giatri(Node* node, int key) {
    if (!node)
        return new_Node(key);

    if (key < node->key)
        node->left = chen_giatri(node->left, key);
    else if (key > node->key)
        node->right = chen_giatri(node->right, key);
    else
        return node;

    node->height = max(chieu_cao(node->left), chieu_cao(node->right)) + 1;

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && key < node->left->key)
        return quay_phai(node);

    // Right Right
    if (balance < -1 && key > node->right->key)
        return quay_trai(node);

    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = quay_trai(node->left);
        return quay_phai(node);
    }

    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = quay_phai(node->right);
        return quay_trai(node);
    }

    return node;
}

int main() {

    return 0;
}