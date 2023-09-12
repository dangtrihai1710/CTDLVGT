#include <iostream>

using namespace std;

// Khai báo cấu trúc Node để biểu diễn một nút trong danh sách liên kết đơn
struct Node {
    int data;
    Node* pNext;
};

// Khai báo cấu trúc Queue để biểu diễn hàng đợi
struct Queue {
    Node* front; // Phần tử đầu hàng đợi
    Node* rear;  // Phần tử cuối hàng đợi
};

// Hàm khởi tạo một hàng đợi rỗng
void initQueue(Queue& q) {
    q.front = q.rear = NULL;
}

// Hàm kiểm tra hàng đợi rỗng
bool isEmpty(const Queue& q) {
    return q.front == NULL;
}

// Hàm thêm một phần tử vào cuối hàng đợi
int enqueue(Queue& q, int data) {
    Node* newNode = new Node{data, NULL};
    if (isEmpty(q)) {
        q.front = q.rear = newNode;
    } else {
        q.rear->pNext = newNode;
        q.rear = newNode;
    }
    return 1;
}

// Hàm in phần tử hàng đợi
void printQueue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Hàng đợi rỗng!" << endl;
        return;
    }

    Node* current = q.front;
    int i = 0;
    cout << "Cac gia tri trong hang doi:" << endl;
    while (current != NULL && i != 5) {
        cout << current->data << " ";
        current = current->pNext;
        i++;
    }
    cout << endl;
}

int main() {
    Queue q;
    initQueue(q);

    // Thêm các phần tử vào hàng đợi
    int n;
    cout << "\nNhap so luong phan tu hang doi: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (enqueue(q, i)) {
            cout << "Enqueued: " << i << endl;
        } else {
            cout << "Queue is full, unable to enqueue: " << i << endl;
        }
    }

    printQueue(q);

    // Hiển thị phần tử đầu hàng đợi
    if (!isEmpty(q)) {
        cout << "Phan tu dau hang doi: " << q.front->data << endl;
        cout << "Phan tu cuoi hang doi: " << q.rear->data << endl;
    } else {
        cerr << "Hàng đợi rỗng!" << endl;
    }



    return 0;
}
