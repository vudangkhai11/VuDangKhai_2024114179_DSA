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
bool DFS_tim_duong_di(int u, int dest,
              bool visited[],
              int parent[])
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

            if(DFS_tim_duong_di(v, dest,
                        visited,
                        parent))
                return true;
        }

        p = p->next;
    }

    return false;
}

int main() {
    
    return 0;
}