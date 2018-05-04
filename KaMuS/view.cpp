#include "view.h"

void mainView(ListParent &pl, ListRelation &rl, ListChild &cl){
    //Variable
    cout<<"================================="<<endl;
    cout<<"        APLIKASI KAMUS         "<<endl;
    cout<<"================================="<<endl;
    ShowFromTimestamp(CurrentTimestamp());
    cout<<endl;
    cout<<"================================="<<endl;
    cout<<"Silahkan Pilih Menu Utama"<<endl;
    cout<<"1. Inggris to Indonesia"<<endl;
    cout<<"2. Indonesia ke Inggris"<<endl;
    cout<<"3. Database"<<endl;
    cout<<"4. Quiz "<<endl;
    cout<<"5. Jumlah Isi Parent "<<endl;
    cout<<"6. Keluar"<<endl;
    int pilih;
    cout<<"Masukan Pilihan : ",cin>>pilih;
    if (pilih == 1){
        system("cls");
        InputView(pl,rl,cl,pilih);
    }else if (pilih == 2){
        system("cls");
        InputView(pl,rl,cl,pilih);
    }else if(pilih == 3){
        system("cls");
        subMenu(pl,rl,cl);
    }else if (pilih == 4){
        system("cls");
        adrParent P;
        banyakParent(pl,P);
    }
}

void subMenu(ListParent &pl, ListRelation &rl, ListChild &cl){
    system("cls");
    cout<<"================================="<<endl;
    cout<<"        APLIKASI KAMUS         "<<endl;
    cout<<"================================="<<endl;
    ShowFromTimestamp(CurrentTimestamp());
    cout<<endl;
    cout<<"================================="<<endl;
    cout<<"Silahkan Pilih Menu Utama"<<endl;
    cout<<"1. English only"<<endl;
    cout<<"2. Indonesia saja"<<endl;
    cout<<"3. Tampilkan Semua"<<endl;

    int pilih;
    cout<<"Masukan Pilihan : ",cin>>pilih;
    if (pilih == 1){
        cout << "KOSAKATA INGGRIS : "<<endl;
        system("cls");
        int bil;
        cout<<"===Menu==="<<endl;
        cout<<"1. Hapus kata"<<endl;
        cout<<"2. Kembali ke menu utama"<<endl;
        cout<<"Pilih menu diatas : ",cin>>bil;
        if (bil== 1){
            string kata;
            cout<<"Masukan kata yang ingin dihapus : ",cin>>kata;
        }else{
            system("cls");
            mainView(pl,rl,cl);
        }
    }else if (pilih == 2){
        cout << "KOSAKATA INDONESIA : "<<endl;
        system("cls");
        int bil;
        cout<<"===Menu==="<<endl;
        cout<<"1. Hapus kata"<<endl;
        cout<<"2. Kembali ke menu utama"<<endl;
        cout<<"Pilih menu diatas : ",cin>>bil;
        if (bil== 1){
            string kata;
            cout<<"Masukan kata yang ingin dihapus : ",cin>>kata;
        }else{
            system("cls");
            mainView(pl,rl,cl);
        }
    }else if(pilih == 3){
        system("cls");
        cout << "=====List All===== " << endl;
        show(rl);
    }
}

void InputView(ListParent &pl, ListRelation &rl, ListChild &cl,int menu){
    string kata;
    cout<<"Masukan kata : ";
    cin>>kata;
    switch(menu){
    case 1 :
        system("cls");
        IngToInd(pl,rl,cl,kata);
        break;
    case 2 :
        system("cls");
        IndoToIng(pl,rl,cl,kata);
        break;
    }
}

void IngToInd(ListParent &pl,ListRelation &rl,ListChild &cl,string kata){
    adrChild engWords = cariKata(cl,kata);
    string input = " ";
    if(engWords != NULL){
        update(engWords,info(engWords).counter++);
        adrRelation translate = cariParent(rl,engWords);
        if(translate != NULL){
           adrParent kataIndo = parent(translate);
           cout << "Translate Found ! ! !"<< endl;
           cout<<endl;
           cout << kata << " = " << info(kataIndo).kata << endl;
           update(translate,info(translate)++);
           cout<<endl;
           int pil;
           cout<<"Tekan 0 untuk ke menu utama : ",cin>>pil;
            if (pil==0){
                system("cls");
                mainView(pl,rl,cl);
            }

        }else{
            cout << "Translate Not Found ! ! !"<<endl;
            cout << "Insert new translate for this words [Y/N] ??";
            string input;
            cin >> input;
            if((input == "Y" ) || (input== "y")){
                addNew(rl,pl,engWords);
                int pil;
                cout<<endl;
                cout<<"Tekan 0 untuk ke menu utama : ",cin>>pil;
                    if (pil==0){
                        system("cls");
                        mainView(pl,rl,cl);
                    }else if (pil != 0){
                        system("cls");
                        mainView(pl,rl,cl);
                    }
            }else if (input == "N"){
                mainView(pl,rl,cl);
            }
        }
    }else{
        system("cls");
        cout << "Words Not Found ! ! !"<<endl;
        cout << "Insert new translate for this words [Y/N] ? ";
        cin >> input;
        if((input == "Y" ) || (input=="y")) {
            addNew(pl,rl,cl,kata,2);
             int pil;
                cout<<endl;
                cout<<"Tekan 0 untuk ke menu utama : ",cin>>pil;
                    if (pil==0){
                        system("cls");
                        mainView(pl,rl,cl);
                    }else if (pil != 0){
                        system("cls");
                        mainView(pl,rl,cl);
                    }
        }else if ((input== "N") || (input == "n")){
            system("cls");
            mainView(pl,rl,cl);
        }
    }
}
void IndoToIng(ListParent &parentList, ListRelation &relationList, ListChild &childList, string kata){
    adrParent Ind = cariKata(parentList,kata);
    string input  = "";
    if (Ind != NULL){
        update(Ind,info(Ind).counter++);
        adrRelation artikan = cariChild(relationList,Ind);
        if(artikan != NULL){
           adrChild kataEnglish = child(artikan);
           cout << "TERJEMAHAN DITEMUKAN"<< endl;
           cout<<endl;
           cout << kata << " = " << info(kataEnglish).kata << endl;
           update(artikan,info(artikan)++);
           int pil;
           cout<<"Tekan 0 untuk ke menu utama : ",cin>>pil;
            if (pil==0){
                system("cls");
                mainView(parentList,relationList,childList);
            }
        }else{
            cout << "Terjemahan Tidak Ditemukan"<<endl;
            cout << "Apakah ingin menambahkan kata terjemahan baru ? [Y/N]";
            cin >> input;
            if(input == "Y" ){
                addNew(relationList,childList,Ind);
                int pil;
                cout<<"Tekan 0 untuk ke menu utama : ",cin>>pil;
                    if (pil==0){
                        system("cls");
                        mainView(parentList,relationList,childList);
                    }else if (pil != 0){
                        system("cls");
                        mainView(parentList,relationList,childList);
                    }
            }
        }
    }else{
        cout << "KATA TIDAK DITEMUKAN"<<endl;
        cout << "Apakah ingin menambahkan terjemahan baru ?? [Y/N] ";
        cin >> input;
        if((input == "Y" ) || (input=="y")) {
            addNew(parentList,relationList,childList,kata,2);
             int pil;
                cout<<endl;
                cout<<"Tekan 0 untuk ke menu utama : ",cin>>pil;
                    if (pil==0){
                        system("cls");
                        mainView(parentList,relationList,childList);
                    }else if (pil != 0){
                        system("cls");
                        mainView(parentList,relationList,childList);
                    }
        }else if ((input== "N") || (input == "n")){
            system("cls");
            mainView(parentList,relationList,childList);
        }
    }
}


// type : 1 => EngtoInd, 2 => IndtoEng
void addNew(ListParent &pl,ListRelation &rl,ListChild &cl,string kata,int type){
    if(type == 1){
        adrParent P = alokasiParent(kata);
        insertLast(pl,P);
        cout << "Arti = ";
        string arti;
        cin >> arti;
        adrChild Q = alokasiChild(arti);
        insertLast(cl,Q);
        insertLast(rl,alokasi(P,Q));
    }
    else{
        adrChild Q = alokasiChild(kata);
        insertLast(cl,Q);
        cout << "Arti = ";
        string arti;
        cin >> arti;
        adrParent P = alokasiParent(arti);
        insertLast(pl,P);
        insertLast(rl,alokasi(P,Q));
    }
    cout << "Arti berhasil di tambahkan";

}
void addNew(ListRelation &rl,ListChild &cl,adrParent parent){
        cout << "Arti = ";
        string arti;
        cin >> arti;
        adrChild Q = alokasiChild(arti);
        insertLast(cl,Q);
        insertLast(rl,alokasi(parent,Q));
        cout << "Arti berhasil di tambahkan";
}

void addNew(ListRelation &rl,ListParent &pl,adrChild child){
        cout << "Arti = ";
        string arti;
        cin >> arti;
        adrParent P = alokasiParent(arti);
        insertLast(pl,P);
        insertLast(rl,alokasi(P,child));
        cout << "Arti berhasil di tambahkan";
}


