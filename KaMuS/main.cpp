#include "mainHeader.h"
int main()
{
    cout<<"================================="<<endl;
    cout<<"        APLIKASI KAMUS         "<<endl;
    cout<<"================================="<<endl;
    cout<<"Silahkan Pilih Menu Utama"<<endl;
    cout<<"1. Inggris to Indonesia"<<endl;
    cout<<"2. Indonesia to Inggris"<<endl;
    int pilih;
    cout<<"Masukan Pilihan : ",cin>>pilih;
    if (pilih == 1){
        system("cls");
        string huruf;
        cout<<"Masukan kata menggunakan huruf KAPITAL : ",cin>>huruf;
        string data;
        if (huruf == data){
            cout<<"Tampilkan disini";
        }else{
            system("cls");
            }
    }else if (pilih == 2){
        system("cls");
        string huruf;
        cout<<"Masukan kata menggunakan huruf KAPITAL : ",cin>>huruf;
    }
    return 0;
}
