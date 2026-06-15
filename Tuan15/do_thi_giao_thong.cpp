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

void them_Canh(int a[][N], int u, int v)
{
    a[u][v] = 1;
    a[v][u] = 1;
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

    return 0;
}