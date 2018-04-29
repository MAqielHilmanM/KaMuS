#include "view.h"

void mainView(){
    //Variable
    string huruf;


    cout<<"================================="<<endl;
    cout<<"        APLIKASI KAMUS         "<<endl;
    cout<<"================================="<<endl;
    ShowCurrentTime();
    cout<<endl;
    cout<<"================================="<<endl;
    cout<<"Silahkan Pilih Menu Utama"<<endl;
    cout<<"1. Inggris to Indonesia"<<endl;
    cout<<"2. Indonesia to Inggris"<<endl;
    int pilih;
    cout<<"Masukan Pilihan : ",cin>>pilih;
    if (pilih == 1){
    }else if (pilih == 2){
        cout<<"Masukan kata menggunakan huruf KAPITAL : ",cin>>huruf;
    }
}

void InputView(int menu){
    string huruf;
    cout<<"Masukan kata menggunakan huruf KAPITAL : ",cin>>huruf;
}
