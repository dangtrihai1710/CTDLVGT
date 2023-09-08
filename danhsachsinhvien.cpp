#include <iostream>
#include <cstring>
using namespace std;

typedef struct SinhVien {
    int maSV;
    char hoTen[100];   
}SV;

typedef struct tagNode {
    SV info;
    struct tagNode* pNext;
} Node;

typedef Node* PtrNode;

void init(PtrNode& pHead) {
    pHead = NULL;
}

bool isEmpty(PtrNode pHead) {
    return pHead == NULL;
}

// Hàm tạo node
PtrNode createNode(SV x) {
    PtrNode p = new Node;
    p->info = x;
    p->pNext = NULL;
    return p;
}


void insertFirst(PtrNode& pHead, PtrNode pNew) {
    if (isEmpty(pHead)) {
        pHead = pNew;
    } else {
        pNew->pNext = pHead;
        pHead = pNew;
    }
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(PtrNode& pHead) {
    int soLuong;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;

    for (int i = 0; i < soLuong; i++) {
        SV sv;
        cout << "Nhap thong tin cho sinh vien thu " << i + 1 << endl;
        cout << "Ma SV: ";
        cin >> sv.maSV;
        cout << "Ho Ten: ";
        cin.ignore(); // Để xóa bộ nhớ đệm của cin trước khi nhập chuỗi
        cin.getline(sv.hoTen, sizeof(sv.hoTen));
        
        PtrNode svMoi = createNode(sv);
        insertFirst(pHead, svMoi);
    }
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(const PtrNode pHead) {
    PtrNode current = pHead;
    int i = 0;
    cout << "Xuat danh sach sinh vien:\n";
    while (current != NULL) {
        cout << "Sinh vien thu "<< i << endl;
        cout << "Ma SV: " << current->info.maSV << ", Ho Ten: " << current->info.hoTen << endl;
        current = current->pNext;
        i++;
    }
}


void hoanVi(SV& a, SV& b) {
    SV temp = a;
    a = b;
    b = temp;
}

PtrNode searchX(PtrNode pHead, SV x) {
    PtrNode p = pHead;
    while (p != NULL && p->info.maSV != x.maSV) {
        p = p->pNext;
    }
    return p;
}

// Hàm xóa node 
void DeleteNode(PtrNode& pHead, PtrNode p) {
    if (!pHead || !p) {
        return;
    }

    // Bước 1: Nếu danh sách chỉ có 1 phần tử và đó là nút cần xóa (p == pHead)
    if (pHead == p) {
        pHead = pHead->pNext;
        delete p;
        return;
    }

    PtrNode pTruoc = NULL;
    PtrNode current = pHead;

    while (current != NULL && current != p) {
        pTruoc = current;
        current = current->pNext;
    }

    // Bước 2: Kiểm tra nếu đã tìm thấy nút cần xóa (p)
    if (current == p) {
        pTruoc->pNext = p->pNext;
        delete p;
    }
}

// Hàm tìm min
PtrNode MinMaSV(PtrNode pHead) {
    PtrNode nodeMin = pHead;
    PtrNode p = pHead->pNext;
    while (p != NULL) {
        if (nodeMin->info.maSV > p->info.maSV)
            nodeMin = p;       
        p = p->pNext;
    }
    return nodeMin;
}

PtrNode MinTen(PtrNode pHead) {
    PtrNode nodeMin = pHead;
    PtrNode p = pHead->pNext;
    while (p != NULL) {
        if (strcmp(nodeMin->info.hoTen, p->info.hoTen) > 0)
            nodeMin = p;       
        p = p->pNext;
    }
    return nodeMin;
}

// Hàm sắp xếp mã sinh viên tăng dần 
void SortMaSV(PtrNode pHead) {
    PtrNode p = pHead;
    while (p != NULL) {
        PtrNode pMin = MinMaSV(p);
        hoanVi(p->info, pMin->info);
        p = p->pNext;
    }
}

// Hàm sắp xếp tên sinh viên tăng dần 
void SortTenSV(PtrNode pHead) {
    PtrNode p = pHead;
    while (p != NULL) {
        PtrNode pMin = MinTen(p);
        hoanVi(p->info, pMin->info);
        p = p->pNext;
    }
}

// Hàm menu
void MeNu(int &chon) {
        cout << "CHUONG TRINH QUAN LY SINH VIEN DANH SACH LIEN KET C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them danh sach sinh vien.                     **\n";
        cout << "**  2. In danh sach sinh vien.                       **\n";
        cout << "**  3. Xoa sinh vien boi ID.                         **\n";
        cout << "**  4. Sap xep ma SV tang dan.                       **\n";
        cout << "**  5. Sap xep ten SV tang dan.                      **\n";
        cout << "**  6. Thoat.                                        **\n";
        // cout << "**  7. Hien thi danh sach sinh vien.                 **\n";
        // cout << "**  8. Ghi danh sach sinh vien vao file.             **\n";
        // cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
}




int main() {
    PtrNode pHead = NULL;
    PtrNode svCanXoa; 
    int chon;

    do {
        MeNu(chon);
        switch(chon) {
            case 1:
                nhapDanhSachSinhVien(pHead);
                break;
            case 2:
                xuatDanhSachSinhVien(pHead);
                break;
            case 3:
                int maSVCanXoa;
                cout << "Nhap ma SV can xoa: ";
                cin >> maSVCanXoa;
                svCanXoa = searchX(pHead, SinhVien{maSVCanXoa, ""});
                if (svCanXoa != NULL) {
                    DeleteNode(pHead, svCanXoa);
                    cout << "Da xoa sinh vien co ma SV " << maSVCanXoa << endl;
                } else {
                    cout << "Khong tim thay sinh vien co ma SV " << maSVCanXoa << endl;
                }
                break;
            case 4:
                SortMaSV(pHead);
                cout << "Danh sach sau khi sap xep theo ma SV:" << endl;
                xuatDanhSachSinhVien(pHead);
                break;
            case 5:
                SortTenSV(pHead);
                cout << "Danh sach sau khi sap xep theo ten SV:" << endl;
                xuatDanhSachSinhVien(pHead);
                break;
            case 6:
                // Giải phóng bộ nhớ
                while (pHead != nullptr) {
                    PtrNode sv = pHead;
                    pHead = pHead->pNext;
                    delete sv;
                }
                break;
            default:
                cout << "Lua chon khong hop le" << endl;
                break;
        }
    } while (chon != 6);

    return 0;
}