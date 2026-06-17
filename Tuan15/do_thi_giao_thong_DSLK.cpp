#include<iostream>
using namespace std;

const int N = 11;

string city[N] =
{
    "Ha Noi",
    "Son Tay",
    "Hoa Binh",
    "Phu Ly",
    "Hung Yen",
    "Hai Duong",
    "Hai Phong",
    "Uong Bi",
    "Bac Giang",
    "Bac Ninh",
    "Thai Nguyen"
};

struct Node
{
    int vertex;
    int weight; // trọng số cạnh
    Node* next;
};

Node *head[N] = {NULL};

void them_Canh(int u, int v, int w)
{
    Node *p = new Node;
    p->vertex = v;
    p->weight = w;
    p->next = head[u];
    head[u] = p;

    p = new Node;
    p->vertex = u;
    p->weight = w;
    p->next = head[v];
    head[v] = p;
}


int main() {
    
    return 0;
}