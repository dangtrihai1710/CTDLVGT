#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_COL 100
typedef int Matran[MAX_COL][MAX_COL];

using namespace std;
int inputArr(int a[], int n) {
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;
    cout << "\nNhap gia tri cho phan tu: ";
    for(int i = 0; i < n; i++) {
        cout << "a["<<i<<"]";
        cin >> a[i];
    }
}

int outputArr(Matran a, int n) {
    cout << "\nXuat gia tri cho phan tu: ";
    for(int i = 0; i < n; i++) {
        cout << "a["<<i<<"]";
    }   
}

int ramdomMatrix(Matran a, int n ,int m) {
    srand(time(NULL));
    cout << "\nMoi nhap so dong ma tran: ";
    cin >> n;
    cout << "\nMoi nhap so cot ma tran: ";
    cin >> m;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            a[i][j] = rand() % 101;
}

void Xuat(Matran a,int d,int c) {
    cout << "\nNoi dung ma tran:\n";
    for(int i=0;i<d;i++) {
        for(int j=0;j<c;j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl ;
    }
}

struct PhanSo {
    int tuSo;
    int mauSo;
};

// Hàm trừ hai phân số
PhanSo truPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo truPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

// Hàm cộng hai phân số
PhanSo congPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo nhanPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo chiaPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    return ketQua;
}



int main() {
    PhanSo ps1, ps2, hieu, tong, nhan, chia;

    cout << "Nhap phan so thu nhat:\n";
    cout << "Nhap tu so: ";
    cin >> ps1.tuSo;
    cout << "Nhap mau so: ";
    cin >> ps1.mauSo;

    cout << "Nhap phan so thu hai:\n";
    cout << "Nhap tu so: ";
    cin >> ps2.tuSo;
    cout << "Nhap mau so: ";
    cin >> ps2.mauSo;

    hieu = truPhanSo(ps1, ps2);

    cout << "Hieu hai phan so la: " << hieu.tuSo << "/" << hieu.mauSo << endl;

    tong = congPhanSo(ps2, ps1); 

    cout << "Hieu hai phan so la: " << tong.tuSo << "/" << tong.mauSo << endl;

    nhan = nhanPhanSo(ps2, ps1);

    cout << "Hieu hai phan so la: " << nhan.tuSo << "/" << nhan.mauSo << endl;

    chia = chiaPhanSo(ps2, ps1);

    cout << "Hieu hai phan so la: " << nhan.tuSo << "/" << nhan.mauSo << endl;



    return 0;
}
