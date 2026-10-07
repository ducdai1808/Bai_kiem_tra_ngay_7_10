#include<iostream>
#include<string>
using namespace std;

struct NhanVien
{
    int MaNV;
    char Hoten[50];
    char Ngaysinh[15];
    double Luong;
};

// Ham nhap 1 nhan vien
void NhapNV(NhanVien &nv)
{
    cout << "Nhap ma nhan vien: ";
    cin >> nv.MaNV;
    cin.ignore();

    cout << "Nhap ho ten nhan vien: ";
    gets(nv.Hoten);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    gets(nv.Ngaysinh);

    cout << "Nhap luong: ";
    cin >> nv.Luong;
}

// Ham nhap danh sach
void NhapDS(NhanVien a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin nhan vien thu: " << i + 1 << "\n";
        NhapNV(a[i]);
    }
}

// Ham xuat 1 nhan vien
void XuatNv(NhanVien nv)
{
    cout << nv.MaNV << "\t"
         << nv.Hoten << "\t\t"
         << nv.Ngaysinh << "\t"
         << nv.Luong << endl;
}

// Ham xuat danh sach
void XuatDS(NhanVien a[], int n)
{
    cout << "\nDanh sach nhan vien:\n";
    cout << "MaNV\tHoTen\t\tNgaysinh\tLuong\n";

    for(int i = 0; i < n; i++)
    {
        XuatNv(a[i]);
    }
}

// Sap xep noi bot Bubble Sort
void bubbleSort(NhanVien a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j].Luong > a[j + 1].Luong)
            {
                NhanVien temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Tim kiem nhi phan
int binarySearch(NhanVien a[], int n, double X)
{
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(a[mid].Luong == X)
        {
            return mid;
        }

        if(a[mid].Luong < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

// Tim tat ca nhan vien co luong bang X
void timNhanVien(NhanVien a[], int n, double X)
{
    int pos = binarySearch(a, n, X);

    if(pos == -1)
    {
        cout << "\nKhong tim thay nhan vien co luong = "
             << X << " trieu dong.";
    }
    else
    {
        cout << "\nCac nhan vien co luong = "
             << X << " trieu dong:\n";

        int i = pos;

        // Tim ve vi tri dau tien co luong X
        while(i >= 0 && a[i].Luong == X)
        {
            i--;
        }

        // Hien thi tat ca nhan vien co luong X
        for(int j = i + 1; j < n && a[j].Luong == X; j++)
        {
            XuatNv(a[j]);
        }
    }
}

int main()
{
    int n;
    NhanVien a[100];

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    // Nhap danh sach
    NhapDS(a, n);

    // Hien thi danh sach vua nhap
    cout << "\n===== DANH SACH NHAN VIEN VUA NHAP =====";
    XuatDS(a, n);

    // Sap xep
    bubbleSort(a, n);

    // Hien thi danh sach sau khi sap xep
    cout << "\n===== DANH SACH SAU KHI SAP XEP =====";
    XuatDS(a, n);

    // Nhap X
    double X;
    cout << "\nNhap luong X can tim: ";
    cin >> X;

    // Tim kiem
    timNhanVien(a, n, X);

    return 0;
}
