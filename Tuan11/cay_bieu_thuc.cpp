#include<iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* tao_Node(char x) {
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
    Node* root = tao_Node('-');

   
    root->left = tao_Node('/');
    root->right = tao_Node('^');



    // ===== CÂY BÊN TRÁI =====

    root->left->left = tao_Node('+');
    root->left->right = tao_Node('d');

    root->left->left->left = tao_Node('*');
    root->left->left->right = tao_Node('c');

    root->left->left->left->left = tao_Node('a');
    root->left->left->left->right = tao_Node('b');



    // ===== CÂY BÊN PHẢI =====


    root->right->left = tao_Node('-');
    root->right->right = tao_Node('g');


    root->right->left->left = tao_Node('*');
    root->right->left->right = tao_Node('h');

    root->right->left->left->left = tao_Node('e');
    root->right->left->left->right = tao_Node('f');

    //duyet_truoc(root);
    //duyet_sau(root);
    duyet_giua(root);

    return 0;
}