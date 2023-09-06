#include <iostream>
using namespace std;

typedef struct tagNode {
    int info;
    struct tagNode* pNext;
} Node;

typedef Node* PtrNode;

void init(PtrNode& pHead) {
    pHead = NULL;
}

bool isEmpty(PtrNode pHead) {
    return pHead == NULL;
}

PtrNode createNode(int x) {
    PtrNode p = new Node;
    p->info = x;
    p->pNext = NULL;
    return p;
}

PtrNode nodeLast(PtrNode pHead) {
    PtrNode p = pHead;
    while (p != NULL && p->pNext != NULL) {
        p = p->pNext;
    }
    return p;
}

void insertLast(PtrNode& pHead, PtrNode pNew) {
    if (isEmpty(pHead)) {
        pHead = pNew;
    } else {
        PtrNode p = nodeLast(pHead);
        p->pNext = pNew;
    }
}

void insertFirst(PtrNode& pHead, PtrNode pNew) {
    if (isEmpty(pHead)) {
        pHead = pNew;
    } else {
        pNew->pNext = pHead;
        pHead = pNew;
    }
}

void input(PtrNode& pHead) {
    int x;
    init(pHead);
    do {
        cout << "Nhap gia tri (Nhap 0 de ket thuc): ";
        cin >> x;
        if (x == 0)
            break;
        PtrNode pNew = createNode(x);
        insertFirst(pHead, pNew);
    } while (true);
}

void output(PtrNode pHead) {
    PtrNode p = pHead;
    while (p != NULL) {
        cout << p->info << "->";
        p = p->pNext;
    }
    cout << "[NULL]\n";
}
void hoanVi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

PtrNode searchX(PtrNode pHead, int x) {
    PtrNode p = pHead;
    while(p->info != x && p!=NULL)  p = p->pNext;
    return p;
}

void DeleteNode(PtrNode& pHead, PtrNode p) {
    if (!pHead || !p) {
        return;
    }

    // Bước 1: Nếu danh sách chỉ có 1 phần tử và đó là nút cần xóa (p == pHead)
    if (pHead == p) {
        pHead = nullptr;
        delete p;
        return;
    }

    PtrNode pTruoc = NULL;
    PtrNode current = pHead;

    while (current->pNext != NULL) {
        pTruoc = current;
        current = current->pNext;
    }

    // Kiểm tra nếu p là nút cuối cùng
    if (current == p) {
        delete p;
        pTruoc->pNext = NULL;
        return; // Kết thúc khi đã xóa nút cuối cùng
    }

    // Bước 3: Đặt pSau1 là nút kế tiếp của p
    PtrNode pSau1 = p->pNext;
    if (pSau1) {
        PtrNode pSau2 = pSau1->pNext;

        // Bước 4: Hoán đổi dữ liệu giữa p và pSau1
        hoanVi(p->info, pSau1->info);

        // Bước 5: Cập nhật con trỏ Next của p
        p->pNext = pSau2;

        // Bước 6: Xóa nút pSau1
        delete pSau1;
    }
}

void insertNodeAtPosition(PtrNode& pHead, int x, int position) {
    if (position == 0 || isEmpty(pHead)) {
        PtrNode pNew = createNode(x);
        pNew->pNext = pHead;
        pHead = pNew;
    } else {
        PtrNode pPrev = NULL;
        PtrNode pCurrent = pHead;
        int currentPosition = 0;

        while (pCurrent != NULL && currentPosition < position) {
            pPrev = pCurrent;
            pCurrent = pCurrent->pNext;
            currentPosition++;
        }

        PtrNode pNew = createNode(x);
        pPrev->pNext = pNew;
        pNew->pNext = pCurrent;
    }
}

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

    input(pHead);

    cout << "Danh sach lien ket truoc khi sap xep: ";
    output(pHead);

    int valueToDelete = 3;
    PtrNode nodeToDelete = searchX(pHead, valueToDelete); // 
    if (nodeToDelete != NULL) {
        // Gọi hàm DeleteNode để xóa nút
        DeleteNode(pHead, nodeToDelete);
        cout << "Danh sach lien ket sau khi xoa: ";
        // Gọi hàm output để in ra danh sách sau khi xóa
        output(pHead);
    } else {
        cout << "Khong tim thay node can xoa." << endl;
    }

    int x,position;
    cout << "\nNhap gia tri can chen: ";
    cin >> x;
    cout << "Nhap vi tri can chen (tu 0 tro len): ";
    cin >> position;

    insertNodeAtPosition(pHead, x, position);

    cout << "Danh sach lien ket sau khi chen: ";
    output(pHead);

    // Sắp xếp
    Sort(pHead);
    cout << "Danh sach lien ket sau khi sap xep: ";
    output(pHead);

    // Giải phóng bộ nhớ
    while (pHead != NULL) {
        PtrNode temp = pHead;
        pHead = pHead->pNext;
        delete temp;
    }

    return 0;
}
