#include <stdio.h>

// Dinh nghia kieu du lieu co cau truc node root
typedef struct node {
    int info;
    struct node *left;
    struct node *right;
}Node;

typedef Node* PtrNode;

// Hàm khởi tạo cây
void Init(PtrNode &proot) {
    proot = NULL;
}

// Hàm kiểm tra rỗng
bool isEmpty (PtrNode proot) {
    if(proot == NULL)   return true;
    return false;
}

// Hàm tạo node x
PtrNode CreateNode(int x) {
    PtrNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// Hàm tạo cây nhị phân từ mảng số nguyên
void CreateTree(PtrNode &proot, int a[], int begin, int end) {
    if(begin > end) return;
    int i = (begin + end) / 2;
    // tao nut cay co goc du lieu a[i]
    proot = CreateNode(a[i]);
    // tao cay con trai chua cac gia tri o nua trai mang
    CreateTree(proot->left, a, begin, i-1);
}

// Hàm duyệt NLR
void NLR(PtrNode proot) {
    if(proot != NULL) {
        printf("%4d",proot -> info); // Xuat gia tri nut goc
        NLR(proot -> left); // Duyet cay con trai
        NLR(proot -> right); // Duyet cay con phai
    }
}

// Hàm thêm cây
void Insert(PtrNode &proot, int x) {
    if(isEmpty(proot)) // nếu cây rỗng, thêm trực tiếp vào cây
        proot = CreateNode(x);
    else {
        if(x == proot->info) // nếu đã có x trong cây
            return;
        if(x < proot->info)
            Insert(proot->left, x);
        if(x > proot->info)
            Insert(proot->right, x);
    }
}

// Hàm xóa cây
int Remove(PtrNode &proot, int x) {
    if (proot == NULL)
        return false; // Không tìm thấy nút cần xóa

    if (proot->info > x) {
        // Tìm và xóa bên trái
        if (Remove(proot->left, x)) {
            // Xóa thành công nút ở phía bên trái
            // Kiểm tra xem có cần cân bằng lại cây không
            // (bạn có thể thêm cân bằng cây ở đây nếu cần)
            return true;
        }
    } else if (proot->info < x) {
        // Tìm và xóa bên phải
        if (Remove(proot->right, x)) {
            // Xóa thành công nút ở phía bên phải
            // Kiểm tra xem có cần cân bằng lại cây không
            // (bạn có thể thêm cân bằng cây ở đây nếu cần)
            return true;
        }
    }         // Nếu proot->info == x 
    else {     
        // Xử lý trường hợp có ít hơn hai cây con
        if (proot->left == NULL) {
            proot = proot->right;
        } else if (proot->right == NULL) {
            proot = proot->left;
        } else {
            // Xử lý trường hợp có cả hai cây con
            // Tìm nút kế tiếp lớn hơn trong cây con bên phải
            PtrNode successor = proot->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }

            // Copy giá trị của nút kế tiếp vào nút hiện tại
            proot->info = successor->info;

            // Xóa nút kế tiếp
            Remove(successor, successor->info);
        }

        // Xóa nút tạm thời
        delete proot;
        return true;
    }

    return false; // Không tìm thấy nút cần xóa
}

// Hàm giải phóng bộ nhớ cây
void FreeTree(PtrNode &proot) {
    if (proot != NULL) {
        FreeTree(proot->left); // Giải phóng cây con trái
        FreeTree(proot->right); // Giải phóng cây con phải
        delete proot; // Giải phóng nút gốc
        proot = NULL; // Đặt con trỏ gốc thành NULL để tránh truy cập sau khi giải phóng
    }
}

int main() {
    PtrNode root = NULL; // Khởi tạo cây rỗng

    int arr[] = {5, 3, 7, 2, 4, 6, 8};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        Insert(root, arr[i]); // Thêm các phần tử vào cây
    }

    printf("Cay sau khi them cac phan tu: ");
    NLR(root); // Duyệt và in cây theo NLR (preorder)

    int value_to_remove = 4;
    if (Remove(root, value_to_remove)) {
        printf("\nDa xoa gia tri %d khoi cay.\n", value_to_remove);
        printf("Cay sau khi xoa gia tri %d: ", value_to_remove);
        NLR(root); // Duyệt và in cây sau khi xóa
    } else {
        printf("\nKhong tim thay gia tri %d trong cay.\n", value_to_remove);
    }

    FreeTree(root);

    return 0;
}
