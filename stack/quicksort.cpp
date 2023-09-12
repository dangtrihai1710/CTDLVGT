#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

struct Stack {
    int top;
    int nodes[100]; 
};

void Push(Stack &s, int x)  {
    if(s.top >= 99)
        cout << "\nStack da day. Khong the them: "<< x << endl;
    else 
        s.nodes[++s.top] = x;
}

int Pop(Stack &s) {
    if(s.top < 0) {
        cout << "\nStack rong. Khong the lay phan tu." << endl;
        return 0;
    } else {
        int x = s.nodes[s.top--];
        return x;
    }
}

void quickSort(int arr[], int low, int high) {
    Stack s;
    s.top = -1;

    Push(s, low);
    Push(s, high);

    while (s.top >= 0) {
        high = Pop(s);
        low = Pop(s);

        int pivot = partition(arr, low, high);

        if (pivot - 1 > low) {
            Push(s, low);
            Push(s, pivot - 1);
        }

        if (pivot + 1 < high) {
            Push(s, pivot + 1);
            Push(s, high);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 10, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, size);

    return 0;
}
