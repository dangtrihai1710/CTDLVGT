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
    PtrNode p;
    p = new Node;

    p->info = x;
    p->pNext = NULL;
    return p;
}

PtrNode nodeLast(PtrNode pHead) {
    PtrNode p = pHead;
    while(p->pNext != NULL) {
        p = p->pNext;
    }
    return p;
}

void insertLast(PtrNode& pHead, PtrNode pNew) {
    if (isEmpty(pHead))
        pHead = pNew;
    else {
        PtrNode p =nodeLast(pHead);
        p->pNext = pNew;
    }
}

void insertFirst(PtrNode& pHead, PtrNode pNew) {
    if (isEmpty(pHead))
        pHead = pNew;
    else {
        pNew->pNext = pHead;
        pHead = pNew;
    }
}

PtrNode input(PtrNode& pHead) {
    int x;
    init(pHead);
    do {
        cout << "Nhap gia tri (Nhap 0 ket thuc): ";
        cin >> x;
        if (x == 0)
            break;
        PtrNode pNew = createNode(x);
        insertFirst(pHead, pNew);
    } while (true);
    return pHead;
}

void output(PtrNode pHead) {
    PtrNode p = pHead;
    while (p != NULL) {
        cout << p->info << "->";
        p = p->pNext;
    }
    cout << "[NULL]\n";
}

void removeP(PtrNode& pHead, PtrNode p) {
    PtrNode prevNode = pHead;
    if (pHead == NULL || p == NULL) {
        return;
    }

    if (pHead == p && p->pNext == NULL) {
        delete p;
        pHead = NULL;
        return;
    }

    // if()

}

void insertNodeAtPosition(PtrNode &pHead, int x, int position) {
    PtrNode pNew = createNode(x); 
    if (position == 0) {
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
        pPrev->pNext = pNew;
        pNew->pNext = pCurrent;
    }
}

int searchX(PtrNode pHead, int x) {
    PtrNode p = pHead;
    int i = 0;
    while (p != NULL && p->info != x) {
        p = p->pNext;
        i++;
    }
    if (p == NULL) {
        return -1; 
    }
    return i;
}

void sort(PtrNode &pHead) {
    PtrNode p, q, pmin;
    int min;
    for (p = pHead; p->pNext != NULL; p = p->pNext) {
        min = p->info;
        pmin = p;
        for (q = p->pNext; q != NULL; q = q->pNext) {
            if (q->info < min) {
                min = q->info;
                pmin = q;
            }
        }
        pmin->info = p->info;
        p->info = min;
    }
}





int main() {
    PtrNode pHead = NULL;
    input(pHead);
    
    cout << "Danh sach lien ket truoc khi sap xep: ";
    output(pHead);

    int x, position;

    cout << "\nNhap gia tri can chen: ";
    cin >> x;
    cout << "Nhap vi tri can chen (tu 0 tro len): ";
    cin >> position;


    insertNodeAtPosition(pHead, x, position);

    cout << "Danh sach lien ket sau khi chen: ";
    output(pHead);

    cout << "\nNhap gia tri x can tim kiem: ";
    cin >> x;
    
    position = searchX(pHead, x);
    if (position == -1) {
        cout << "Khong tim thay gia tri " << x << " trong danh sach.\n";
    } else {
        cout << "3. Vi tri Node co gia tri x: " << position << endl;
    }

    // Sắp xếp
    sort(pHead);
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

