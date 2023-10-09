#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

//Dinh nghia cau truc nut cay 
struct Node{
	int info;
	struct Node *left;
	struct Node *right;
	int height;
};
//Ham tinh chieu cao cua nut
int getHeight(Node *p){
	if(p==NULL)
		return 0;
	return p->height;
}
//Ham tao 1 nut moi
Node* CreateNode(int x){
	Node* node = new Node;
	node->info=x;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}
//Ham tinh so can bang cua mot nut
int balanceFactor(Node *p){
	if(p == NULL)
		return 0;
		
	return getHeight(p->left) - getHeight(p->right);	
}
//Ham tim gia tri lon nhat giua 2 so nguyen
int max(int a,int b){
	return a>b?a:b;
}
//Ham xoay trai
Node *rotateLeft(Node *p){
	// TH1 ko xoay do p rong 
	if(p==NULL)
		return NULL;
	
	
	//TH2 ko xoay dc do p ko co cay con phai
	if(p->right==NULL)
		return NULL;
		
	//TH3 thuc hien xoay
	Node *pivot = p->right;
	
	//chuyen cay con trai thanh cay con phai cua p
	p->right= pivot->left;
	//chuyen p thanh cay trai cua pivot
	pivot->left =p;
	//cap nhat chieu cao cua nut p va pivot
	p->height = 1 + max(getHeight(p->right), getHeight(p->left));
	pivot->height = 1 + max(getHeight(p->right), getHeight(p->left) );
	
	return pivot;
}
//Ham xoay phai
Node *rotateRight(Node *p){
	//TH1 ko xoay do p rong
	if(p==NULL)
		return NULL;
	
	//TH2 ko xoay dc do p ko co cay con 
	if(p->left==NULL)
		return NULL;
		
	//TH3 thuc hien xoay
	Node *pivot = p->left;
	
	//chuyen nut con phai cua pivot thang nut con trai
	p->left=pivot->right;
	
	//chuyen p thang nut con phai cua pivot
	pivot->right=p;
	//cap nhat chieu cao cua nut p va pivot
	p->height=1+max(getHeight(p->right), getHeight(p->left));
	pivot->height = 1 + max(getHeight(p->right), getHeight(p->left) );
	return pivot;

}
// can bang cay tai nut p
Node *balance(Node *p) {
    int bf = balanceFactor(p);
    if (bf < -1) {
        if (balanceFactor(p->right) > 0) {
            p->right = rotateRight(p->right);
        }
        p = rotateLeft(p);
    } else if (bf > 1) {
        if (balanceFactor(p->left) < 0) {
            p->left = rotateLeft(p->left);
        }
        p = rotateRight(p);
    }
    return p;
}

//Ham them 1 nut voi gia tri info cho trc
struct Node *insert(struct Node *p, int x) {
    if (p == NULL)
        return CreateNode(x);

    if (x < p->info)
        p->left = insert(p->left, x);
    else if (x > p->info)
        p->right = insert(p->right, x);
    else
        return p;

    p->height = 1 + max(getHeight(p->left), getHeight(p->right));

    return balance(p);
}
//Ham tim nut nho nhat
struct Node *findMinValueNode(struct Node *node) {
    struct Node *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
//Ham xoa nut
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->info)
        root->left = deleteNode(root->left, key);
    else if (key > root->info)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct Node *temp = findMinValueNode(root->right);
            root->info = temp->info;
            root->right = deleteNode(root->right, temp->info);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    return balance(root);
}
//Ham xuat theo LNR
void printLNR(struct Node *node) {
    if (node != NULL) {
        printLNR(node->left);
        printf("%d ", node->info);
        printLNR(node->right);
    }
}
//Ham xuat theo cay
void printTree(struct Node *node, int space) {
    if (node == NULL)
        return;
    printTree(node->right, space + 5);
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", node->info);
    printTree(node->left, space + 5);
}
int main() {
    struct Node *root = NULL;
    int choice,value;
    int x;

    while (1) {
    	
        printf("\nMenu:\n");
        printf("1. Them gia tri\n");
        printf("2. Xoa gia tri\n"); 
        printf("3. In cay AVL\n");
        printf("4. In theo thu tu tang dan (LNR)\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &x);
                root = insert(root, x);
                printf("Gia tri %d da duoc them vao cay.\n");
                break;
            case 2:
            	printf("Nhap gia tri can xoa: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Da xoa gia tri %d khoi cay AVL.\n", value);
                break;
            case 3:
                printf("Cay AVL theo so do can bang: \n");
                printTree(root, 0);
                break;
            case 4:
                printf("Cay AVL theo thu tu tang dan (LNR): ");
                printLNR(root);
                printf("\n");
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Chuc nang khong hop le. Vui long nhap lai.\n");
        }
    }


    return 0;
}