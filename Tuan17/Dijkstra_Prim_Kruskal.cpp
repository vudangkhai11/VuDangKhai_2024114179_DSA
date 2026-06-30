#include<iostream>
using namespace std;

const int kocoduongdi = 1000000000;

string tentp[11] = {  "Ha Noi", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay", "Thai Nguyen", "Bac Ninh", "Bac Giang", "Uong Bi", "Hai Phong"};

int matran[11][11];

void taodothi() {
    for (int i = 0; i < 11; i++) {
        for (int j= 0; j < 11; j++) {
            if (i== j) matran[i][j] = 0;
            else matran[i][j] = kocoduongdi;
        }
    }
}
//Dijkstra
void dijkstra(int batDau, int ketThuc) {
    int khoangcach[11];
    int truoc[11];
    bool daduyet[11] = { false };

    for (int i = 0; i < 11; i++) {
        khoangcach[i] = kocoduongdi;
        truoc[i] = -1;
    }
    khoangcach[batDau] = 0;

    for (int i = 0; i < 10; i++) {
        int min = kocoduongdi, u = -1;
        for (int v = 0; v < 11; v++) {
            if (!daduyet[v] && khoangcach[v] < min) {
                min = khoangcach[v];
                u = v;
            }
        }
        if (u == -1) break;
        daduyet[u] = true;

        for (int v = 0; v < 11; v++) {
            if (!daduyet[v] && matran[u][v] != kocoduongdi && khoangcach[u] + matran[u][v] < khoangcach[v]) {
                khoangcach[v] = khoangcach[u] + matran[u][v];
                truoc[v] = u;
            }
        }
    }

    // In lo trinh
    cout << "=> Khoang cach ngan nhat tu " << tentp[batDau] << " den " << tentp[ketThuc] << " la: " << khoangcach[ketThuc] << endl;
    cout << "=> Lo trinh: ";
    int lotrinh[11], dem = 0, tam = ketThuc;
    while (tam != -1) {
        lotrinh[dem++] = tam;
        tam = truoc[tam];
    }
    for (int i = dem - 1; i >= 0; i--) {
        cout << tentp[lotrinh[i]];
        if (i > 0) cout << " -> ";
    }
    cout << "\n";
}
int main() {

    return 0;
}