#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Định nghĩa cấu trúc Node cho cây nhị phân tìm kiếm
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef Node *PtrNode;

// Hàm để tạo một Node mới
PtrNode createNode(int data) {
    PtrNode newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm để chèn một nút mới vào cây nhị phân tìm kiếm
PtrNode insert(PtrNode root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Hàm kiểm tra xem cây con có phải là cây nhị phân đúng không
bool isBinarySearchTreeUtil(PtrNode node, int min, int max) {
    if (node == NULL) {
        return true;
    }

    if (node->data < min || node->data > max) {
        return false;
    }

    return (isBinarySearchTreeUtil(node->left, min, node->data - 1) &&
            isBinarySearchTreeUtil(node->right, node->data + 1, max));
}

// Hàm kiểm tra xem cây có phải là cây nhị phân đúng không
bool isBinarySearchTree(PtrNode root) {
    return isBinarySearchTreeUtil(root, INT_MIN, INT_MAX);
}

// Hàm kiểm tra xem cây có phải là cây nhị phân đầy đủ không
bool isFullBinaryTree(PtrNode root) {
    if (root == NULL) {
        return true; // Cây rỗng được coi là cây nhị phân đầy đủ
    }

    // Nếu nút hiện tại có 0 hoặc 2 con, kiểm tra các cây con của nút
    if ((root->left == NULL && root->right == NULL) || (root->left && root->right)) {
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }

    // Nếu nút hiện tại có 1 con (không đủ), trả về false
    return false;
}

// Hàm để xác định nút cha của nút chứa khóa x
PtrNode findParentNode(PtrNode root, int x, PtrNode parent) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == x) {
        return parent;
    }

    if (x < root->data) {
        return findParentNode(root->left, x, root);
    } else {
        return findParentNode(root->right, x, root);
    }
}

// Hàm để đếm số nút lá và số nút giữa trong cây
void countLeafAndIntermediateNodes(PtrNode root, int *leafCount, int *intermediateCount) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        (*leafCount)++;
    } else {
        (*intermediateCount)++;
    }

    countLeafAndIntermediateNodes(root->left, leafCount, intermediateCount);
    countLeafAndIntermediateNodes(root->right, leafCount, intermediateCount);
}

// Hàm để đếm kích thước của cây
int countNodes(PtrNode root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Hàm để tính độ sâu (chiều cao) của cây
int findTreeHeight(PtrNode root) {
    if (root == NULL) {
        return -1; // Cây rỗng có chiều cao là -1
    }

    int leftHeight = findTreeHeight(root->left);
    int rightHeight = findTreeHeight(root->right);

    // Chiều cao của cây là chiều cao của nhánh cao nhất cộng thêm 1
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Hàm tìm và in node có giá trị lớn nhất trong cây
void FindMaxNode(PtrNode root) {
    if (root == NULL) {
        printf("Cay rong.\n");
        return;
    }
    PtrNode current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    printf("Node co gia tri lon nhat: %d\n", current->data);
}

// Hàm tìm và in node có giá trị nhỏ nhất trong cây
void FindMinNode(PtrNode root) {
    if (root == NULL) {
        printf("Cay rong.\n");
        return;
    }
    PtrNode current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    printf("Node co gia tri nho nhat: %d\n", current->data);
}

int sumTreeValues(PtrNode root) {
    if (root == NULL) {
        return 0; // Trường hợp cơ sở: cây rỗng, tổng là 0
    }

    // Tính tổng giá trị của nút hiện tại và các nút con
    int leftSum = sumTreeValues(root->left);
    int rightSum = sumTreeValues(root->right);

    return root->data + leftSum + rightSum;
}


int main() {
    PtrNode root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    if (isBinarySearchTree(root)) {
        printf("Cay nhi phan dung.\n");
    } else {
        printf("Cay nhi phan sai.\n");
    }
    if (isFullBinaryTree(root)) {
        printf("Cay la cay nhi phan day du.\n");
    } else {
        printf("Cay khong la cay nhi phan day du.\n");
    }

    int x = 40;
    PtrNode parentNode = findParentNode(root, x, NULL);

    if (parentNode) {
        printf("Nut cha cua nut chua khoa %d la: %d\n", x, parentNode->data);
    } else {
        printf("Khong tim thay nut chua khoa %d hoac nut nay la nut goc.\n", x);
    }

    int leafCount = 0;
    int intermediateCount = 0;

    countLeafAndIntermediateNodes(root, &leafCount, &intermediateCount);

    printf("So nut la trong cay la: %d\n", leafCount);
    printf("So nut giua trong cay la: %d\n", intermediateCount);

    int size = countNodes(root);

    printf("Kich thuoc cua cay la: %d\n", size);

    int height = findTreeHeight(root);

    printf("Chieu cao cua cay la: %d\n", height);

    FindMaxNode(root);

    FindMinNode(root);
    int totalSum = sumTreeValues(root);
    printf("Tong gia tri cua cac nut tren cay la: %d\n", totalSum);

    return 0;
}
