#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* pNext;
} Node;

typedef Node* PtrNode;

// Hàm khởi tạo pHead
void init(PtrNode &pHead) {
    pHead = NULL;
}

// Hàm kiểm tra rỗng
int isEmpty(PtrNode pHead) {
    return pHead == NULL;
}

// Hàm tạo 1 node có dữ liệu là x
PtrNode createNode(int x) {
    PtrNode p;
    p = new Node;

    if (p == NULL) {
        printf("Khong du bo nho cho viec cap phat node moi.\n");
        return 0;
    }

    p->info = x;
    p->pNext = NULL;
    return p;
}

// Hàm thêm phần tử mới vào đầu danh sách
void insertFirst(PtrNode &pHead, PtrNode pNew) {
    if (isEmpty(pHead))
        pHead = pNew;
    else {
        pNew->pNext = pHead;
        pHead = pNew;
    }
}

//Hàm nhập danh sách
void input(PtrNode &pHead) {
    init(pHead);
    int n, x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap so can them vao danh sach: ");
        scanf("%d", &x);
        PtrNode pNew = createNode(x);
        insertFirst(pHead, pNew);
    }
}

// Hàm xuất danh sách ra màn hình
void printList(PtrNode pHead) {
    printf("Danh sach lien ket: ");
    while (pHead != NULL) {
        printf("%d ", pHead->info);
        pHead = pHead->pNext;
    }
    printf("\n");
}

// Hàm chèn nút mới sau nút chứa x
void insertAfterX(PtrNode &pHead, int x, int y) {
    PtrNode pCurrent = pHead;

    while (pCurrent != NULL && pCurrent->info != x) {
        pCurrent = pCurrent->pNext;
    }

    if (pCurrent == NULL) {
        printf("Khong tim thay phan tu %d trong danh sach.\n", x);
    } else {
        PtrNode pNew = createNode(y);
        pNew->pNext = pCurrent->pNext;
        pCurrent->pNext = pNew;
    }
}

int countNodes(PtrNode pHead) {
    int count = 0;
    PtrNode pCurrent = pHead;

    while (pCurrent != NULL) {
        count++;
        pCurrent = pCurrent->pNext;
    }

    return count;
}

// Giá trị của node thứ k trong danh sách
int getNodeValue(PtrNode pHead, int k) {
    int count = 0;
    PtrNode pCurrent = pHead;

    while (pCurrent != NULL) {
        count++;
        if (count == k) return pCurrent->info;
        pCurrent = pCurrent->pNext;
    }
    return -1; 
}

// Phần tử nhỏ nhất trong danh sách
PtrNode Min(PtrNode pHead) {
    PtrNode nodeMin = pHead;
    PtrNode p = pHead->pNext;
    while (p != NULL) {
        if (nodeMin->info > p->info) 
            nodeMin = p;       
        p = p->pNext;
    }
    return nodeMin;
}

// Phần tử lớn nhất trong danh sách
PtrNode Max(PtrNode pHead) {
    PtrNode nodeMax = pHead;
    PtrNode p = pHead->pNext;
    while (p != NULL) {
        if (nodeMax->info < p->info) 
            nodeMax = p;       
        p = p->pNext;
    }
    return nodeMax;
}

// Xóa 1 phần tử có khóa k
void deleteNode(PtrNode &pHead, int k) {
    PtrNode pCurrent = pHead;
    PtrNode pPrevious = NULL;

    while (pCurrent != NULL && pCurrent->info != k) {
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (pCurrent != NULL) {
        if (pPrevious != NULL) {
            pPrevious->pNext = pCurrent->pNext;
        } else {
            pHead = pCurrent->pNext;
        }
        delete pCurrent; 
    } else {
        printf("Khong tim thay node co khoa %d trong danh sach.\n", k);
    }
}
// Hàm hoán vị 2 số nguyên
void hoanVi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
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

int main() {
    PtrNode pHead = NULL;
    int x, y, k;
    input(pHead);

    // Xuất danh sách liên kết ra màn hình
    printList(pHead);

    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    printf("Nhap gia tri y: ");
    scanf("%d", &y);

    // Chèn y sau x nếu tìm thấy x
    insertAfterX(pHead, x, y);

    // Đếm số nút trên danh sách
    int nodeCount = countNodes(pHead);
    printf("So luong phan tu tren danh sach: %d\n", nodeCount);   

    // Lấy giá trị của node thứ k
    printf("Nhap vi tri node k: ");
    scanf("%d", &k);
    int nodeValue = getNodeValue(pHead, k);
    
    if (nodeValue != -1) {
        printf("Gia tri cua node thu %d la: %d\n", k, nodeValue);
    } else {
        printf("Khong tim thay node thu %d trong danh sach.\n", k);
    }


    // Phần tử nhỏ nhất trong danh sách
    PtrNode minNode = Min(pHead);

    if (minNode != NULL) {
        printf("Gia tri lon nhat trong danh sach la: %d\n", minNode->info);
    } else {
        printf("Danh sach lien ket rong.\n");
    }


    // Phần tử lớn nhất trong danh sách
    PtrNode maxNode = Max(pHead);

    if (maxNode != NULL) {
        printf("Gia tri lon nhat trong danh sach la: %d\n", maxNode->info);
    } else {
        printf("Danh sach lien ket rong.\n");
    }

    // Xóa 1 phần tử có khóa k
    deleteNode(pHead, k);
    printf("\nDSLK sau khi xoa: ");
    printList(pHead);

    // Hàm sắp xếp tăng dần phương pháp Interchange Sort
    Sort(pHead);
    printf("\nDSLK sau khi sap xep tang dan: ");
    printList(pHead);


    return 0;
}
