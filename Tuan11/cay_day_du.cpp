#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* tao_Node(int x) {
    Node *p = new Node;

    p->data = x;
    p->left = nullptr;
    p->right = nullptr;

    return p;
}