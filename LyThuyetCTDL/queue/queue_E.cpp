#include <iostream>
#include <cstring>
#define MAXQUEUE 100
using namespace std;

typedef struct queue{
    int front, rear;
    int node[MAXQUEUE];
}Queue;

void Init(Queue &q) {
    q.front = q.rear = -1;
}

int IsEmpty(Queue &q) {
    return (q.front == -1);
}

int IsFull(Queue &q) {
    return ((q.rear - q.front+1) % MAXQUEUE == 0);
}

int enQueue(Queue &q, int x) {
    if(IsFull(q)) return 0; // Full Queue
    else {
        if(IsEmpty(q)) q.front = 0;
        q.rear = (q.rear + 1) % MAXQUEUE; 
        q.node[q.rear] = x;
        return 1;
    }
} 

// In 5 giá trị đầu trong hàng đợi
void PrintQueue(Queue &q) {
    if (IsEmpty(q)) {
        cout << "Hien tai hang doi dang rong." << endl;
        return;
    }

    int current = q.front;
    cout << "Cac gia tri trong hang doi:" << endl;
    while (current != 4) {
        cout << q.node[current] << " ";
        current = (current + 1) % MAXQUEUE;
    }
    cout << q.node[current] << endl;
}



int main() {
    Queue q;
    Init(q); // Khởi tạo hàng đợi

    int n;
    cout << "\nNhap so luong phan tu hang doi: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (enQueue(q, i)) {
            cout << "Enqueued: " << i << endl;
        } else {
            cout << "Queue is full, unable to enqueue: " << i << endl;
        }
    }

    cout << "\n5 gia tri dau trong hang doi: ";
    PrintQueue(q);

    if (!IsEmpty(q)) {
        cout << "Gia tri dau cua Queue: " << q.node[q.front] << endl;
        cout << "Gia tri cuoi cua Queue: " << q.node[q.rear] << endl;
    } else {
        cout << "Queue hien tai dang rong, khong co gia tri dau hoac cuoi." << endl;
    }

    return 0;
}