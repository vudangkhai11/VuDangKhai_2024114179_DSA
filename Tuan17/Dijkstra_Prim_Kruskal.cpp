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
int main() {

    return 0;
}