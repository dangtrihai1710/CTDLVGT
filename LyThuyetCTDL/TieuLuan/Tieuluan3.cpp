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


// Định nghĩa kiểu dữ liệu cấu trúc truyện
typedef struct QuyenTruyen {
    char ma[MAXSTACK];
    char tentruyen[MAXSTACK];
    char tacgia[MAXSTACK];
    char theloai[MAXSTACK];
    float giatruyen;
    struct Date ngaynhap;
}Truyen;

// Nhập ngày nhập truyện
void nhapNgayNhapTruyen(Date &d) {
    cout << "\n\tNhap ngay: ";
    cin >> d.ngay;
    cout << "\n\tNhap thang: ";
    cin >> d.thang;
    cout << "\n\tNhap nam: ";
    cin >> d.nam;
}

// Xuất ngày nhập truyện 
void xuatNgayNhapTruyen(Date d) {
    cout << ""<<d.ngay<<"/"<<d.thang<<"/"<<d.nam<<"";
}


struct Stack {
    int top;
    Truyen nodes[MAXSTACK];
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

// Hàm nhập thông tin cho một quyển truyện
void nhapTruyen(Truyen &x) {
    cout << "\n\tNhap ma so quyen truyen: ";
    cin.ignore(); // Loại bỏ ký tự Enter còn lại trong bộ đệm
    cin.getline(x.ma, sizeof(x.ma));
    
    cout << "\n\tNhap ten quyen truyen: ";
    cin.getline(x.tentruyen, sizeof(x.tentruyen));
    
    cout << "\n\tNhap tac gia: ";
    cin.getline(x.tacgia, sizeof(x.tacgia));
    
    cout << "\n\tNhap the loai: ";
    cin.getline(x.theloai, sizeof(x.theloai));
    
    cout << "\n\tNhap gia quyen truyen: ";
    cin >> x.giatruyen;
    
    cout << "\n\tNhap ngay nhap: ";
    nhapNgayNhapTruyen(x.ngaynhap);
}

// Hàm xuất thông tin cho một quyển truyện
void xuatTruyen(Truyen x) {
    cout << "\n\tMa so quyen truyen: " << x.ma;
    cout << "\n\tTen quyen truyen: " << x.tentruyen;
    cout << "\n\tTac gia: " << x.tacgia;
    cout << "\n\tThe loai: " << x.theloai;
    cout << "\n\tGia quyen truyen: " << x.giatruyen;
    cout << "\n\tNgay nhap: ";
    xuatNgayNhapTruyen(x.ngaynhap);
    cout << endl;
}



// Hàm nhập danh sách truyện
void nhapDanhSachTruyen(Stack &s, int &n) {
    do {
        cout << "\n\tNhap so luong truyen (0<n<=100): ";
        cin >> n;
        if(0 >= n || n >= MAXSTACK)
            cout << "\n\tSo luong truyen khong hop le";
    } while (0 >= n || n >= MAXSTACK);
    for (int i = 0; i < n; i++) {
        cout << "\n\tNhap thong tin cho quyen truyen thu " << i + 1 << ":";
        nhapTruyen(s.nodes[++s.top]);
    }
}

// Hàm xuất danh sách truyện
void xuatDanhSachTruyen(Stack s, int n) {
    for (int i = 0; i < n; i++) {
        xuatTruyen(s.nodes[i]);
    }
}

// Hàm tìm truyện theo mã
void timTruyenTheoMa(Stack s, int n, char mssv[MAXSTACK]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].ma, mssv) == 0) {
            cout << "\nThong tin truyen co ma truyen la " << mssv << ":";
            xuatTruyen(s.nodes[i]);
            return;
        }
    }
    cout << "\n\tKhong tim thay truyen co ma nay " << mssv;
}

// Hàm xuat danh sach truyện thể loại kinh dị
void xuatDanhSachTruyenKinhDi(Stack s, int n) {
    cout << "\n\tDanh sach truyen kinh di:";
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].theloai, "kinh di") == 0) {
            xuatTruyen(s.nodes[i]);
        }
    }
}

// Hàm xuất danh sách truyện giá dưới 50.000 VND thể loại kinh dị
void XuatTruyen5(Stack s, int n) {
    cout << "\n\tDanh sach truyen the loai kinh di:";
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].theloai, "kinh di") == 0 && s.nodes[i].giatruyen < 50000) {
            xuatTruyen(s.nodes[i]);
        }
    }
}

// Hàm tìm truyện theo tên
void timTruyenTheoTen(Stack s, int n, char ten[MAXSTACK]) {
    cout << "\tThong tin ten truyen da nhap " << ten << ":";
    for (int i = 0; i < n; i++) {
        if (strcmp(s.nodes[i].tentruyen, ten) == 0) 
            xuatTruyen(s.nodes[i]);      
    }
}

// Hàm hoán vị
void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

// Hàm xóa quyển truyện theo vị trí
void xoaTruyenTheoViTri(Stack &s, int viTri) {
    if (viTri < 0 || viTri >= s.top + 1) {
        cout << "\n\tVi tri xoa khong hop le." << endl;
        return;
    }

    for (int i = viTri; i < s.top; i++) {
        s.nodes[i] = s.nodes[i + 1];
    }

    s.top--;
    cout << "\n\tDa xoa quyen truyen tai vi tri " << viTri + 1 << endl;
}


// Hàm sắp xếp danh sách sinh viên theo điểm toán tăng dần
void sapXepTruyenTheoGia(Stack &s, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s.nodes[i].giatruyen > s.nodes[j].giatruyen) {
                swap(s.nodes[i], s.nodes[j]);
            }
        }
    }
}

// Hàm MENU lựa chọn
void MeNu(int &chon) {
    cout << "\n\tCHUONG TRINH QUAN LY KHO TRUYEN C/C++";
    cout << "\n\t******------------MENU-------------******";
    cout << "\n\t1. Nhap danh sach truyen";
    cout << "\n\t2. Xuat danh sach truyen";
    cout << "\n\t3. Tim thong tin truyen theo ma";
    cout << "\n\t4. Xuat danh sach truyen kinh di";
    cout << "\n\t5. Xuat danh sach truyen gia duoi 50.000 VND the loai kinh di";
    cout << "\n\t6. Tim thong tin truyen theo ten truyen";
    cout << "\n\t7. Xoa truyen theo vi tri nhap trong kho ";
    cout << "\n\t8. Xuat danh sach truyen theo gia tang dan";
    cout << "\n\t0. Thoat";
    cout << "\n\tChon chuc nang: ";
    cin >> chon;
}

int main() {
    Stack s;
    int n, chon;
    char ma[MAXSTACK], ten[MAXSTACK];

    Init(s);

    do {
        MeNu(chon);

        switch (chon) {
        case 1:
            nhapDanhSachTruyen(s, n);
            break;
        case 2:
            if (IsEmpty(s)) {
                cout << "\nDanh sach truyen rong!" << endl;
            } else {
                xuatDanhSachTruyen(s, n);
            }
            break;
        case 3:
            cout << "\nNhap ma so quyen truyen can tim: ";
            cin.ignore();
            cin.getline(ma, sizeof(ma));
            timTruyenTheoMa(s, n, ma);
            break;
        case 4:
            xuatDanhSachTruyenKinhDi(s, n);
            break;
        case 5:
            XuatTruyen5(s, n);
            break;
        case 6:
            cout << "\nNhap ten truyen can tim: ";
            cin.ignore();
            cin.getline(ten, sizeof(ten));
            timTruyenTheoTen(s, n, ten);
            break;
        case 7:
            int viTri;
            cout << "\nNhap vi tri truyen can xoa: ";
            cin >> viTri;
            xoaTruyenTheoViTri(s, viTri - 1); // Chuyển về vi tri 0-based
            break;
        case 8:
            sapXepTruyenTheoGia(s, n);
            cout << "\nDanh sach truyen sau khi sap xep theo gia tang dan:";
            xuatDanhSachTruyen(s, n);
            break;
        case 0:
            cout << "\nKet thuc chuong trinh!";
            break;
        default:
            cout << "\nLua chon khong hop le. Vui long chon lai!" << endl;
            break;
        }
    } while (chon != 0);

    return 0;
}
