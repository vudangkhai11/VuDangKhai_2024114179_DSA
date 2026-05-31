#include<iostream>
using namespace std;

struct SV {
    string ten;
    int namSinh;
};

struct Node{
    SV data;
    Node *left, *right;

    Node(SV sv) {
        data = sv;
        left = right = nullptr;
    }
};

Node* them_node_BST(Node* goc, SV sv) {
    if(goc == nullptr)
        return new Node(sv);
    if(sv.namSinh < goc->data.namSinh)
        goc->left = them_node_BST(goc->left, sv);
    else
        goc->right = them_node_BST(goc->right, sv);

    return goc;
}



int main() {

    return 0;
}
// 2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004