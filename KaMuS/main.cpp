#include "mainHeader.h"
int main()
{
    cout<<"================================="<<endl;
    cout<<"        APLIKASI KAMUS         "<<endl;
    cout<<"================================="<<endl;
    ShowCurrentTime();
    cout<<endl;
    cout<<"Timestamp : " << CurrentTimestamp() << endl;
    cout<<"================================="<<endl;
    cout<<"Silahkan Pilih Menu Utama"<<endl;
    cout<<"1. Inggris to Indonesia"<<endl;
    cout<<"2. Indonesia to Inggris"<<endl;
    int pilih;
    cout<<"Masukan Pilihan : ",cin>>pilih;
    if (pilih == 1){
        string huruf;
        cout<<"Masukan kata menggunakan huruf KAPITAL : ",cin>>huruf;
    }else if (pilih == 2){
        string huruf;
        cout<<"Masukan kata menggunakan huruf KAPITAL : ",cin>>huruf;
    }
    clrscr();
    return 0;
}
