#include <stdio.h>

// Dinh nghia kieu du lieu co cau truc node root
typedef struct node {
    int info;
    struct node *left;
    struct node *right;
}Node;

typedef Node* PtrNode;

void Init(PtrNode &proot) {
    proot = NULL;
}

bool isEmpty (PtrNode proot) {
    if(proot == NULL)   return true;
    return false;
}

PtrNode CreateNode(int x) {
    PtrNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void CreateTree(PtrNode &proot, int a[], int begin, int end) {
    if(begin > end) return;
    int i = (begin + end) / 2;
    // tao nut cay co goc du lieu a[i]
    proot = CreateNode(a[i]);
    // tao cay con trai chua cac gia tri o nua trai mang
    CreateTree(proot->left, a, begin, i-1);
}

void NLR(PtrNode proot) {
    if(proot != NULL) {
        printf("%4d",proot -> info); // Xuat gia tri nut goc
        NLR(proot -> left); // Duyet cay con trai
        NLR(proot -> right); // Duyet cay con phai
    }
}

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


int Remove(PtrNode &proot, int x) {
    if(proot == NULL)
        return false; // không tìm thấy nút cần xóa
    if(proot->info > x) // tìm và xóa bên trái
        return Remove(proot->left, x);
    if(proot->info < x) // tìm và xóa bên phải
        return Remove(proot->right, x);
    // nếu (proot->info == x)
    PtrNode p,f,rp;
    p = proot; //p biến tạm trỏ đến proot
    // trường hợp proot có 1 cây con
    if(proot->left == NULL) // có 1 cây con
        proot = proot->right;
    else if (proot->right == NULL) // có 1 cây con
        proot = proot->left;
    else {
        //TH pTree có 2 cây con chọn nút nhỏ nhất bên cây con phải
        f = p; // f để lưu cha của rp
        rp = rp->right; //rp qua bên p->right
        while(rp->left != NULL) {
            f = rp; // lưu cha của rp
            rp = rp->left; //rp qua bên trái
        } //kết thúc khi rp là nút có nút con trái là NULL
        p->info = rp->info; // đổi giá trtị của p và rp
        if(f == p) // nếu cha của rp là p
            f->right = rp->right;
        else //f != p
            f->left = rp->right;
        p = rp; // ptrỏ đến phần tử thế mạng rp
    }
    delete p; // xóa nút p
    return true;

}

void FreeTree(PtrNode &proot) {
    if (proot != NULL) {
        FreeTree(proot->left); // Giải phóng cây con trái
        FreeTree(proot->right); // Giải phóng cây con phải
        delete proot; // Giải phóng nút gốc
        proot = NULL; // Đặt con trỏ gốc thành NULL để tránh truy cập sau khi giải phóng
    }
}


// Các phần khai báo và định nghĩa cấu trúc Node và các hàm đã được đưa ra ở trên.

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
