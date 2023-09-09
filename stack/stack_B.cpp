#include <iostream>
#include <cstring>
#define MAXSTACK 100
using namespace std;

typedef struct node {
    int info;
    struct node *pNext;
}Node;

typedef Node *PtrNode;
typedef PtrNode Stack;
Stack s;

void Init(Stack &s) {
    s = NULL ;
}

bool IsEmpty(Stack s) {
    return (s == NULL);
}

int Push(Stack &s, int x)  {
    PtrNode p = new Node;
    if(IsEmpty(p)) return 0;
    p->info = x;
    p->pNext = s;
    s = p;
    return 1;
}

int Pop(Stack &s, int &x) {
    if(IsEmpty(s))  return 0;
    PtrNode p = s;
    x=p->info;
    s=s->pNext;
    delete p;
    return 1;
}

int CopyStack(PtrNode s, PtrNode &dest) {
    if (IsEmpty(s)) return 0; // Nếu stack nguồn rỗng, không có gì để sao chép.

    dest = NULL;

    // Con trỏ dùng để duyệt stack nguồn
    PtrNode p = s;

    // Con trỏ dùng để duyệt và xây dựng stack đích
    PtrNode q = NULL;

    while (p != NULL) {
        PtrNode newNode = new Node;
        if (newNode == NULL) return 0; // Kiểm tra việc cấp phát bộ nhớ

        newNode->info = p->info;
        newNode->pNext = NULL;

        if (dest == NULL) {
            dest = newNode; // Nếu đây là phần tử đầu tiên, thiết lập đỉnh của stack đích
            q = dest;
        } else {
            q->pNext = newNode; // Liên kết phần tử mới vào stack đích
            q = q->pNext; // Di chuyển con trỏ đến phần tử mới trong stack đích
        }

        p = p->pNext; // Di chuyển con trỏ đến phần tử tiếp theo trong stack nguồn
    }

    return 1;
}


int main() {
    PtrNode sourceStack = nullptr; // Khởi tạo stack nguồn
    Push(sourceStack, 1);
    Push(sourceStack, 2);
    Push(sourceStack, 3);

    PtrNode destinationStack = nullptr; // Khởi tạo stack đích

    if (CopyStack(sourceStack, destinationStack)) {
        // In ra các phần tử từ stack đích (destinationStack)
        PtrNode temp = destinationStack;
        while (temp != nullptr) {
            cout << temp->info << " ";
            temp = temp->pNext;
        }
        // Giải phóng bộ nhớ của stack đích nếu cần
        while (destinationStack != nullptr) {
            PtrNode temp = destinationStack;
            destinationStack = destinationStack->pNext;
            delete temp;
        }
    } else {
        cout << "Sao chép không thành công." << endl;
    }

    return 0;
}