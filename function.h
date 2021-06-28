#include <bits/stdc++.h>
#include "objects_system.h"
#define M 10000
using namespace std;
// ham ghi du lieu giup luu du lieu vao cac file du lieu
void GhiDuLieu(HanhKhach a, VeTau b){
    system("cls");
    fstream output_1, output_2,output_3;
    output_1.open("DuLieuHanhKhach.txt",ios::out | ios::app);
    output_2.open("DuLieuVeTau.txt",ios::out | ios::app);
    output_3.open("DuLieuPhieuVeTau.txt",ios::out | ios::app);
    string data_1 = a.getID() + "\n" + a.getName() + "\n" 
                    + a.getPhoneNumber() + "\n" + a.getCMND() +  "\n";
    string data_2 = b.getID() + "\n" + to_string(b.getLoaiVe()) + "\n" + to_string(b.getPrice()) + 
                    "\n" + to_string(b.getSoGhe()) + "\n" + to_string(b.getSoToa()) + "\n" + to_string(b.getChuyen()) +"\n"
                    + b.getGio() + "\n";
    string data_3 = data_1 + data_2;

    output_1 << data_1;
    output_2 << data_2;
    output_3 << data_3;

    if (output_1.is_open() && output_2.is_open()){
        cout << "Ghi du lieu thanh cong !";
    } else
    {
        cout << "Error: "<< strerror(errno) << endl;
    }
    

    output_1.close();
    output_2.close();
    output_3.close();
}
// doc du lieu tu cac file du lieu de thuc hien cac chuc nang
void DocDuLieu_HanhKhach(HanhKhach arr[M], int &size){

    fstream input_1, input_2;
    input_1.open("DuLieuHanhKhach.txt",ios::in);

    char str[255];
    while (!input_1.eof()){
        // lay id tu csdl
        input_1.getline(str,255);
        string t_id = str;
        arr[size].setID(t_id);
        // lay name tu csdl
        input_1.getline(str,255);
        string t_name = str;
        arr[size].setName(t_name);
        // lay phone_number tu csdl
        input_1.getline(str,255);
        string t_phone = str;
        arr[size].setPhoneNumber(t_phone);
        // lay so cmnd tu csdl;
        input_1.getline(str,255);
        string t_cmnd = str;
        arr[size].setCMND(t_cmnd);

        size++;
    }

    input_1.clear();
    input_1.seekg(0,ios::beg);
    input_1.close();
}
void DocDuLieu_VeTau(VeTau arr[M],int &size){

    fstream f;
    f.open("DuLieuVeTau.txt",ios::in);
    char str[255];

    while (!f.eof()){
        f.getline(str,255);
        string id = str;
        arr[size].setID_VT(id);

        f.getline(str,255);
        int lv = atoi(str);
        arr[size].setLoaiVe(lv);

        f.getline(str,255);
        int price = atoi(str);
        arr[size].setPrice(price);

        f.getline(str,255);
        int soGhe = atoi(str);
        arr[size].setSoGhe(soGhe);

        f.getline(str,255);
        int soToa = atoi(str);
        arr[size].setSoToa(soToa);

        f.getline(str,255);
        int chuyen = atoi(str);
        arr[size].setChuyen(chuyen);

        f.getline(str,255);
        string gio = str;
        arr[size].setGio(gio);
        size++;
    }



    f.close();
}


// cac ham ham duoi de thuc hien cac chuc nang
void QuanLiLichTrinh(VeTau arr[M], int size){

    int thongke[size];

    for (int i = 1; i <= size; i++) thongke[i] = 0;

    for (int i = 1; i <= size; i++){
        thongke[arr[i].getChuyen()]++;
    }   
    cout << "\n \t \t Da Nang -> Ha Noi: " << thongke[1];
    cout << "\n \t \t Da Nang -> TP Ho Chi Minh: " << thongke[2];
    cout << "\n \t \t Da Nang -> Hue: " << thongke[3];
    cout << "\n \t \t Da Nang -> Nghe An: " << thongke[4];
    cout << "\n \t \t Da Nang -> Quang Tri: " << thongke[5] << endl;

}

void TimKiemHanhKhach(HanhKhach arr[M], int size, string name){

   int keys[M];
   int j = 0;
    for (int i = 0; i < size; i++){
        if (arr[i].getName() == name) keys[j++] = i;
    }
    if (j == 0){
        cout << "\n \t \t Khong co hanh khach ten " << name << " trong CSDL!!!";
    } else 
        for (int i = 0; i < j; i++){
            arr[keys[i]].showInfo();
            cout << endl;
        }

}

void TimKiemVeTau(VeTau arr[M], int size, string id){

    int key = M + 1;

    for (int i = 0; i < size; i++){
        if (arr[i].getID_VT() == id) key = i;
    }

    if (key == M + 1){
        cout << "\n \t \t Ve tau khong co trong CSDL !";
    }else{
        arr[key].showInfo();
    }
}

void TimKiemLichTrinh(VeTau arr[M], int size, int lich_trinh){

    // 1 Da Nang -> Ha Noi
    // 2 Da Nang -> TP HCM
    // 3 Da Nang -> Hue
    // 4 Da Nang -> Nghe An
    // 5 Da Nang -> Quang Tri

    int keys[M];
    int j = 0;
    for (int i = 0; i < size; i++){
        if (arr[i].getChuyen() == lich_trinh) keys[j++]  = i;
    }

    if ( j == 0){
        cout << "\n \t \t Khong co chuyen nao trong CSDl !";
    }

    for (int i = 0; i < j; i++){
        arr[keys[i]].showInfo();
        cout << endl;
    }


}

long DoanhThuVeThuong(VeTau arr[M], int &size){

    long sum = 0;
    for (int i = 0; i < size; i++){
       if (arr[i].getPrice() == 200000) sum += arr[i].getPrice();
    }
    

    return sum;
}

long DoanhThuVeVip(VeTau arr[M], int &size){

    long sum = 0;
    for (int i = 0; i < size; i++){
       if (arr[i].getPrice() == 250000) sum += arr[i].getPrice();
    }
    

    return sum;
}
