#include <iostream>
#include <string>
#include <limits>
using namespace std;

class KhoHang {
private:
    string maKho;
    string tenKho;
    string diaDiem;
    int sucChuaToiDa;
    int soLuongHienTai;
    string loaiHang;
    string nguoiQuanLy;

public:
    // Ham lay ma kho
    void setMaKho(const string& maKhoHopLe) {
        maKho = maKhoHopLe;
    }
    // Ham nhap thong tin kho con lai
    void nhap() {
        cin.ignore();
        cout << "Ten kho: ";
        getline(cin, tenKho);

        cout << "Dia diem: ";
        getline(cin, diaDiem);

        do {
            while(true) {
                cout << "Suc chua toi da: ";
                if(cin >> sucChuaToiDa) {
                    break;
                }
                else {
                    cout << "Phai la so nguyen!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            if(sucChuaToiDa < 0) cout << "Suc chua khong hop le.\n";
        } while(sucChuaToiDa < 0);
        // So luong hang hien tai khong duoc am
        do {
            while(true) {
                cout << "So luong hang hien tai: ";
                if(cin >> soLuongHienTai) {
                    break;
                }
                else {
                    cout << "Phai la so nguyen!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            if (soLuongHienTai < 0 ||
                soLuongHienTai > sucChuaToiDa) {
                cout << "So luong hang khong hop le! Nhap lai.\n";
            }
        } while (soLuongHienTai < 0 ||
                 soLuongHienTai > sucChuaToiDa);

        cin.ignore();

        cout << "Loai hang luu tru: ";
        getline(cin, loaiHang);

        cout << "Nguoi quan ly: ";
        getline(cin, nguoiQuanLy);
    }

   // Ham xuat thong tin kho
    void xuat() {
        cout << "Ma kho: " << maKho << endl;
        cout << "Ten kho: " << tenKho << endl;
        cout << "Dia diem: " << diaDiem << endl;
        cout << "Suc chua toi da: " << sucChuaToiDa << endl;
        cout << "So luong hang hien tai: "
             << soLuongHienTai << endl;
        cout << "Loai hang luu tru: " << loaiHang << endl;
        cout << "Nguoi quan ly: " << nguoiQuanLy << endl;
    }

    // Ham nhap hang vao kho
    void nhapKho(int soLuong) {
        if (soLuong <= 0) {
            cout << "So luong hang khong hop le!\n";
        }
        else if (soLuongHienTai + soLuong > sucChuaToiDa) {
            cout << "Khong du suc chua de nhap hang!\n";
        }
        else {
            soLuongHienTai = soLuongHienTai + soLuong;
            cout << "Nhap hang thanh cong!\n";
        }
    }

    // Ham xuat hang kho
    void xuatKho(int soLuong) {
        if (soLuong <= 0) {
            cout << "So luong hang khong hop le!\n";
        }
        else if (soLuong > soLuongHienTai) {
            cout << "Khong du hang de xuat!\n";
        }
        else {
            soLuongHienTai = soLuongHienTai - soLuong;
            cout << "Xuat hang thanh cong!\n";
        }
    }

    // Ham lay ma kho
    string getMaKho() {
        return maKho;
    }

    // Ham lay dia diem
    string getDiaDiem() {
        return diaDiem;
    }

    // Ham lay suc chua toi da
    int getSucChua() {
        return sucChuaToiDa;
    }
};

// ================= NHAP DANH SACH =================
//Ham kiem tra ma kho trung
bool kiemTraMaKhoTrung(KhoHang ds[], int n, const string& makhomoi) {
    for(int i = 0; i < n; i++) {
        if(ds[i].getMaKho() == makhomoi) {
            return true;
        }
    }
    return false;
}

void nhapDanhSach(KhoHang ds[], int &n) {
    do {
        cout << "Nhap so luong kho (0 < n < 200): ";
        cin >> n;

        if (n <= 0 || n >= 200) {
            cout << "So luong kho khong hop le! Nhap lai.\n";
        }
    } while (n <= 0 || n >= 200);

    for (int i = 0; i < n; i++) {
        cout << "\n===== NHAP KHO THU " << i + 1 << " =====\n";

        string maKhoNhap;
        bool isDuplicate;
        do {
            cout << "Ma kho: ";
            cin >> maKhoNhap;

            isDuplicate = kiemTraMaKhoTrung(ds, i , maKhoNhap);
            if (isDuplicate) cout << "Ma kho da ton tai!\n";
        } while(isDuplicate);
        ds[i].setMaKho(maKhoNhap);
        ds[i].nhap();
    }
}


// ================= XUAT DANH SACH =================

void xuatDanhSach(KhoHang ds[], int n) {
    if (n == 0) {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << "\n========== DANH SACH KHO HANG ==========\n";

    for (int i = 0; i < n; i++) {
        cout << "\n----- KHO THU " << i + 1 << " -----\n";
        ds[i].xuat();
    }
}


// ================= SAP XEP =================

void sapXep(KhoHang ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getSucChua() < ds[j].getSucChua()) {
                KhoHang temp;

                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "Da sap xep theo suc chua toi da giam dan!\n";
}


// ================= TIM THEO MA KHO =================

void timTheoMa(KhoHang ds[], int n) {
    string ma;
    bool timThay = false;

    cout << "Nhap ma kho can tim: ";
    cin >> ma;

    for (int i = 0; i < n; i++) {
        if (ds[i].getMaKho() == ma) {
            cout << "\n===== KHO CAN TIM =====\n";
            ds[i].xuat();
            timThay = true;
        }
    }

    if (timThay == false) {
        cout << "Khong tim thay kho co ma " << ma << "!\n";
    }
}


// ================= TIM THEO DIA DIEM =================

void timTheoDiaDiem(KhoHang ds[], int n) {
    string diaDiem;
    bool timThay = false;

    cin.ignore();

    cout << "Nhap dia diem can tim: ";
    getline(cin, diaDiem);

    for (int i = 0; i < n; i++) {
        if (ds[i].getDiaDiem() == diaDiem) {
            cout << "\n===== KHO CAN TIM =====\n";
            ds[i].xuat();
            timThay = true;
        }
    }

    if (timThay == false) {
        cout << "Khong tim thay kho tai dia diem "
             << diaDiem << "!\n";
    }
}


// ================= THEM KHO =================

void themKho(KhoHang ds[], int &n) {
    int viTri;

    if (n >= 199) {
        cout << "Khong the them! Danh sach da dat gioi han.\n";
        return;
    }

    cout << "Nhap vi tri can them (1 - " << n + 1 << "): ";
    cin >> viTri;

    if (viTri < 1 || viTri > n + 1) {
        cout << "Vi tri khong hop le!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Dich cac phan tu sang phai
    for (int i = n; i >= viTri; i--) {
        ds[i] = ds[i - 1];
    }

    cout << "\n===== NHAP KHO MOI =====\n";
    string maKhoNhap;
    bool isDuplicate;
    do {
        cout << "Ma kho: ";
        cin >> maKhoNhap;

        isDuplicate = kiemTraMaKhoTrung(ds, viTri, maKhoNhap);
        if (isDuplicate) cout << "Ma kho da ton tai!\n";
    } while(isDuplicate);
    ds[viTri].setMaKho(maKhoNhap);
    ds[viTri].nhap();

    n++;

    cout << "Them kho thanh cong!\n";
}


// ================= XOA KHO =================

void xoaKho(KhoHang ds[], int &n) {
    int viTri;

    if (n == 0) {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << "Nhap vi tri can xoa (1 - " << n << "): ";
    cin >> viTri;

    if (viTri < 1 || viTri > n) {
        cout << "Vi tri khong hop le!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Dich cac phan tu sang trai
    for (int i = viTri - 1; i < n - 1; i++) {
        ds[i] = ds[i + 1];
    }

    n--;

    cout << "Xoa kho thanh cong!\n";
}


// ================= NHAP HANG =================

void thucHienNhapKho(KhoHang ds[], int n) {
    int viTri;
    int soLuong;

    cout << "Nhap vi tri kho: ";
    cin >> viTri;

    if (viTri < 1 || viTri > n) {
        cout << "Vi tri khong hop le!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Nhap so luong hang can nhap: ";
    cin >> soLuong;

    ds[viTri - 1].nhapKho(soLuong);
}


// ================= XUAT HANG =================

void thucHienXuatKho(KhoHang ds[], int n) {
    int viTri;
    int soLuong;

    cout << "Nhap vi tri kho: ";
    cin >> viTri;

    if (viTri < 1 || viTri > n) {
        cout << "Vi tri khong hop le!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Nhap so luong hang can xuat: ";
    cin >> soLuong;

    ds[viTri - 1].xuatKho(soLuong);
}


// ================= HAM MAIN =================

int main() {
    KhoHang ds[199];
    int n = 0;
    int luaChon;

    do {
        cout << "\n\n========== QUAN LY KHO HANG ==========\n";
        cout << "1. Nhap danh sach kho hang\n";
        cout << "2. In danh sach kho hang\n";
        cout << "3. Sap xep theo suc chua giam dan\n";
        cout << "4. Tim kho theo ma kho\n";
        cout << "5. Tim kho theo dia diem\n";
        cout << "6. Them kho vao vi tri\n";
        cout << "7. Xoa kho tai vi tri\n";
        cout << "8. Nhap hang vao kho\n";
        cout << "9. Xuat hang kho\n";
        cout << "0. Thoat\n";
        cout << "======================================\n";

        while(true) {
            cout << "Nhap lua chon: ";
            if(cin >> luaChon) {
                break;
            }
            else {
                cout << "Lua chon khong hop le!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (luaChon) {

        case 1:
            nhapDanhSach(ds, n);
            break;

        case 2:
            xuatDanhSach(ds, n);
            break;

        case 3:
            if (n == 0)
                cout << "Danh sach rong!\n";
            else
                sapXep(ds, n);
            break;

        case 4:
            if (n == 0)
                cout << "Danh sach rong!\n";
            else
                timTheoMa(ds, n);
            break;

        case 5:
            if (n == 0)
                cout << "Danh sach rong!\n";
            else
                timTheoDiaDiem(ds, n);
            break;

        case 6:
            themKho(ds, n);
            break;

        case 7:
            xoaKho(ds, n);
            break;

        case 8:
            if (n == 0)
                cout << "Danh sach rong!\n";
            else
                thucHienNhapKho(ds, n);
            break;

        case 9:
            if (n == 0)
                cout << "Danh sach rong!\n";
            else
                thucHienXuatKho(ds, n);
            break;

        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 0);

    return 0;
}
