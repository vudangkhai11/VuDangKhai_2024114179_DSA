#include<iostream>
using namespace std;

const int N = 11;
const int INF = 1000000;

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
    int weight;
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

void DFS_DeQuy(int u, bool visited[])
{
    visited[u] = true;

    cout << city[u] << endl;

    Node* p = head[u];

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

//Tim dường đi bang DFS
bool DFS_tim_duong_di(int u, int dest, bool visited[], int parent[])
{
    visited[u] = true;

    if(u == dest)
        return true;

    Node* p = head[u];

    while(p != NULL)
    {
        int v = p->vertex;

        if(!visited[v])
        {
            parent[v] = u;

            if(DFS_tim_duong_di(v, dest, visited, parent))
                return true;
        }

        p = p->next;
    }

    return false;
}

void in_DuongDi(int parent[], int start, int dest)
{
    if(dest == start)
    {
        cout << city[start];
        return;
    }

    in_DuongDi(parent, start, parent[dest]);

    cout << " -> "
         << city[dest];
}

int main() {
    them_Canh(0,1,45);
    them_Canh(0,2,75);
    them_Canh(0,3,60);
    them_Canh(0,5,58);
    them_Canh(0,9,30);
    them_Canh(0,10,80);

    them_Canh(3,4,35);
    them_Canh(4,5,50);

    them_Canh(5,6,45);

    them_Canh(6,7,28);

    them_Canh(7,8,40);
    them_Canh(8,9,22);

    them_Canh(9,7,65);

    cout << "\n===== TIM DUONG DI =====\n";

    bool visited[N] = {false};
    int parent[N];

    for(int i = 0; i < N ; i++)
        parent[i] = -1;

    if(DFS_tim_duong_di(0, 6, visited, parent))
    {
        cout << "Duong di tu Ha Noi den Hai Phong:\n";

        in_DuongDi(parent, 0, 6);

        cout << endl;
    }
    else
    {
        cout << "Khong ton tai duong di\n";
    }

    return 0;
}