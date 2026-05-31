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

// Tìm và in tất cả sinh viên sinh năm x
void tim_SV(Node* goc, int x) {
    if(goc == nullptr) return;

    if(x < goc->data.namSinh) tim_SV(goc->left, x);
    else if (x > goc->data.namSinh) tim_SV(goc->right, x);
    else {
        cout << goc->data.ten << " - " << goc->data.namSinh << endl;
        tim_SV(goc->right, x);
    }
}


int main() {
    SV ds[] = {
        {"An", 2001},
        {"Binh", 2002},
        {"Cuong", 2006},
        {"Dung", 2007},
        {"Ha", 2003},
        {"Lan", 2004},
        {"Minh", 2005},
        {"Nam", 2001},
        {"Phuong", 1999},
        {"Trang", 2004}
    };

    Node* goc = nullptr;

    for(auto sv : ds) goc = them_node_BST(goc, sv);

    cout << "Sinh vien sinh nam 2004: \n";
    tim_SV(goc, 2004);
    return 0;
}
// 2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004