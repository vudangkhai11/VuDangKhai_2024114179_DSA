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

void themcanh(int u, int v, int trongSo) {
    matran[u][v] = trongSo;
    matran[v][u] = trongSo;
}

// Ham in Ma tran dinh ke 
void inmatran(int maTran[11][11]) {
    for (int i =0; i < 11; i++) cout << i << "\t";
    cout << "\n";
    for (int i= 0; i < 11; i++) {
        cout << " " << i << " | ";
        for (int j = 0; j < 11; j++) {
            if (maTran[i][j]== kocoduongdi || i== j) cout << "0\t"; // In 0 neu khong co canh noi
            else cout << maTran[i][j] << "\t";                   // In ra trong so
        }
        cout << "\n";
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

void Prim(int dinhbatdau) {
    int matranMST[11][11];
    int khoangcach[11], cha[11];
    bool dathem[11] = { false };

    // Khoi tao ma tran cay khung rong
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++) matranMST[i][j] = kocoduongdi;

    for (int i = 0; i < 11; i++) khoangcach[i] = kocoduongdi;
    khoangcach[dinhbatdau] = 0;
    cha[dinhbatdau] = -1;

    for (int i = 0; i < 10; i++) {
        int min = kocoduongdi, u = -1;
        for (int v = 0; v < 11; v++) {
            if (!dathem[v] && khoangcach[v] < min) {
                min = khoangcach[v];
                u = v;
            }
        }

        dathem[u] = true;
        // Ghi canh vao ma tran mst
        if (cha[u] != -1) {
            matranMST[u][cha[u]] = matran[u][cha[u]];
            matranMST[cha[u]][u] = matran[u][cha[u]];
        }

        for (int v = 0; v < 11; v++) {
            if (matran[u][v] != kocoduongdi && !dathem[v] && matran[u][v] < khoangcach[v]) {
                cha[v] = u;
                khoangcach[v] = matran[u][v];
            }
        }
    }

    inmatran(matranMST);
}

int main() {

    return 0;
}