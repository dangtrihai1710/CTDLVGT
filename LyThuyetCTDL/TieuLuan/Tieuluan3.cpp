#include <iostream>
#include <conio.h>
#include <cstring>
#define MAXSTACK 100
using namespace std;

// Định nghĩa kiểu dữ liệu ngày tháng
struct Date {
    unsigned ngay;
    unsigned thang;
    unsigned nam;
};


// Định nghĩa kiểu dữ liệu cấu trúc sinh viên
typedef struct SinhVien {
    char ma[MAXSTACK];
    char ten[MAXSTACK];
    char gioiTinh;
    float diemtoan;
    float diemly;
    float diemanh;
    char tennganh[MAXSTACK];
    struct Date ng;
}SV;

// Nhập ngày sinh cho sinh viên
void nhapNgaySinh(Date &d) {
    cout << "\n\tNhap ngay: ";
    cin >> d.ngay;
    cout << "\n\tNhap thang: ";
    cin >> d.thang;
    cout << "\n\tNhap nam: ";
    cin >> d.nam;
}

// Xuất ngày sinh cho sinh viên
void xuatNgaySinh(Date d) {
    cout << ""<<d.ngay<<"/"<<d.thang<<"/"<<d.nam<<"";
}

//Hàm nhập 1 sinh viên
void nhapSV(SV &x) {
    cout << "\n\tNhap ma: ";
    fflush(stdin);
    gets(x.ma);
    cout << "\n\tNhap ten: ";
    gets(x.ten);
    cout << "\n\tNhap ten nganh hoc: (VD:CNTT)";
    gets(x.tennganh);
    cout << "\n\tNhap diem toan: ";
    cin >> x.diemtoan;
    cout << "\n\tNhap diem ly: ";
    cin >> x.diemly;
    cout << "\n\tNhap diem anh: ";
    cin >> x.diemanh;
    cout << "\n\tNhap ngay thang nam sinh: ";
    nhapNgaySinh(x.ng);
    fflush(stdin);
    do {
        cout << "\n\tNhap gioi tinh(x-nu,y-nam): ";
        x.gioiTinh = getche();
    }while(x.gioiTinh != 'x' && x.gioiTinh != 'y');
}

// Hàm xuất 1 sinh viên
void xuatSV(SV x) {
    cout << "\n\tMa:" << x.ma ;
    cout << " Ten:" << x.ten ;
    cout << " Ten nganh:" << x.tennganh ;
    cout << " Diem toan:" << x.diemtoan ;
    cout << " Diem ly:" << x.diemly ;
    cout << " Diem tin:" << x.diemanh ;
    xuatNgaySinh(x.ng);
    cout << " Gioi tinh:" << x.gioiTinh ;
}
struct Stack {
    int top;
    SV nodes[MAXSTACK];
};

void Init(Stack &s) {
    s.top = -1;
}

bool IsEmpty(Stack s) {
    return (s.top == -1);
}

bool IsFull(Stack s) {
    return (s.top == MAXSTACK - 1);
}


// Hàm MENU lựa chọn
void MeNu(int &chon) {
    cout << "\n\tCHUONG TRINH QUAN LY SINH VIEN BANG C/C++";
    cout << "\n\t******------------MENU-------------******";
    cout << "\n\t1. Nhap danh sach sinh vien";
    cout << "\n\t2. Xuat danh sach sinh vien";
    cout << "\n\t3. Tim thong tin sinh vien theo MSSV";
    cout << "\n\t4. Xuat danh sach sinh vien CNTT";
    cout << "\n\t5. Xuat danh sach sinh vien nu CNTT";
    cout << "\n\t6. Tim thong tin sinh vien theo ten";
    cout << "\n\t7. Xuat danh sach sinh vien theo ten nganh";
    cout << "\n\t8. Xuat danh sach sinh vien theo diem toan tang dan";
    cout << "\n\t0. Thoat";
    cout << "\n\tChon chuc nang: ";
    cin >> chon;
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(Stack &s, int &n) {
    cout << "\n\tNhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\n\tNhap thong tin cho sinh vien thu " << i + 1 << ":";
        nhapSV(s.nodes[++s.top]);
    }
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(Stack s, int n) {
    for (int i = 0; i < n; i++) {
        xuatSV(s.nodes[i]);
    }
}

// Hàm tìm sinh viên theo MSSV
void timSinhVienTheoMSSV(Stack s, int n, char mssv[MAXSTACK]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].ma, mssv) == 0) {
            cout << "\nThong tin sinh vien co MSSV " << mssv << ":";
            xuatSV(s.nodes[i]);
            return;
        }
    }
    cout << "\nKhong tim thay sinh vien co MSSV " << mssv;
}

// Hàm xuat danh sach sinh vien CNTT
void xuatDanhSachSinhVienCNTT(Stack s, int n) {
    cout << "\nDanh sach sinh vien CNTT:";
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].tennganh, "CNTT") == 0) {
            xuatSV(s.nodes[i]);
        }
    }
}

// Hàm xuat danh sach sinh vien nu CNTT
void xuatDanhSachSinhVienNuCNTT(Stack s, int n) {
    cout << "\nDanh sach sinh vien nu CNTT:";
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].tennganh, "CNTT") == 0 && s.nodes[i].gioiTinh == 'x') {
            xuatSV(s.nodes[i]);
        }
    }
}

// Hàm tìm sinh viên theo tên
void timSinhVienTheoTen(Stack s, int n, char ten[MAXSTACK]) {
    cout << "\nDanh sach sinh vien co ten " << ten << ":";
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].ten, ten) == 0) {
            xuatSV(s.nodes[i]);
        }
    }
}

// Hàm xuat danh sach sinh vien theo ten nganh
void xuatDanhSachSinhVienTheoTenNganh(Stack s, int n, char tenNganh[MAXSTACK]) {
    cout << "\nDanh sach sinh vien theo ten nganh " << tenNganh << ":";
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].tennganh, tenNganh) == 0) {
            xuatSV(s.nodes[i]);
        }
    }
}

// Hàm sắp xếp danh sách sinh viên theo điểm toán tăng dần
void sapXepSinhVienTheoDiemToan(Stack &s, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s.nodes[i].diemtoan > s.nodes[j].diemtoan) {
                swap(s.nodes[i], s.nodes[j]);
            }
        }
    }
}

int main() {
    Stack stack;
    Init(stack);
    int chon;
    int n = 0;

    do {
        MeNu(chon);
        switch (chon) {
            case 1:
                nhapDanhSachSinhVien(stack, n);
                break;
            case 2:
                xuatDanhSachSinhVien(stack, n);
                break;
            case 3:
                char mssv[MAXSTACK];
                cout << "\nNhap MSSV can tim: ";
                fflush(stdin);
                gets(mssv);
                timSinhVienTheoMSSV(stack, n, mssv);
                break;
            case 4:
                xuatDanhSachSinhVienCNTT(stack, n);
                break;
            case 5:
                xuatDanhSachSinhVienNuCNTT(stack, n);
                break;
            case 6:
                char ten[MAXSTACK];
                cout << "\nNhap ten sinh vien can tim: ";
                fflush(stdin);
                gets(ten);
                timSinhVienTheoTen(stack, n, ten);
                break;
            case 7:
                char tenNganh[MAXSTACK];
                cout << "\nNhap ten nganh can tim: ";
                fflush(stdin);
                gets(tenNganh);
                xuatDanhSachSinhVienTheoTenNganh(stack, n, tenNganh);
                break;
            case 8:
                sapXepSinhVienTheoDiemToan(stack, n);
                xuatDanhSachSinhVien(stack, n);
                break;
            case 0:
                cout << "\nThoat chuong trinh.";
                break;
            default:
                cout << "\nLua chon khong hop le. Vui long chon lai.";
                break;
        }
    } while (chon != 0);

    return 0;
}



