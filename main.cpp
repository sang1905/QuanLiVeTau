#include <bits/stdc++.h>
#include "function.h"
// PBL Nhom 5
// 1. Phan Thanh Sang
// 2. Hoang Van Thai
// 3. Nguyen Minh Phuong

using namespace std;
void menuDatVe(){
    char role_DatVe;
    do{
        cout << "\n \t 1. Nhap thong tin mua ve ";
        cout << "\n \t 0. Thoat ";
        cout << "\n \t \t Vui long chon chuc nang: "; cin >> role_DatVe;

        switch (role_DatVe)
        {
        case '1':
        {
            system("cls");
            cout << "\n \t \t BAN VUA CHON CHUC NANG NHAP THONG TIN MUA VE !";
            HanhKhach a;
            VeTau b;
            a.NhapTT();
            b.DatVe();
            GhiDuLieu(a,b);
            break;
        }
        case '0':
        {
            system("cls");
            break;
        }
        default:
            cout << "\n \t \t Lua chon khong hop le ! Vui long chon lai !";
            break;
        }

    }while(role_DatVe != '0');
}
void menuQuanLy(){
    
    char role_quanly;
    do{
        cout << "\n \t \t 1. Quan li ve";
        cout << "\n \t \t 2. Quan li lich trinh";
        cout << "\n \t \t 3. Quan li hanh khach";
        cout << "\n \t \t 0. Thoat";
        cout << "\n \t \t \t Vui long lua chon chuc nang: "; cin >> role_quanly;

        switch (role_quanly)
        {
        case '1':
        {
            system("cls");
            cout << "BAN VUA CHON CHUC NANG QUAN LI VE !"<< endl;
            VeTau vt[M];
            int size = 0;
            DocDuLieu_VeTau(vt,size);
            
            for (int i = 0; i < size - 1 ; i++){
                vt[i].showInfo();
                cout << endl;
            }

            break;
        }
        case '2':
        {
            system("cls");
            cout << "BAN VUA CHON CHUC NANG QUAN LI LICH TRINH !"<< endl;
            VeTau vt[M];
            int size = 1;
            DocDuLieu_VeTau(vt,size);
            QuanLiLichTrinh(vt,size);

            break;
        }
        case '3':
        {
            system("cls");
            cout << "BAN VUA CHON CHUC NANG QUAN LI HANH KHACH !"<< endl;
            int size_hk = 0;;
            HanhKhach hk[M];
            DocDuLieu_HanhKhach(hk,size_hk); // ghi du lieu ra man hinh
            
            for (int i = 0; i < size_hk - 1; i++){
                hk[i].showInfo();
                cout << endl;
            }
            
            break;
        }
        case '0':
        {
            system("cls");
            break;
        }

        default:
            system("cls");
            cout << "\n \t \t Lua chon khong hop le ! Vui long chon lai !";
            break;
        }
    }while(role_quanly != '0');
}
void menuTimKiem(){

    char role_Timkiem;
    do{
    cout << "\n \t 1. Tim kiem hanh khach";
    cout << "\n \t 2. Tim kiem ve tau";
    cout << "\n \t 3. Tim kiem lich trinh";
    cout << "\n \t 0. Thoat...";
    cout << "\n \t \t Vui long chon chuc nang: "; cin >> role_Timkiem;

    switch (role_Timkiem)
    {
    case '1':
    {
        system("cls");
        cout << "\n \t \tBAN VUA LUA CHON TIM KIEM HANH KHACH !" << endl;
        cin.ignore();
        string name;
        cout << "\n \t \t Nhap ten hanh khach muon tim kiem: "; getline(cin,name);
        HanhKhach hk[M];
        int size = 0;
        DocDuLieu_HanhKhach(hk, size);
        TimKiemHanhKhach(hk,size,name);
        fflush(stdin);
        break;
    }
    case '2':
    {
        system("cls");
        cout << "\n \t \tBAN VUA LUA CHON TIM KIEM VE TAU !" << endl;
        cin.ignore();
        string id;
        cout << "\n \t \t Moi ban nhap id ve tau can tim: "; getline(cin,id);
        VeTau vt[M];
        int size = 0;
        DocDuLieu_VeTau(vt,size);
        TimKiemVeTau(vt,size,id);
        fflush(stdin);
        break;
    }
    case '3':
    {
        system("cls");
        cout << "\n \t \tBAN VUA LUA CHON TIM KIEM LICH TRINH !" << endl;
        cout << "\n \t \t Chon lich trinh muon tim kiem: ";
        cout << "\n \t 1. Da Nang -> Ha Noi";
        cout << "\n \t 2. Da Nang -> TP HCM";
        cout << "\n \t 3. Da Nang -> Hue";
        cout << "\n \t 4. Da Nang -> Nghe An";
        cout << "\n \t 5. Da Nang -> Quang Tri";
        int lich_trinh;
        do{
            cout << "\n \t \t Lua chon: "; cin >> lich_trinh;

            if (lich_trinh < 1 || lich_trinh > 5){
                cout << "\n \t \t Lua chon khong hop le ! Xin vui long nhap lai !";
            }
        }while (lich_trinh < 1 || lich_trinh > 5);

        VeTau vt[M];
        int size = 0;
        DocDuLieu_VeTau(vt,size);
        TimKiemLichTrinh(vt,size,lich_trinh);
        fflush(stdin);

        break;
    }
    case '0':
    {
        system("cls");
        break;
    }
    default:
        system("cls");
        cout << "\n \t \t Lua chon khong hop le ! Vui long nhap lai !" << endl;
        break;
    }
    } while (role_Timkiem != '0');

}
void menuThongKe(){

    char role_Thongke;
    do{
        cout << "\n \t 1. Tong doanh thu ve thuong";
        cout << "\n \t 2. Tong doanh thu ve vip";
        cout << "\n \t 0. Exit";
        cout << "\n \t \t Vui long chon chuc nang: "; cin >> role_Thongke;

        switch (role_Thongke)
        {
        case '1':
        {
            system("cls");
            cout << "\n \t \t BAN VUA CHON TONG DOANH THU VE THUONG" << endl;
            VeTau vt[M];
            int size = 0;
            DocDuLieu_VeTau(vt,size);
            long doanh_thu = DoanhThuVeThuong(vt,size);

            cout << "\n \t Tong doanh thu ve thuong la la: " << doanh_thu << endl;
            break;
        }
        case '2':
        {
            system("cls");
            cout << "\n \t \t BAN VUA CHON TONG DOANH THU VE VIP" << endl;
            VeTau vt[M];
            int size = 0;
            DocDuLieu_VeTau(vt,size);
            long doanh_thu = DoanhThuVeVip(vt,size);

            cout << "\n \t Tong doanh thu ve thuong la la: " << doanh_thu << endl;
            //cout << "\n \t Doanh thu ve vip la: " << doanh_thu << endl;
            break;
        }
        case '0':
        {
            system("cls");
            break;
        }
        default:
            system("cls");
            cout << "\n \t \t Lua chon khong hop le ! Vui long chon lai !" << endl;
            break;
        }
    }while (role_Thongke != '0');
}
void menuRole(){
// Lua chon chuc nang 
char role;
do{ 
    cout << "\n \t                         ***                             ";
    cout << "\n \t -------------------------------------------------------";
    cout << "\n \t \t HE THONG QUAN LI VE TAU VIETNAM - 2OKTMT1";
    cout << "\n \t 1. Chuc nang dat ve";
    cout << "\n \t 2. Chuc nang quan ly";
    cout << "\n \t 3. Chuc nang tim kiem";
    cout << "\n \t 4. Chuc nang thong ke";
    cout << "\n \t 0. Exit";
     cout << "\n \t -------------------------------------------------------";
    cout << "\n \t \t Vui long chon chuc nang cua ban: "; cin >> role;
   

    switch (role)
    {
    case '1':
    {
        system("cls");
        cout << "\n BAN VUA LUA CHON CHUC NANG DAT VE !" << endl; 
        menuDatVe();
        break;
    }
    case '2':
    {
        system("cls");
        cout << "\n BAN VUA LUA CHON CHUC NANG QUAN LY !" << endl; 
        menuQuanLy();

        break;
    }
    case '3':
    {
        system("cls");
        cout << "\n BAN VUA CHON CHUC NANG TIM KIEM !" << endl;
        menuTimKiem();
        break;
    }
    case '4':
    {
        system("cls");
        cout << "\n BAN VUA CHON CHUC NANG THONG KE !" << endl;
        menuThongKe();
        break;
    }
    case '0':
    {
        system("cls");
        cout << "Tam biet quy khach !...";
        break;
    }
    default:
    {
        system("cls");
        cout << "Lua chon khong hop le ! Vui long nhap lai !";
        break;
    }
    }
} while (role != '0');
}
int main(){

    // co 1 menu chinh
    // trong menu chinh co 4 menu phu
    // trong moi menu phu co cac chuc nang khac nhau

    menuRole();


    return 0;
}
