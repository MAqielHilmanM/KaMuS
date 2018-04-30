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
    cout<<"2. Indonesia to Inggris"<<endl;
    cout<<"3. Database"<<endl;
    int pilih;
    cout<<"Masukan Pilihan : ",cin>>pilih;
    if (pilih == 1){
        InputView(pl,rl,cl,pilih);
    }else if (pilih == 2){
        InputView(pl,rl,cl,pilih);
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
    }else if (pilih == 2){
    }
}

void InputView(ListParent &pl, ListRelation &rl, ListChild &cl,int menu){
    string kata;
    cout<<"Masukan kata : ";
    cin>>kata;
    switch(menu){
    case 1 :
        IngToInd(pl,rl,cl,kata);
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
           cout << kata << " = " << info(kataIndo).kata << endl;
           update(translate,info(translate)++);
        }else{
            cout << "Translate Not Found ! ! !"<<endl;
            cout << "Insert new translate for this words [Y/N] ??";
            cin >> input;
            if(input == "Y" ) addNew(rl,pl,engWords);
        }
    }else{
        cout << "Words Not Found ! ! !"<<endl;
        cout << "Insert new translate for this words [Y/N] ? ";
        cin >> input;
        if(input == "Y" ) {
            addNew(pl,rl,cl,kata,1);
        }
    }
}

// type : 1 => EngtoInd, 2 => IndtoEng
void addNew(ListParent &pl,ListRelation &rl,ListChild &cl,string kata,int type){
    if(type == 1){
        adrParent P = alokasiParent(kata);
        insertLast(pl,P);
        cout << "arti = ";
        string arti;
        cin >> arti;
        adrChild Q = alokasiChild(arti);
        insertLast(cl,Q);
        insertLast(rl,alokasi(P,Q));
    }
    else{
        adrChild Q = alokasiChild(kata);
        insertLast(cl,Q);
        cout << "arti = ";
        string arti;
        cin >> arti;
        adrParent P = alokasiParent(arti);
        insertLast(pl,P);
        insertLast(rl,alokasi(P,Q));
    }
    cout << "arti berhasil di tambahkan";
}

void addNew(ListRelation &rl,ListChild &cl,adrParent parent){
        cout << "arti = ";
        string arti;
        cin >> arti;
        adrChild Q = alokasiChild(arti);
        insertLast(cl,Q);
        insertLast(rl,alokasi(parent,Q));
        cout << "arti berhasil di tambahkan";
}
void addNew(ListRelation &rl,ListParent &pl,adrChild child){
        cout << "arti = ";
        string arti;
        cin >> arti;
        adrParent P = alokasiParent(arti);
        insertLast(pl,P);
        insertLast(rl,alokasi(P,child));
        cout << "arti berhasil di tambahkan";
}
