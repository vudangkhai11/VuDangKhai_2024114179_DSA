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
//Prim
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
//Kruskstra

struct Canh { int u, v, trongSo; };
bool sosanhcanh(Canh a, Canh b) { return a.trongSo < b.trongSo; }

int taphop[11];

int timgoc(int i) {

    if (taphop[i]== i) return i;
    return taphop[i]= timgoc(taphop[i]);
}
void goptaphop(int i, int j) {
    taphop[timgoc(i)] = timgoc(j);
}

void kruskal() {
    vector<Canh> danhsachcanh;
    int matranMST[11][11];

    // Khoi tao mang tap hop va ma tran cay khung
    for (int i = 0; i < 11; i++) {
        taphop[i] = i;
        for (int j = 0; j < 11; j++) matranMST[i][j] = kocoduongdi;
    }

    // Rut trich toan bo cac canh tu ma tran do thi
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 11; j++) {
            if (matran[i][j] != kocoduongdi) {
                danhsachcanh.push_back({ i, j, matran[i][j] });
            }
        }
    }

    // Sap xep cac canh tang dan
    sort(danhsachcanh.begin(), danhsachcanh.end(), sosanhcanh);

    int socanh = 0;
    for (Canh canh : danhsachcanh) {
        if (socanh == 10) break; // Cay khung 11 dinh thi chi can 10 canh

        // Neu khong tao thanh chu trinh thi them vao cay khung
        if (timgoc(canh.u) != timgoc(canh.v)) {

            matranMST[canh.u][canh.v]= canh.trongSo;

            matranMST[canh.v][canh.u]= canh.trongSo;

            goptaphop(canh.u, canh.v);
            socanh++;
        }
    }

    // In ra ma tran cua cay khung bang ham ban da viet
    inmatran(matranMST);
}
int main() {

    return 0;
}