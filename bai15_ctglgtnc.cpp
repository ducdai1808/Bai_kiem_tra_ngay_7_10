#include <iostream>
#include <string.h>
using namespace std;

// Cau 1: Dinh nghia cau truc KhachHang
struct KhachHang
{
    int maKH;
    char tenKH[50];
    char soDT[15];
    double tongTien;
};

// Cau 2: Ham nhap 1 khach hang
void nhapKH(KhachHang &kh)
{
    cout << "Nhap ma khach hang: ";
    cin >> kh.maKH;
    cin.ignore();

    cout << "Nhap ten khach hang: ";
    gets(kh.tenKH);

    cout << "Nhap so dien thoai: ";
    gets(kh.soDT);

    cout << "Nhap tong tien thanh toan: ";
    cin >> kh.tongTien;
}

// Ham nhap mang khach hang
void nhapDS(KhachHang a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin khach hang thu " << i + 1 << ":\n";
        nhapKH(a[i]);
    }
}

// Cau 3: Ham xuat 1 khach hang
void xuatKH(KhachHang kh)
{
    cout << kh.maKH << "\t"
         << kh.tenKH << "\t"
         << kh.soDT << "\t"
         << kh.tongTien << endl;
}

// Ham xuat danh sach
void xuatDS(KhachHang a[], int n)
{
    cout << "\nDanh sach khach hang:\n";
    cout << "MaKH\tTenKH\t\tSDT\t\tTongTien\n";

    for(int i = 0; i < n; i++)
    {
        xuatKH(a[i]);
    }
}

// Cau 4: Sap xep chen truc tiep (Insertion Sort)
void insertionSort(KhachHang a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        KhachHang x = a[i];
        int j = i - 1;

        while(j >= 0 && a[j].tongTien > x.tongTien)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

// Cau 5: Tim kiem nhi phan
int binarySearch(KhachHang a[], int n, double X)
{
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(a[mid].tongTien == X)
            return mid;

        if(a[mid].tongTien < X)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Ham hien thi tat ca khach hang co tong tien = X
void timKhachHang(KhachHang a[], int n, double X)
{
    int pos = binarySearch(a, n, X);

    if(pos == -1)
    {
        cout << "\nKhong tim thay khach hang co tong tien = " << X;
    }
    else
    {
        cout << "\nCac khach hang co tong tien = " << X << ":\n";

        // In ve ben trai
        int i = pos;
        while(i >= 0 && a[i].tongTien == X)
        {
            i--;
        }

        // In tu vi tri dau tien
        for(int j = i + 1; j < n && a[j].tongTien == X; j++)
        {
            xuatKH(a[j]);
        }
    }
}

// Cau 6: Ham main
int main()
{
    int n;
    KhachHang a[100];

    cout << "Nhap so luong khach hang: ";
    cin >> n;

    // Nhap va hien thi
    nhapDS(a, n);

    cout << "\nDanh sach vua nhap:";
    xuatDS(a, n);

    // Sap xep
    insertionSort(a, n);

    cout << "\nDanh sach sau khi sap xep tang dan theo tong tien:";
    xuatDS(a, n);

    // Tim kiem
    double X;
    cout << "\nNhap tong tien can tim: ";
    cin >> X;

    timKhachHang(a, n, X);

    return 0;
}
