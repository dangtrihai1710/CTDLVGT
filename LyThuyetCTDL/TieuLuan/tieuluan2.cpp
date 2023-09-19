#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
// Định nghĩa ngày tháng năm
typedef struct Date {
    int ngay;
    int thang;
    int nam;
} Date;
//  Định nghĩa SV
typedef struct SinhVien {
    char ma[MAX];
    char ten[MAX];
    char gioiTinh;
    float diemtoan;
    float diemly;
    float diemanh;
    char tennganh[MAX];
    Date ng;
} SV;

// Định nghĩa dslk
typedef struct tagNode {
    SV info;
    struct tagNode* pNext;
} Node;

typedef Node* PtrNode;

// Hàm khởi tạo pHead
void init(PtrNode &pHead) {
    pHead = NULL;
}

// Hàm kiểm tra rỗng
bool isEmpty(PtrNode pHead) {
    return pHead == NULL;
}

// Hàm nhập ngày sinh
void nhapNgaySinh(Date &d) {
    cout << "\n\tNhap ngay: ";
    cin >> d.ngay;
    cout << "\n\tNhap thang: ";
    cin >> d.thang;
    cout << "\n\tNhap nam: ";
    cin >> d.nam;
}

// Hàm xuất ngày sinh
void xuatNgaySinh(Date d) {
    cout << d.ngay << "/" << d.thang << "/" << d.nam;
}

// Hàm nhập 1 SV
void nhapSV(SV &x) {
    cout << "\n\tNhap ma: ";
    cin >> x.ma;
    cout << "\n\tNhap ten: ";
    cin >> x.ten;
    cout << "\n\tNhap ten nganh hoc: (VD:CNTT)";
    cin >> x.tennganh;
    cout << "\n\tNhap diem toan: ";
    cin >> x.diemtoan;
    cout << "\n\tNhap diem ly: ";
    cin >> x.diemly;
    cout << "\n\tNhap diem anh: ";
    cin >> x.diemanh;
    cout << "\n\tNhap ngay thang nam sinh: ";
    nhapNgaySinh(x.ng);
    do {
        cout << "\n\tNhap gioi tinh (x-nu, y-nam): ";
        cin >> x.gioiTinh;
    } while (x.gioiTinh != 'x' && x.gioiTinh != 'y');
}

// Hàm xuất 1 SV
void xuatSV(SV x) {
    cout << "\n\tMa:" << x.ma;
    cout << " Ten:" << x.ten;
    cout << " Ten nganh:" << x.tennganh;
    cout << " Diem toan:" << x.diemtoan;
    cout << " Diem ly:" << x.diemly;
    cout << " Diem tin:" << x.diemanh;
    cout << " Ngay sinh: ";
    xuatNgaySinh(x.ng);
    cout << " Gioi tinh:" << x.gioiTinh;
}

// Hàm tạo node
PtrNode createNode(SV x) {
    PtrNode p = new Node;
    p->info = x;
    p->pNext = NULL;
    return p;
}

// Hàm thêm phần tử vào đầu danh sách
void insertFirst(PtrNode &pHead, PtrNode pNew) {
    if (isEmpty(pHead)) {
        pHead = pNew;
    }
    else {
        pNew->pNext = pHead;
        pHead = pNew;
    }
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(PtrNode &pHead) {
    int soLuong;
    cout << "\n\tNhap so luong sinh vien: ";
    cin >> soLuong;

    for (int i = 0; i < soLuong; i++) {
        SV sv;
        cout << "\n\tNhap thong tin cho sinh vien thu " << i + 1 << endl;
        nhapSV(sv);
        PtrNode svMoi = createNode(sv);
        insertFirst(pHead, svMoi);
    }
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(PtrNode pHead) {
    PtrNode current = pHead;
    int i = 1;
    cout << "Xuat danh sach sinh vien:\n";
    while (current != NULL) {
        cout << "Sinh vien thu " << i << endl;
        xuatSV(current->info);
        current = current->pNext;
        i++;
    }
}



// Hàm tìm kiếm sinh viên theo MSSV
void timTheoMSSV(PtrNode pHead, char mssv[]) {
    PtrNode current = pHead;
    bool found = false;

    while (current != NULL) {
        if (strcmp(current->info.ma, mssv) == 0) {
            xuatSV(current->info);
            found = true;
            break; // Thoát khỏi vòng lặp sau khi tìm thấy sinh viên
        }
        current = current->pNext;
    }

    if (!found) {
        cout << "Khong tim thay sinh vien co MSSV nay: " << mssv << endl;
    }
}

// Hàm hiển thị sinh viên từ khoa CNTT
void xuatSinhVienCNTT(PtrNode pHead) {
    PtrNode current = pHead;
    int i = 1;

    cout << "Danh sach sinh vien CNTT:\n";
    while (current != NULL) {
        if (strcmp(current->info.tennganh, "CNTT") == 0) {
            cout << "Sinh vien thu " << i << endl;
            xuatSV(current->info);
            i++;
        }
        current = current->pNext;
    }
}

// Hàm hiển thị sinh viên nữ từ khoa CNTT
void xuatSinhVienNuCNTT(PtrNode pHead) {
    PtrNode current = pHead;
    int i = 1;

    cout << "Danh sach sinh vien nu CNTT:\n";
    while (current != NULL) {
        if (strcmp(current->info.tennganh, "CNTT") == 0 && current->info.gioiTinh == 'x') {
            cout << "Sinh vien nu CNTT thu " << i << endl;
            xuatSV(current->info);
            i++;
        }
        current = current->pNext;
    }
}

// Hàm tìm kiếm sinh viên theo tên
void timTheoTen(PtrNode pHead, char ten[]) {
    PtrNode current = pHead;
    int i = 1;
    bool found = false;

    while (current != NULL) {
        if (strcmp(current->info.ten, ten) == 0) {
            cout << "Sinh vien co ten '" << ten << "' thu " << i << endl;
            xuatSV(current->info);
            found = true;
        }
        current = current->pNext;
        i++;
    }

    if (!found) {
        cout << "Khong tim thay sinh vien co ten nay: " << ten << endl;
    }
}

// Hàm hiển thị sinh viên theo tên ngành
void xuatSinhVienTheoTenNganh(PtrNode pHead, char tennganh[]) {
    PtrNode current = pHead;
    int i = 1;

    cout << "Danh sach sinh vien theo nganh '" << tennganh << "':\n";
    while (current != NULL) {
        if (strcmp(current->info.tennganh, tennganh) == 0) {
            cout << "Sinh vien thu " << i << endl;
            xuatSV(current->info);
            i++;
        }
        current = current->pNext;
    }
}

// Hàm sắp xếp sinh viên theo điểm toán tăng dần
void sapXepTheoDiemToan(PtrNode& pHead) {
    if (isEmpty(pHead)) {
        return;
    }

    PtrNode current = pHead;
    PtrNode nextNode = current->pNext;

    while (current != NULL) {
        while (nextNode != NULL) {
            if (current->info.diemtoan > nextNode->info.diemtoan) {
                swap(current->info, nextNode->info);
            }
            nextNode = nextNode->pNext;
        }
        current = current->pNext;
        if (current != NULL) {
            nextNode = current->pNext;
        }
    }
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

int main() {
    PtrNode pHead;
    init(pHead);

    int choice;
    do {
        MeNu(choice); // Hiển thị menu và lấy sự lựa chọn của người dùng

        switch (choice) {
            case 1:
                nhapDanhSachSinhVien(pHead);
                break;
            case 2:
                xuatDanhSachSinhVien(pHead);
                break;
            case 3:
                char mssv[MAX];
                cout << "Nhap MSSV can tim: ";
                cin >> mssv;
                timTheoMSSV(pHead, mssv);
                break;
            case 4:
                xuatSinhVienCNTT(pHead);
                break;
            case 5:
                xuatSinhVienNuCNTT(pHead);
                break;
            case 6:
                char ten[MAX];
                cout << "Nhap ten SV can tim: ";
                cin.ignore();
                cin.getline(ten, sizeof(ten));
                timTheoTen(pHead, ten);
                break;
            case 7:
                char tennganh[MAX];
                cout << "Nhap ten nganh can tim SV: ";
                cin.ignore();
                cin.getline(tennganh, sizeof(tennganh));
                xuatSinhVienTheoTenNganh(pHead, tennganh);
                break;
            case 8:
                sapXepTheoDiemToan(pHead);
                cout << "Danh sach sinh vien co diem toan tang dan:\n";
                xuatDanhSachSinhVien(pHead);
                break;
            case 0:
                cout << "Thoat chuong trinh quan ly sinh vien.\n";
                break;
            default:
                cout << "Lua chon khon hop le .Vui long chon lai.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
