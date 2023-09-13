#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Sinhvien {
    char masv[10];
    char hoten[40];
    float dtb;
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

// Hàm thêm phần tử mới vào đầu danh sách
void insertFirst(PtrNode& pHead, PtrNode pNew) {
    if (isEmpty(pHead)) {
        pHead = pNew;
    } else {
        pNew->pNext = pHead;
        pHead = pNew;
    }
}

// Hàm nhập 1 sinh viên 
void Nhap1SV(SV &x) {
        printf("Nhap ma SV: ");
        fflush(stdin);
        gets(x.masv);
        printf("Nhap ho Ten: ");
        fflush(stdin); // Xóa bộ nhớ đệm của stdin trước khi nhập chuỗi
        gets(x.hoten);
        printf("Nhap diem trung binh: ");
        scanf("%f", &x.dtb);
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(PtrNode& pHead) {
    SV x;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien thu %d: \n", i + 1);
        Nhap1SV(x);
        PtrNode svMoi = createNode(x);
        insertFirst(pHead, svMoi);
    }
}

// Hàm xuất 1 sinh viên
void xuat1SV(PtrNode pHead) {
        printf("Ma SV: %s, Ho Ten: %s, Diem trung binh: %0.2f\n", pHead->info.masv, pHead->info.hoten, pHead->info.dtb);
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(PtrNode pHead) {
    PtrNode current = pHead;
    int i = 0;
    printf("Xuat danh sach sinh vien:\n");
    while (current != NULL) {
        printf("Sinh vien thu %d:\n", i + 1);
        xuat1SV(current);
        current = current->pNext;
        i++;
    }
}

// Hàm xuất danh sách sinh viên có điểm trung bình > 5
void xuatDanhSachSinhVienDiemTren5(PtrNode pHead) {
    PtrNode current = pHead;
    int i = 0;
    printf("Xuat danh sach sinh vien co diem tren 5:\n");
    while (current != NULL) {
        if (current->info.dtb > 5.0) {
            printf("Sinh vien thu %d\n", i + 1);
            printf("Ma SV: %s, Ho Ten: %s, Diem trung binh: %.2f\n", current->info.masv, current->info.hoten, current->info.dtb);
        }
        current = current->pNext;
        i++;
    }
}


// Hàm tìm sinh viên theo mã
PtrNode timSinhVienTheoMaX(const PtrNode pHead, char ma[10]) {
    PtrNode current = pHead;
    while (current != NULL) {
        if (strcmp(current->info.masv, ma) == 0) {
            return current; 
        }
        current = current->pNext;
    }
    return NULL; 
}


// Hàm hoán vị
void hoanVi(SV& a, SV& b) {
    SV temp = a;
    a = b;
    b = temp;
}

// Phần tử nhỏ nhất trong danh sách
PtrNode Min(PtrNode pHead) {
    PtrNode nodeMin = pHead;
    PtrNode p = pHead->pNext;
    while (p != NULL) {
        if (nodeMin->info.dtb > p->info.dtb) 
            nodeMin = p;       
        p = p->pNext;
    }
    return nodeMin;
}

// Hàm sắp xếp tăng dần phương pháp Interchange Sort
void Sort(PtrNode pHead) {
    PtrNode p = pHead;
    while (p != NULL) {
        PtrNode pMin = Min(p);
        hoanVi(p->info, pMin->info);
        p = p->pNext;
    }
}

// Hàm thêm sinh viên vào sau sinh viên có mã X
void themSinhVienSauMaX(PtrNode& pHead, char ma[10], SV svMoi) {
    PtrNode nodeX = timSinhVienTheoMaX(pHead, ma);
    if (nodeX == NULL) {
        printf("Khong tim thay sinh vien co ma SV \"%s\", khong the them.\n", ma);
        return;
    }

    PtrNode svMoiNode = createNode(svMoi);

    svMoiNode->pNext = nodeX->pNext;

    nodeX->pNext = svMoiNode;

    printf("Da them sinh vien moi sau sinh vien co ma SV \"%s\".\n", ma);
}


// Hàm xóa sinh viên đầu danh sách
void xoaSinhVienDauDanhSach(PtrNode &pHead) {
    if (isEmpty(pHead)) {
        printf("Danh sach rong, khong co sinh vien de xoa.\n");
        return;
    }

    PtrNode temp = pHead;
    pHead = pHead->pNext;
    delete temp;
    printf("Da xoa sinh vien dau danh sach.\n");
}

// Hàm xóa sinh viên cuối danh sách
void xoaSinhVienCuoiDanhSach(PtrNode &pHead) {
    if (isEmpty(pHead)) {
        printf("Danh sach rong, khong co sinh vien de xoa.\n");
        return;
    }

    if (pHead->pNext == NULL) {
        delete pHead;
        pHead = NULL;
        printf("Da xoa sinh vien cuoi danh sach.\n");
        return;
    }

    PtrNode current = pHead;
    PtrNode previous = NULL;

    while (current->pNext != NULL) {
        previous = current;
        current = current->pNext;
    }

    previous->pNext = NULL;
    free(current);
    printf("Da xoa sinh vien cuoi danh sach.\n");
}


// Hàm xóa toàn bộ danh sách sinh viên
void xoaDanhSachSinhVien(PtrNode& pHead) {
    PtrNode current = pHead;
    PtrNode next;

    while (current != NULL) {
        next = current->pNext; // Lưu trữ con trỏ đến nút tiếp theo trước khi giải phóng nút hiện tại
        delete current; // Giải phóng bộ nhớ của nút hiện tại
        current = next; // Di chuyển đến nút tiếp theo trong danh sách
    }

    pHead = NULL; 
    printf("Da xoa toan bo danh sach sinh vien.\n");
}


// Hàm xóa sinh viên có mã x
void xoaSinhVienTheoMa(PtrNode& pHead, char ma[10]) {
    if (isEmpty(pHead)) {
        printf("Danh sach rong, khong co sinh vien de xoa.\n");
        return;
    }

    PtrNode current = pHead;
    PtrNode previous = NULL;

    while (current != NULL) {
        if (strcmp(current->info.masv, ma) == 0) {
            // Tìm thấy sinh viên có mã x
            if (previous != NULL) {
                previous->pNext = current->pNext; // Thay đổi con trỏ của nút trước nó để bỏ qua nút hiện tại
            } else {
                // Nếu nút hiện tại là nút đầu danh sách
                pHead = current->pNext; // Thay đổi con trỏ đầu danh sách
            }
            free(current); // Giải phóng bộ nhớ của sinh viên bị xóa
            printf("Da xoa sinh vien co ma SV \"%s\".\n", ma);
            return;
        }
        previous = current;
        current = current->pNext;
    }

    // Không tìm thấy sinh viên có mã x
    printf("Khong tim thay sinh vien co ma SV \"%s\".\n", ma);
}


int main() {
    PtrNode pHead;
    init(pHead);
    nhapDanhSachSinhVien(pHead);
    xuatDanhSachSinhVien(pHead);

    printf("\nDanh sach sinh vien co diem trung binh tren 6: ");
    xuatDanhSachSinhVienDiemTren5(pHead);

    // Tìm sinh viên theo mã
    printf("********************************\n");
    char maTimKiem[10];
    printf("Nhap ma SV can tim: ");
    fflush(stdin);
    gets(maTimKiem);
    PtrNode svTimThay = timSinhVienTheoMaX(pHead, maTimKiem);

    if (svTimThay != NULL) {
        printf("Da tim thay sinh vien co ma SV \"%s\":\n", maTimKiem);
        xuat1SV(svTimThay); // Xuất thông tin của sinh viên tìm thấy
    } else {
        printf("Khong tim thay sinh vien co ma SV \"%s\"\n", maTimKiem);
    }

    // Hàm sắp xếp tăng dần phương pháp Interchange Sort
    printf("********************************\n");
    Sort(pHead);
    printf("\nDanh sach sau khi sap xep diem trung binh SV tang dan: ");
    xuatDanhSachSinhVien(pHead);

    char maX[10];
    printf("Nhap ma SV can tim de them sau: ");
    fflush(stdin);
    gets(maX);

    SV svMoi;
    Nhap1SV(svMoi); // Nhập thông tin cho sinh viên mới

    // Thêm sinh viên mới vào sau sinh viên có mã X
    themSinhVienSauMaX(pHead, maX, svMoi);

    // Xuất danh sách sau khi thêm
    xuatDanhSachSinhVien(pHead);
    
    printf("********************************\n");
    xoaSinhVienDauDanhSach(pHead);
    printf("\nXóa sinh viên đầu danh sách: ");

    printf("********************************\n");
    xuatDanhSachSinhVien(pHead);
    // Xóa sinh viên cuối danh sách
    xoaSinhVienCuoiDanhSach(pHead);
    printf("\nXóa sinh viên cuối danh sách: ");
    // Xuất danh sách sau khi xóa
    xuatDanhSachSinhVien(pHead);

    printf("********************************\n");
    char maXoa[10];
    printf("\nXoa sinh vien theo ma x: ");
    printf("Nhap ma SV can xoa: ");
    fflush(stdin);
    gets(maXoa);
    // Xóa sinh viên có mã x
    xoaSinhVienTheoMa(pHead, maXoa);
    // Xuất danh sách sau khi xóa
    xuatDanhSachSinhVien(pHead);


    return 0;
}




