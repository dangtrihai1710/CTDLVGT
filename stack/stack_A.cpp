#include <iostream>
#include <cstring>
#define MAXSTACK 100
using namespace std;

struct Stack {
    int top;
    int nodes[MAXSTACK];
};

void Init(Stack &s) {
    s.top = -1;
}

bool IsEmpty(Stack s) {
    return (s.top == -1);
}

bool IsFull(Stack s) {
    return (s.top == MAXSTACK-1);
}

void Push(Stack &s, int x)  {
    if(IsFull(s))
        cout << "\nStack da day. khong the them: "<< x << endl;
    else 
        s.nodes[++s.top] = x;
}

int Pop(Stack &s) {
    if(IsEmpty(s))  return 0;
    else {
        int x = s.nodes[s.top--];
        return 1;
    }
}

void CopyStack(Stack &dest, Stack &src) {
    Stack temp;
    Init(temp);

    while (!IsEmpty(src)) {
        int topValue = src.nodes[src.top];
        src.top--; // Giảm top để loại bỏ phần tử từ stack gốc
        Push(temp, topValue); // Đẩy giá trị vào stack tạm thời
    }

    while (!IsEmpty(temp)) {
        int topValue = temp.nodes[temp.top];
        temp.top--; // Giảm top của stack tạm thời
        Push(dest, topValue); // Đẩy giá trị vào stack đích
    }
}

int main() {
    Stack myStack;
    Init(myStack);

    Push(myStack, 1);
    Push(myStack, 2);
    Push(myStack, 3);

    Stack copiedStack;
    Init(copiedStack);

    // Sao chép stack gốc sang stack mới
    CopyStack(copiedStack, myStack);

    // In ra các phần tử của stack mới
    while (!IsEmpty(copiedStack)) {
        int val = copiedStack.nodes[copiedStack.top];
        cout << val << " ";
        copiedStack.top--; // Giảm top để lấy phần tử tiếp theo
    }

    return 0;
}
