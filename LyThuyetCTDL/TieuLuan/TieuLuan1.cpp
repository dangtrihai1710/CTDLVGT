#include <iostream>
#include <conio.h>
#include <cstring>
#define MAX 100
using namespace std;

// Định nghĩa kiểu dữ liệu ngày tháng
struct Date {
    unsigned ngay;
    unsigned thang;
    unsigned nam;
};


// Định nghĩa kiểu dữ liệu cấu trúc sinh viên
typedef struct SinhVien {
    char ma[MAX];
    char ten[MAX];
    char gioiTinh;
    float diemtoan;
    float diemly;
    float diemanh;
    char tennganh[MAX];
    struct Date ng;
}SV;

// Nhập ngày sinh cho sinh viên
void nhapNgaySinh(Date &d) {
    cout << "\n\tNhap ngay: ";
    cin >> d.ngay;
    cout << "\n\tNhap thang: ";
    cin >> d.thang;
    cout << "\n\tNhap nam: ";
    cin >> d.nam;
}

// Xuất ngày sinh cho sinh viên
void xuatNgaySinh(Date d) {
    cout << ""<<d.ngay<<"/"<<d.thang<<"/"<<d.nam<<"";
}

//Hàm nhập 1 sinh viên
void nhapSV(SV &x) {
    cout << "\n\tNhap ma: ";
    fflush(stdin);
    gets(x.ma);
    cout << "\n\tNhap ten: ";
    gets(x.ten);
    cout << "\n\tNhap ten nganh hoc: (VD:CNTT)";
    gets(x.tennganh);
    cout << "\n\tNhap diem toan: ";
    cin >> x.diemtoan;
    cout << "\n\tNhap diem ly: ";
    cin >> x.diemly;
    cout << "\n\tNhap diem anh: ";
    cin >> x.diemanh;
    cout << "\n\tNhap ngay thang nam sinh: ";
    nhapNgaySinh(x.ng);
    fflush(stdin);
    do {
        cout << "Nhap gioi tinh(x-nu,y-nam): ";
        x.gioiTinh = getche();
    }while(x.gioiTinh != 'x' && x.gioiTinh != 'y');
}

// Hàm xuất 1 sinh viên
void xuatSV(SV x) {
    cout << "\n\tMa:" << x.ma ;
    cout << " Ten:" << x.ten ;
    cout << " Ten nganh:" << x.tennganh ;
    cout << " Diem toan:" << x.diemtoan ;
    cout << " Diem ly:" << x.diemly ;
    cout << " Diem tin:" << x.diemanh ;
    xuatNgaySinh(x.ng);
    cout << " Gioi tinh:" << x.gioiTinh ;
}

// Hàm nhập danh sách sinh viên
void nhapDSSV(SV a[],int &n) {
    do {
        cout << "\n\tNhap so luong sinh vien (0<n<=100): ";
        cin >> n;
        if(0 >= n || n >= MAX)
            cout << "\n\tSo luong sinh vien khong hop le";
    } while (0 >= n || n >= MAX);
    cout << "\n\tNhap danh sach sinh vien: ";
    for(int i=0;i<n;i++) {
        cout << "\n\tNhap sinh vien thu: "<< i+1;
        nhapSV(a[i]);
    }
}

// Hàm xuất danh sách sinh viên
void xuatDSSV(SV a[],int n) {
    cout << "\n\tDanh sach sinh vien: ";
    for(int i=0;i<n;i++) {
        cout << "\n\tXuat sinh vien thu: "<< i+1;
        xuatSV(a[i]);
    }
}


// Hàm tìm sinh viên theo mã số sinh viên
void TimSV(SV a[],int n,char s[MAX]) {
    int i, flag = 0;
    if(n == 0)  
        cout << "\n\t\tDanh sach sinh vien rong";
    else
        cout << "\n\t\tNhap MSSV can tim: ";
    fflush(stdin);
    gets(s);
    for(i=0;i<n;i++) 
        if(strcmp(a[i].ma,s) == 0){
            xuatSV(a[i]);
            flag ++;
        }
    if(flag == 0)
        cout << "\n\tKhong tim thay ten sinh vien";
}

// Hàm xuất sinh viên ngành công nghệ thông tin 
void XuatSV_CNTT(SV a[],int n) {
    int i,flag = 0;
    for(i=0;i<n;i++) 
        if(strstr(a[i].tennganh,"CNTT")) {
            xuatSV(a[i]);
            flag ++;
        }
    if(flag == 0) 
        cout << "\n\tKhong tim thay sinh vien ";
}

// Hàm xuất sinh viên nữ ngành công nghệ thông tin
void XuatSVNu_CNTT(SV a[],int n) {
    int i,flag = 0;
    for(i=0;i<n;i++) 
        if(strstr(a[i].tennganh,"CNTT") && a[i].gioiTinh == 'x') {
            xuatSV(a[i]);
            flag ++;
        }
    if(flag == 0) 
        cout << "\n\tKhong tim thay sinh vien";
}

// Tìm và xuất thông tin sinh viên theo tên
void timSV_Ten(SV a[],int n,char s[MAX]) {
    int i,flag = 0;
    if(n == 0)  
        cout << "\n\tDanh sach sinh vien rong";
    else
        cout << "\n\tNhap MSSV can tim: ";
    gets(s);
    for(i=0;i<n;i++) 
        if(strstr(a[i].ten,s)) {
            xuatSV(a[i]);
            flag ++;
        }
    if(flag == 0) 
        cout << "\n\tKhong tim thay ten sinh vien";
}

// Xuất danh sách thông tin sinh viên theo ngành học tìm kiếm
void xuatSVTheoNganh(SV a[],int n,char s[MAX]) {
    int i,flag = 0;
    if(n == 0)  
        cout << "\n\tDanh sach sinh vien rong";
    else
        cout << "\n\tNhap ten nganh can xuat ds sinh vien: ";
    gets(s);
    for(i=0;i<n;i++) 
        if(strstr(a[i].tennganh,s)) {
            xuatSV(a[i]);
            flag ++;
        }
    if(flag == 0) 
        cout << "\n\tKhong tim thay sinh vien";
}


// Hàm hoán vị 
void HoanVi(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp sinh viên có điểm toán tăng dần
void SapXepDiemToan(SV a[], int n) {
    for(int i=0;i<n-1;i++) 
        for(int j=i+1;j<n;j++)
            if (a[i].diemtoan > a[j].diemtoan)
                HoanVi(a[i].diemtoan,a[j].diemtoan);
}

// Hàm xóa sinh viên theo mã sinh viên
void xoaSinhVienTheoMa(SV a[], int &n, char maSV[MAX]) {
    int i, j;
    bool found = false;

    for (i = 0; i < n; i++) {
        if (strcmp(a[i].ma, maSV) == 0) {
            found = true;
            // Dịch chuyển các sinh viên phía sau lên trước để ghi đè sinh viên bị xóa
            for (j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--; // Giảm số lượng sinh viên đi 1
            cout << "\n\tDa xoa sinh vien co ma " << maSV << endl;
            break;
        }
    }

    if (!found) {
        cout << "\n\tKhong tim thay sinh vien co ma " << maSV << endl;
    }
}


// Hàm MENU lựa chọn
void MeNu(int &chon) {
    cout << "\n\tCHUONG TRINH QUAN LY SINH VIEN BANG C/C++";
    cout << "\n\t******------------MENU-------------******";
    cout << "\n\t1. Nhap danh sach sinh vien";
    cout << "\n\t2. Xuat danh sach sinh vien";
    cout << "\n\t3. Tim thong tin sinh vien theo MSSV";
    cout << "\n\t4. Xuat danh sach sinh vien CNTT";
    cout << "\n\t5. Xuat danh sach sinh vien nu CNTT";
    cout << "\n\t6. Tim thong tin sinh vien theo ten";
    cout << "\n\t7. Xuat danh sach sinh vien theo ten nganh";
    cout << "\n\t8. Xuat danh sach sinh vien theo diem toan tang dan";
    cout << "\n\t9. Xoa sinh vien theo ma sinh vien";
    cout << "\n\t0. Thoat";
    cout << "\n\tChon chuc nang: ";
    cin >> chon;
}


int main() {
    SV a[MAX];
    int n;
    int chon;
    char maSV[MAX];

    do {
        MeNu(chon);
        switch (chon) {
            case 1:
                nhapDSSV(a, n);
                break;
            case 2:
                xuatDSSV(a, n);
                break;
            case 3:
                TimSV(a, n, maSV);
                break;
            case 4:
                XuatSV_CNTT(a, n);
                break;
            case 5:
                XuatSVNu_CNTT(a, n);
                break;
            case 6:
                timSV_Ten(a, n, maSV);
                break;
            case 7:
                xuatSVTheoNganh(a, n, maSV);
                break;
            case 8:
                SapXepDiemToan(a,n);
                break;    
            case 9:
                cout << "\n\tNhap ma sinh vien can xoa: ";
                cin.ignore();
                cin.getline(maSV, MAX);
                xoaSinhVienTheoMa(a, n, maSV);
                break;
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Chuc nang khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (chon != 0);

    return 0;
}


