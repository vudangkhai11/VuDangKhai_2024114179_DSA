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

void duyet_truoc(Node* root) { // root -> left -> right
    if (root == nullptr)
        return;

    cout << root->data << " ";

    duyet_truoc(root->left);
    duyet_truoc(root->right);
}

void duyet_giua(Node* root) { // left -> root -> right
    if (root == nullptr)
        return;
    
    duyet_giua(root->left);

    cout << root->data << " ";

    duyet_giua(root->right);
}

void duyet_sau(Node* root) { // left -> right -> root
    if (root == nullptr)
        return;
    
    duyet_sau(root->left);
    duyet_sau(root->right);

    cout << root->data << " ";
}

int main() {
    Node* root = tao_Node(1);
    
    root->left = tao_Node(2);
    root->right = tao_Node(3);

    root->left->left = tao_Node(4);
    root->left->right = tao_Node(5);

    //duyet_truoc(root);
    //duyet_giua(root);
    //duyet_sau(root);

    return 0;
}