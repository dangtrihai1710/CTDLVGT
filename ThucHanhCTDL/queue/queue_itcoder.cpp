#include <iostream>
using namespace std;

// Khai bao cau truc du lieu benh nhan
typedef struct benhnhan {
    int soThuTu;
    char hoten[50];
    int tuoi;
}BenhNhan;

// Khai bao cau truc du lieu cho Node
typedef struct node {
    BenhNhan info;
    struct node* pNext;
}Node;

// Khai bao cau truc du lieu cho Queue
typedef struct QUEUE {
    Node* pHead;
    Node* pTail;
}Queue;

// Ham khoi tao Queue
void Init(Queue& q) {
    q.pHead = q.pTail = NULL;
}

// Ham kiem tra rong
int IsEmpty(Queue *q) {
    return (q->pHead == NULL);
}

// Them benh nhan vao Queue
void Insert(Queue* q, BenhNhan bn) {
    Node* newNode = new Node;
    newNode->info = bn;
    newNode->pNext = NULL;
    if(IsEmpty(q)) 
        q->pHead = q->pTail = newNode;
    else {
        q->pTail->pNext = newNode;
        q->pTail = newNode;
    }
}

// Lay benh nhan tiep theo se kham
BenhNhan Remove(Queue *q, int &dakham) {
    if(IsEmpty(q)) {
        BenhNhan empty = {-1, "", -1}; // Gia tri mac dinh Queue rong
        return empty;
    } else {
        Node* temp = q->pHead;
        BenhNhan bn = temp->info;
        q->pHead = q->pHead->pNext;
        free(temp);
        // Tang bien dem so nguoi da kham
        dakham++;
        return bn;
    }
}

// Xuất danh sách bệnh nhân còn lại trong hàng đợi cho khám
void DisplayQueue(Queue* q) {
    if (IsEmpty(q)) {
        cout << "Hien tai khong co benh nhan trong hang doi cho kham.\n";
        return;
    }

    Node* currentNode = q->pHead;
    cout << "Danh sach benh nhan trong hang doi cho kham:\n";

    while (currentNode != NULL) {
        BenhNhan bn = currentNode->info;
        cout << "So thu tu: " << bn.soThuTu << "\n";
        cout << "Ho ten: " << bn.hoten << "\n";
        cout << "Tuoi: " << bn.tuoi << "\n\n";
        currentNode = currentNode->pNext;
    }
}




int main() {
    Queue queue;
    Init(queue);
    int choice;
    int soThuTu = 1;
    int daKham = 0; // Bien dem so nguoi da kham

    while(1) {
        cout << "\nMenu:\n";
        cout << "1. Them benh nhan vao hang doi\n";
        cout << "2. Lay benh nhan tiep theo cho kham\n";
        cout << "3. So luong nguoi da kham\n";
        cout << "4. Xuat danh sach benh nhan cho kham\n";
        cout << "5. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                BenhNhan bn;
                bn.soThuTu = soThuTu++;
                cout << "Nhap ho ten benh nhan: ";
                fflush(stdin);
                gets(bn.hoten);
                cout << "Nhap tuoi: ";
                cin >> bn.tuoi;
                Insert(&queue, bn);
                cout << "Them benh nhan thanh cong:\n";
                break;
            case 2:
                if(!IsEmpty(&queue)) {
                    BenhNhan bn = Remove(&queue, daKham);
                    cout << "Benh nhan tiep theo cho kham:\n";\
                    cout << "So thu tu: " << bn.soThuTu << "Hoten: " << bn.hoten << "Tuoi: " << bn.tuoi;
                } else 
                    cout <<"Khong con benh nhan nao cho kham:\n";
                break;
            case 3:
                cout << "So luong nguoi da kham: " << daKham;
                break;
            case 4:
                DisplayQueue(&queue);
                break;
            case 5:
                cout << "Ket thuc chuong trinh.\n";
                exit(0);
            default:
                cout << "Chon chuc nang khong hop le. Vui long chon lai!\n";
        }
    }

    return 0;
}