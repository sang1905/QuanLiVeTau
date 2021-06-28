#include <bits/stdc++.h>

using namespace std;

// duoi day la he thong cac objects 

class HanhKhach{
 protected:
    string id;
    string name;
    string phone_number;
    string cmnd;
public:
    HanhKhach(){
        srand(time(NULL));
        this->id = "20KTMT" + to_string(rand()%(5000000-1000000+1) + 1000000);
    }
    HanhKhach(string name, string phone_number, string cmnd){
        srand(time(NULL));
        this->name         = name;
        this->phone_number = phone_number;
        this->cmnd         = cmnd;
        this->id = "20KTMT" + to_string(rand()%(5000000-1000000+1) + 1000000);
    }

    // setter for HanhKhach
    void setID(string id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }

    void setPhoneNumber(string phone_number){
        this->phone_number = phone_number;
    }

    void setCMND(string cmnd){
        this->cmnd = cmnd;
    }

    //getter for HanhKhach

    string getName(){
        return this->name;
    }

    string getPhoneNumber(){
        return this->phone_number;
    }

    string getCMND(){
        return this->cmnd;
    }

    string getID(){
        return this->id;
    }

    // functions
    void NhapTT(){
        cout << "\n \t \t NHAP THONG TIN HANH KHACH";
        cin.ignore();
        cout << "\n \t Ho va ten: "; getline(cin,name);
        cout << "\n \t So dien thoai: "; getline(cin, phone_number);
        cout << "\n \t CMND: "; getline(cin,cmnd);

    }

    void showInfo(){
        cout << "\n \t ID: " << getID();
        cout << "\n \t Name: " << getName();
        cout << "\n \t Phone Number: " << getPhoneNumber();
        cout << "\n \t CMND: " << getCMND();
    }
    friend class VeTau;
};

class VeTau: public HanhKhach{
    friend class HanhKhach;
    protected:
        string id_vetau = HanhKhach::getID();
        double price; // ve vip 250k ve binhthuong 200k
        int loaiVe; // 1 la ve vip 2 la ve binh thuong
        int soToa;
        int soGhe;
        int chuyen;
        string gio_khoihanh;
    public:
        VeTau(){

        }

        VeTau(double price, int loaiVe, int soToa, int soGhe){
            srand((long)time(NULL));
            this->price  = price;
            this->loaiVe = loaiVe;
            this->soToa  = soToa;
            this->soGhe  = soGhe;
            this->id = rand()%(5000000-1000000+1) + 1000000;
        }

        //setter for VeTau
        void setID_VT(string id){
            this->id = id;
        }
        void setPrice(double price){
            this->price = price;
        }
        void setLoaiVe(int loaiVe){
            this->loaiVe = loaiVe;
        }
        void setSoToa(int soToa){
            this->soToa = soToa;
        }
        void setSoGhe(int soGhe){
            this->soGhe = soGhe;
        }
        void setChuyen(int chuyen){
            this->chuyen = chuyen;
        }
        void setGio(string gio_khoihanh){
            this->gio_khoihanh = gio_khoihanh;
        }
        // getter for VeTau
        double getPrice(){
            return this->price;
        }
        int getLoaiVe(){
            return this->loaiVe;
        }
        int getSoToa(){
            return this->soToa;
        }
        int getSoGhe(){
            return this->soGhe;
        }
        string getID_VT(){
            return this->id_vetau;
        }
        int getChuyen(){
           return this->chuyen;
        }
        string getGio(){
            return this->gio_khoihanh;
        }
        // functions of class

        bool isNumber(char x[255]){

            for (int i = 0; i < strlen(x); i++)
                if (isdigit(x[i]) == false) return false;
            return true;
        }
        void XuliVe(){
            // loai ve co 2 loai
            // 1 ve vip
            // 2 ve thuong
            // neu khac hai 1 va 2 thi bat buoc nhap lai
            char temp[255];
           do {
           cout << "\n \t \t Chon ve:  "; cin.getline(temp,255);

           if (isNumber(temp) == true){
               this->loaiVe = atoi(temp);
                if (this->loaiVe > 2 || this->loaiVe < 1){
                    cout << "\n \t \t Loi ! Loai ve khong ton tai !";
                } 

           }else {
               cout << "\n \t \t Vui long nhap dinh dang thich hop !";
           }
           }while(isNumber(temp) == false || this->loaiVe > 2 || this->loaiVe < 1);

            this->loaiVe = atoi(temp);
            if (this->loaiVe == 1){
                    this->price = 250000;
                } else{
                     this->price = 200000;

        }
        }

       
            
        void XuliToa(){
           char temp[255];
           do {
           cout << "\n \t \t Nhap so toa:  "; cin.getline(temp,255);

           if (isNumber(temp) == true){
               this->soToa = atoi(temp);
                if (this->soToa > 10 || this->soToa < 1){
                    cout << "\n \t \t Loi ! So toa khong ton tai !";
                } 

           }else {
               cout << "\n \t \t Vui long nhap dinh dang thich hop !";
           }
           }while(isNumber(temp) == false || this->soToa > 10 || this->soToa < 1);

        }

        void XuliGhe(){
            char temp[255];
           do {
           cout << "\n \t \t Nhap so ghe:  "; cin.getline(temp,255);
           if (isNumber(temp) == true){
               this->soGhe = atoi(temp);
                if (this->soGhe > 20 || this->soGhe < 1){
                    cout << "\n \t \t Loi ! So ghe khong ton tai !";
                } 

           }else {
               cout << "\n \t \t Vui long nhap dinh dang thich hop !";
           }
           }while(isNumber(temp) == false || this->soGhe > 20 || this->soGhe < 1);
        }


        void XuliGio(){
            // co 4 khung gio
            // 1. 7h
            // 2. 14h
            // 3. 17h
            // 4. 20h

            cout << "\n \t \t  VUI LONG CHON GIO DI ";
            cout << "\n \t 1. 7h";
            cout << "\n \t 2. 14h";
            cout << "\n \t 3. 17h";
            cout << "\n \t 4. 20h" << endl;

           char temp[255];
           do {
           cout << "\n \t \t Chon gio di:  "; cin.getline(temp,255);
           if (isNumber(temp) == true){
                if (atoi(temp) > 4 || atoi(temp) < 1){
                    cout << "\n \t \t Loi ! Gio di khong ton tai !";
                } 

           }else {
               cout << "\n \t \t Vui long nhap dinh dang thich hop !";
           }
           }while(isNumber(temp) == false || atoi(temp) > 4 || atoi(temp) < 1);

           switch (atoi(temp))
           {
           case 1:
                this->gio_khoihanh = "7h";
               break;
           case 2:
                this->gio_khoihanh = "14h";
               break;
            case 3:
                this->gio_khoihanh = "17h";
               break;
            case 4:
                this->gio_khoihanh = "20h";
               break;
           default:
               break;
           }
        }
        void XuliChuyen(){
            
            cout << "\n \t \t Moi ban chon chuyen:";
            cout << "\n \t \t \t 1. Da Nang -> Ha Noi";
            cout << "\n \t \t \t 2. Da Nang -> TP Ho Chi Minh";
            cout << "\n \t \t \t 3. Da Nang -> Hue";
            cout << "\n \t \t \t 4. Da Nang -> Nghe An";
            cout << "\n \t \t \t 5. Da Nang -> Quang Tri";
            

           char temp[255];
           do {
           cout << "\n \t \t Chon chuyen:  "; cin.getline(temp,255);
           if (isNumber(temp) == true){
               this->chuyen = atoi(temp);
                if (this->chuyen > 5 || this->chuyen < 1){
                    cout << "\n \t \t Loi ! Chuyen khong ton tai !";
                } 

           }else {
               cout << "\n \t \t Vui long nhap dinh dang thich hop !";
           }
           }while(isNumber(temp) == false || this->chuyen > 5 || this->chuyen < 1);

        }
        void DatVe(){
            system("cls");
            cout << "\n \t \t NHAP THONG TIN VE !";
            cout << "\n \t Vui long chon loai ve:";
                 cout << "\n \t \t 1. Ve vip";
                 cout << "\n \t \t 2. Ve binh thuong";
                 XuliVe();
                 XuliToa();
                 XuliGhe();
                 XuliChuyen();
                 XuliGio();
        }

        void showInfo(){
            cout << "\n \t ID: " << HanhKhach::getID();

            // Loai Ve
            if (getLoaiVe() == 1){
                cout << "\n \t Loai Ve: VIP";
            } else 
                cout << "\n \t Loai Ve: Binh Thuong";

            cout << "\n \t Price: " << getPrice();
            cout << "\n \t So Toa: " << getSoToa();
            cout << "\n \t So Ghe: " << getSoGhe();

             switch (this->chuyen)
            {
            case 1:
                cout << "\n \t Chuyen: Da Nang -> Ha Noi";
                break;
            case 2:
                cout << "\n \t Chuyen: Da Nang -> TP Ho Chi Minh";
                break;
            case 3:
                cout << "\n \t Chuyen: Da Nang -> Hue";
                break;
            case 4:
                cout << "\n \t Chuyen: Da Nang -> Nghe An";
                break;
            case 5:
                cout << "\n \t Chuyen: Da Nang -> Quang Tri";
                break;
            default:
                cout << "\n \t Chuyen: Khong ro";
                break;
            }
        cout << "\n \t Gio khoi hanh: " << getGio();
        
        
}

};
class PhieuVeTau:  public VeTau{
    private:
        string id           = HanhKhach::getID();
        string name         = HanhKhach::getName();
        string phone_number = HanhKhach::getPhoneNumber();
        string cmnd         = HanhKhach::getCMND();
        double price        = VeTau::getPrice();
        int loaiVe          = VeTau::getLoaiVe();
        int soToa           = VeTau::getSoToa();
        int soGhe           = VeTau::getSoGhe();
    public:
    PhieuVeTau(){
        
    }
        void showInfo(){
            HanhKhach::showInfo();
            VeTau::showInfo();
        }
};

