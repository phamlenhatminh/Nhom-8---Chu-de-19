
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
