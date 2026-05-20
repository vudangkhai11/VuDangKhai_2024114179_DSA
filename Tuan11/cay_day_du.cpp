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

void duyet_truoc(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";

    duyet_truoc(root->left);
    duyet_truoc(root->right);
}

int main() {
    Node* root = tao_Node(1);
    
    root->left = tao_Node(2);
    root->right = tao_Node(3);

    root->left->left = tao_Node(4);
    root->left->right = tao_Node(5);

    duyet_truoc(root);

    return 0;
}