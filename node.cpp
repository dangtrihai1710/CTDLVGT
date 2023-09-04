#include <iostream>
using namespace std;

typedef struct tagNode {
    float info;
    struct tagNode* pNext;
} Node;

typedef Node* PtrNode;

void init(PtrNode& pHead) {
    pHead = NULL;
}

bool isEmpty(PtrNode pHead) {
    return pHead == NULL;
}

PtrNode createNode(float x) {
    PtrNode p;
    p = new Node;

    p->info = x;
    p->pNext = NULL;
    return p;
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
    float x;
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

int countNodes(PtrNode pHead) {
    int count = 0;
    PtrNode p = pHead;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

float nodeMax(PtrNode pHead) {
    if(isEmpty(pHead)) {
        cout << "Danh sach rong. Khong co node lon nhat." << endl;
        return 0;       
    }
    float pMax = pHead->info;
    PtrNode p = pHead; 
    while(p != NULL) {
        if(p->info > pMax) 
            pMax = p->info;
        p= p->pNext;
    }
    return pMax;
} 

int searchX(PtrNode pHead, float x) {
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

void showListEven(PtrNode pHead) {
    PtrNode p = pHead;
    int i = 0;
    while (p != NULL) {
        if (i % 2 == 0) {
            cout << p->info << "->";
        }
        p = p->pNext;
        i++;
    }
    cout << "[NULL]\n";
}

float averageNode(PtrNode pHead) {
    if (isEmpty(pHead) || pHead->pNext == NULL) {
        cout << "Danh sach khong co du node hoac chi co 1 node. Khong the tinh trung binh." << endl;
        return 0; 
    }

    float sum = 0;
    int count = 0;
    PtrNode p = pHead;
    int i = 0;
    while (p != NULL) {
        if (i % 2 != 0) { 
            sum += p->info;
            count++;
        }
        p = p->pNext;
        i++;
    }

    if (count == 0) {
        cout << "Khong co node o vi tri le trong danh sach." << endl;
        return 0; 
    }

    return sum / count;
}



int main() {
    PtrNode pHead = NULL;
    input(pHead);
    cout << "Danh sach lien ket: ";
    output(pHead);
    cout << "1.So luong Node trong dslk: " << countNodes(pHead) << endl;
    cout << "2.Node co gia tri lon nhat: " << nodeMax(pHead) << endl;
    float x;
    cout << "Nhap gia tri x can tim: ";
    cin >> x;
    cout << "3.Vi tri Node co gia tri x: " << searchX(pHead,x) << endl;
    cout << "4.In Node co gia tri chan: ";
    showListEven(pHead);
    cout << "5.Gia tri trung binh cong cac Node le: " << averageNode(pHead) << endl;

    // Giải phóng bộ nhớ
    while (pHead != NULL) {
        PtrNode temp = pHead;
        pHead = pHead->pNext;
        delete temp;
    }

    return 0;
}
