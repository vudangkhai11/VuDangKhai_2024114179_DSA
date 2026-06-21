#include<iostream>
#include<queue>
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

void hienThiDSKe()
{
    for(int i = 0; i < N; i++)
    {
        cout << city[i] << " : ";

        Node *p = head[i];
        while(p != NULL)
        {
            cout << city[p->vertex]
                 << "(" << p->weight << ") -> ";
            p = p->next;
        }

        cout << "NULL\n";
    }
}

// DFS đệ quy
void DFS_DeQuy(int u, bool visited[])
{
    visited[u] = true;
    cout << city[u] << endl;

    Node *p = head[u];

    while(p != NULL)
    {
        int v = p->vertex;

        if(!visited[v])
            DFS_DeQuy(v, visited);

        p = p->next;
    }
}

void DFS(int start)
{
    bool visited[N] = {false};
    DFS_DeQuy(start, visited);
}

// BFS
void BFS(int start)
{
    bool visited[N] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << city[u] << endl;

        Node *p = head[u];

        while(p != NULL)
        {
            int v = p->vertex;

            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }

            p = p->next;
        }
    }
}

int main() {
    them_Canh(0,1,45);    // Ha Noi - Son Tay
    them_Canh(0,2,75);    // Ha Noi - Hoa Binh
    them_Canh(0,3,60);    // Ha Noi - Phu Ly
    them_Canh(0,5,58);    // Ha Noi - Hai Duong
    them_Canh(0,9,30);    // Ha Noi - Bac Ninh
    them_Canh(0,10,80);   // Ha Noi - Thai Nguyen

    them_Canh(3,4,35);    // Phu Ly - Hung Yen
    them_Canh(4,5,50);    // Hung Yen - Hai Duong

    them_Canh(5,6,45);    // Hai Duong - Hai Phong

    them_Canh(6,7,28);    // Hai Phong - Uong Bi

    them_Canh(7,8,40);    // Uong Bi - Bac Giang
    them_Canh(8,9,22);    // Bac Giang - Bac Ninh

    them_Canh(9,7,65);    // Bac Ninh - Uong Bi

    cout << "=== Danh sach ke ===\n";
    hienThiDSKe();

    cout << "\n=== DFS tu Ha Noi ===\n";
    DFS(0);

    cout << "\n=== BFS tu Ha Noi ===\n";
    BFS(0);

    return 0;
}