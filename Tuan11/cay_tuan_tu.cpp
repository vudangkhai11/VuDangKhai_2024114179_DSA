#include<iostream>
#include <cmath>
using namespace std;

class CayTuanTu {
private:
    char* cay;          // Mảng động lưu cấu trúc cây
    int kichThuoc;      // Kích thước hiện tại của mảng
    char TRONG = '-';   // Ký tự đại diện cho nút trống

    // Hàm bổ trợ để tự động mở rộng mảng khi chỉ số vượt quá kích thước hiện tại
    void moRongMang(int chiSoMoi) {
        if (chiSoMoi >= kichThuoc) {
            int kichThuocMoi = chiSoMoi + 1;
            char* mangMoi = new char[kichThuocMoi];
            
            // Sao chép dữ liệu cũ sang mảng mới
            for (int i = 0; i < kichThuoc; i++) {
                mangMoi[i] = cay[i];
            }
            // Điền ký tự TRONG vào phần vùng nhớ mới mở rộng
            for (int i = kichThuoc; i < kichThuocMoi; i++) {
                mangMoi[i] = TRONG;
            }
            
            // Giải phóng mảng cũ và trỏ sang mảng mới
            delete[] cay;
            cay = mangMoi;
            kichThuoc = kichThuocMoi;
        }
    }

public:
    // Hàm khởi tạo (Constructor)
    CayTuanTu(int kichThuocBanDau = 10) {
        kichThuoc = kichThuocBanDau;
        cay = new char[kichThuoc];
        for (int i = 0; i < kichThuoc; i++) {
            cay[i] = TRONG;
        }
    }

    // Hàm hủy (Destructor) để giải phóng bộ nhớ khi dùng mảng động
    ~CayTuanTu() {
        delete[] cay;
    }

    // Đặt nút gốc (Root)
    void datNutGoc(char giaTri) {
        cay[0] = giaTri;
    }

    // Thêm con trái vào nút tại chiSoCha
    void datConTrai(char giaTri, int chiSoCha) {
        if (chiSoCha >= kichThuoc || cay[chiSoCha] == TRONG) {
            cout << "Loi: Nut cha tai vi tri " << chiSoCha << " khong ton tai!\n";
            return;
        }
        int chiSoTrai = 2 * chiSoCha + 1;
        moRongMang(chiSoTrai);
        cay[chiSoTrai] = giaTri;
    }

    // Thêm con phải vào nút tại chiSoCha
    void datConPhai(char giaTri, int chiSoCha) {
        if (chiSoCha >= kichThuoc || cay[chiSoCha] == TRONG) {
            cout << "Loi: Nut cha tai vi tri " << chiSoCha << " khong ton tai!\n";
            return;
        }
        int chiSoPhai = 2 * chiSoCha + 2;
        moRongMang(chiSoPhai);
        cay[chiSoPhai] = giaTri;
    }

    // In toàn bộ cấu trúc mảng ra màn hình
    void inMangCay() {
        cout << "Mang tuan tu cua cay: ";
        for (int i = 0; i < kichThuoc; i++) {
            cout << cay[i] << " ";
        }
        cout << "\n";
    }

    // Duyệt cây theo thứ tự trước (Pre-order)
    void duyetThuTuTruoc(int chiSo = 0) {
        // Nếu chỉ số vượt quá mảng hoặc gặp nút trống thì dừng
        if (chiSo >= kichThuoc || cay[chiSo] == TRONG) {
            return;
        }
        cout << cay[chiSo] << " ";                // Gốc
        duyetThuTuTruoc(2 * chiSo + 1);           // Trái
        duyetThuTuTruoc(2 * chiSo + 2);           // Phải
    }
};
int main() {

    return 0;
}