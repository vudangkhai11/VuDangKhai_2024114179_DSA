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

    return 0;
}