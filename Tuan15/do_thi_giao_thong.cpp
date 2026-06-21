#include<iostream>
#include<queue>
#include<stack>
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

void them_Canh(int a[][N], int u, int v)
{
    a[u][v] = 1;
    a[v][u] = 1;
}

void BFS(int a[][N], int start)
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

        for(int v = 0; v < N; v++)
        {
            if(a[u][v] == 1 && !visited[v])
            {
                visited[v] = true;
                q.push(v);
            }            
        }
    }
}

void DFS(int a[][N], int start)
{
    bool visited[N] = {false};
    stack<int> st;

    st.push(start);

    while(!st.empty())
    {
        int u = st.top();
        st.pop();

        if(!visited[u])
        {
            visited[u] = true;
            cout << city[u] << endl;

            for(int v = N - 1; v >= 0; v--)
            {
                if(a[u][v] == 1 && !visited[v])
                {
                    st.push(v);
                }
            }
        }
    }
}

int main() {
    int a[N][N] = {0};

    them_Canh(a,0,1);
    them_Canh(a,0,2);
    them_Canh(a,0,3);
    them_Canh(a,0,5);
    them_Canh(a,0,9);
    them_Canh(a,0,10);

    them_Canh(a,3,4);
    them_Canh(a,4,5);

    them_Canh(a,5,6);

    them_Canh(a,6,7);

    them_Canh(a,7,8);
    them_Canh(a,8,9);

    them_Canh(a,9,7);

    cout << "Ma tran ke:\n";

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout << a[i][j] << " ";

        cout << endl;
    }

    cout << "\nDuyet BFS tu Ha Noi:\n";
    BFS(a, 0);    

    return 0;
}