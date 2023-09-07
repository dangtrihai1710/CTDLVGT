#include <iostream>
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


// Sắp xếp
PtrNode Min(PtrNode pHead) {
    PtrNode nodeMin = pHead;
    PtrNode p = pHead->pNext;
    while (p != NULL) {
        if (nodeMin->info.maSV > p->info.maSV)
            nodeMin = p;       
        p = p->pNext;
    }
    return nodeMin;
}

void Sort(PtrNode pHead) {
    PtrNode p = pHead;
    while (p != NULL) {
        PtrNode pMin = Min(p);
        hoanVi(p->info, pMin->info);
        p = p->pNext;
    }
}





int main() {
    PtrNode pHead = NULL;

    nhapDanhSachSinhVien(pHead);

    // Hiển thị danh sách sinh viên
    xuatDanhSachSinhVien(pHead);

    int maSVCanXoa;
    cout << "Nhap ma SV can xoa: ";
    cin >> maSVCanXoa;

    PtrNode svCanXoa = searchX(pHead, SV{maSVCanXoa, ""}); // Tạo một đối tượng SV tạm thời với mã sinh viên cần xóa
    if (svCanXoa != NULL) {
        DeleteNode(pHead, svCanXoa);
        cout << "Da xoa sinh vien co ma SV " << maSVCanXoa << endl;
    } else {
        cout << "Khong tim thay sinh vien co ma SV " << maSVCanXoa << endl;
    }
    // Hiển thị danh sách sinh viên sau khi xóa
    xuatDanhSachSinhVien(pHead);

    // // Sắp xếp
    Sort(pHead);
    cout << "------Danh sach lien ket sau khi sap xep------:" << endl;
    xuatDanhSachSinhVien(pHead);

    //Giải phóng bộ nhớ
    while (pHead != nullptr) {
        PtrNode sv = pHead;
        pHead = pHead->pNext;
        delete sv;
    }   

    return 0;
}