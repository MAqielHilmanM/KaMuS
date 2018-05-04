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
    cout<<"5. Keluar"<<endl;
    int pilih;
    cout<<"Masukan Pilihan : ",cin>>pilih;
    if (pilih == 1){
        clear_screen();
        InputView(pl,rl,cl,pilih);
    }else if (pilih == 2){
        clear_screen();
        InputView(pl,rl,cl,pilih);
    }else if(pilih == 3){
        clear_screen();
        subMenu(pl,rl,cl);
    }else if (pilih == 4){
        clear_screen();
        adrParent P;
    }else{
        exit(0);
    }
}

void subMenu(ListParent &pl, ListRelation &rl, ListChild &cl){
    clear_screen();
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
        clear_screen();
        cout << "KOSAKATA INGGRIS : "<<endl;
        BanyakData(cl);
        cout << endl;
        show(cl);
        cout<<"===Menu==="<<endl;
        if(first(cl) != NULL) cout<<"1. Hapus kata"<<endl;
        cout<<"2. Kembali ke menu utama"<<endl;
        cout<<"Pilih menu diatas : ",cin>>pilih;
        if (pilih== 1 && (first(cl) != NULL)){
            string kata;
            adrChild cld;
            do{
                cout<<"Masukkan kata yang ingin dihapus : ",cin>>kata;
                cld = cariKata(cl,kata);
            }while(cld == NULL);
            if(cld != NULL){;
                deleteAfter(cl,prev(cld),cld);
                adrRelation rel;
                rel = cariParent(rl,cld);
                do{
                    if(rel != NULL){
                        deleteAfter(rl,prev(rel),rel);
                        rel = NULL;
                    }
                    rel = cariParent(rl,cld);
                }while(rel != NULL);

                cout << "delete kata berhasil" << endl;
            }
            backToHome(pl,rl,cl);
        }else{
                 backToHome(pl,rl,cl);
        }
    }else if (pilih == 2){
        clear_screen();
        cout << "KOSAKATA INDONESIA : "<<endl;
        BanyakData(pl);
        cout << endl;
        show(pl);
        cout<<"===Menu==="<<endl;
        if(first(pl) != NULL) cout<<"1. Hapus kata"<<endl;
        cout<<"2. Kembali ke menu utama"<<endl;
            cout<<"Pilih menu diatas : ",cin>>pilih;
        if (pilih== 1 && first(pl) != NULL){
        string kata;
        adrParent par,Q;
            do{
                cout<<"Masukkan kata yang ingin dihapus : ",cin>>kata;
                par = cariKata(pl,kata);
            }while(par == NULL);

            if(par != NULL && par != first(pl)){
                Q = first(pl);
                while(next(Q) != par){
                    Q = next(Q);
                }
                deleteAfter(pl,Q,par);
            }else{
                deleteFirst(pl,par);
            }
            adrRelation rel;
            rel = cariChild(rl,par);
            do{
                if(rel != NULL){
                    deleteAfter(rl,prev(rel),rel);
                    rel = NULL;
                }
                rel = cariChild(rl,par);
            }while(rel != NULL);
            cout << "delete kata berhasil" << endl;
            backToHome(pl,rl,cl);
        }else{
            backToHome(pl,rl,cl);
        }
    }else if(pilih == 3){
        clear_screen();
        cout << "=====List All===== " << endl;
        BanyakData(rl);
        cout << endl;
        show(rl);
        cout<<"===Menu==="<<endl;
        if(first(rl) != NULL) cout<<"1. Hapus kata"<<endl;
        cout<<"2. Kembali ke menu utama"<<endl;
        cout<<"Pilih menu diatas : ",cin>>pilih;
        if (pilih == 1 && (first(rl) != NULL)){
            string kataInd,kataEng;
            adrRelation rel;
            do{
                cout<<"Masukkan kata yang ingin dihapus (Indonesia) : ",cin>>kataInd;
                cout<<"Masukkan arti kata yang ingin dihapus (English) : ",cin>>kataEng;
                rel = cariRelation(rl,cariKata(pl,kataInd),cariKata(cl,kataEng));
            }while(rel == NULL);
            if(rel != NULL){;
                deleteAfter(rl,prev(rel),rel);
                cout << "delete arti berhasil" << endl;
            }
            backToHome(pl,rl,cl);

        }else{
            backToHome(pl,rl,cl);
        }
    }
}

void InputView(ListParent &pl, ListRelation &rl, ListChild &cl,int menu){
    string kata;
    if(menu == 1){
        ShowTop(rl,2);
        cout << endl;
        ShowTopKeyword(cl);
        cout << endl;
    }else if(menu == 2){
        ShowTop(rl,1);
        cout << endl;
        ShowTopKeyword(pl);
        cout << endl;
    }
    cout<<"Masukan kata : ";
    cin>>kata;
    switch(menu){
    case 1 :
        clear_screen();
        IngToInd(pl,rl,cl,kata);
        break;
    case 2 :
        clear_screen();
        IndoToIng(pl,rl,cl,kata);
        break;
    }
}

void IngToInd(ListParent &pl,ListRelation &rl,ListChild &cl,string kata){
    adrChild engWords = cariKata(cl,kata);
    string input = " ";
    if(engWords != NULL){
        info(engWords).counter++;
        cout << "Hasil pencarian terdapat "<<totalMultipleFromChild(rl,engWords)<<endl;
        if(totalMultipleFromChild(rl,engWords) > 1){
            cout << "TERJEMAHAN DITEMUKAN"<< endl;
            ShowMultipleFromChild(rl, engWords);
            cout << "Apakah ingin menambahkan arti baru ? [Y/N]";
            cin >> input;
            if(input == "Y" ){
                addNew(rl,pl,engWords);
            }
           backToHome(pl,rl,cl);
        }else{
            adrRelation translate = cariParent(rl,engWords);
            if(translate != NULL){
               adrParent kataIndo = parent(translate);
               cout << "Translate Found ! ! !"<< endl;
               cout<<endl;
               cout << kata << " = " << info(kataIndo).kata << endl;
               info(translate)++;
               cout<<endl;
               cout << "Apakah ingin menambahkan arti baru ? [Y/N]";
                cin >> input;
                if(input == "Y" ){
                    addNew(rl,pl,engWords);
                }
                backToHome(pl,rl,cl);
            }else{
                cout << "Translate Not Found ! ! !"<<endl;
                cout << "Insert new translate for this words [Y/N] ??";
                string input;
                cin >> input;
                if((input == "Y" ) || (input== "y")){
                    addNew(rl,pl,engWords);
                    backToHome(pl,rl,cl);
                }else if (input == "N"){
                    backToHome(pl,rl,cl);
                }
            }
        }
    }else{
        clear_screen();
        cout << "Words Not Found ! ! !"<<endl;
        cout << "Insert new translate for this words [Y/N] ? ";
        cin >> input;
        if((input == "Y" ) || (input=="y")) {
            addNew(pl,rl,cl,kata,2);
                backToHome(pl,rl,cl);
        }else if ((input== "N") || (input == "n")){
                backToHome(pl,rl,cl);
        }
    }
}
void IndoToIng(ListParent &parentList, ListRelation &relationList, ListChild &childList, string kata){
    adrParent Ind = cariKata(parentList,kata);
    string input  = "";
    if (Ind != NULL){
        info(Ind).counter++;
        if(totalMultipleFromParent(relationList, Ind) > 1){
            cout << "TERJEMAHAN DITEMUKAN"<< endl;
            ShowMultipleFromParent(relationList, Ind);
            cout << "Apakah ingin menambahkan arti baru ? [Y/N]";
            cin >> input;
            if(input == "Y" ){
                addNew(relationList,childList,Ind);
            }
           backToHome(parentList,relationList,childList);
        }else{
            adrRelation artikan = cariChild(relationList,Ind);
            if(artikan != NULL){
               adrChild kataEnglish = child(artikan);
               cout << "TERJEMAHAN DITEMUKAN"<< endl;
               cout<<endl;
               cout << kata << " = " << info(kataEnglish).kata << endl;
               info(artikan)++;

                cout << "Apakah ingin menambahkan arti baru ? [Y/N]";
                cin >> input;
                if(input == "Y" ){
                    addNew(relationList,childList,Ind);
                }
               backToHome(parentList,relationList,childList);
            }else{
                cout << "Terjemahan Tidak Ditemukan"<<endl;
                cout << "Apakah ingin menambahkan kata terjemahan baru ? [Y/N]";
                cin >> input;
                if(input == "Y" ){
                    addNew(relationList,childList,Ind);
                }
                backToHome(parentList,relationList,childList);
            }

        }
    }else{
        cout << "KATA TIDAK DITEMUKAN"<<endl;
        cout << "Apakah ingin menambahkan terjemahan baru ?? [Y/N] ";
        cin >> input;
        if((input == "Y" ) || (input=="y")) {
            addNew(parentList,relationList,childList,kata,1);
            cout<<endl;
            backToHome(parentList,relationList,childList);
         }else if ((input== "N") || (input == "n")){
            backToHome(parentList,relationList,childList);
        }
    }
}


// type : 2 => EngtoInd, 1 => IndtoEng
void addNew(ListParent &pl,ListRelation &rl,ListChild &cl,string kata,int type){
    if(type == 1){
        adrParent P = alokasiParent(kata);
        insertLast(pl,P);
        cout << "Arti = ";
        string arti;
        cin >> arti;
        adrChild Q;
        if(cariKata(cl,arti) != NULL){
            Q = cariKata(cl,arti);
        }
        else{
            Q = alokasiChild(arti);
            insertLast(cl,Q);
        }
        insertLast(rl,alokasi(P,Q));
    }
    else{
        adrChild Q = alokasiChild(kata);
        insertLast(cl,Q);
        cout << "Arti = ";
        string arti;
        cin >> arti;
        adrParent P;

        if(cariKata(pl,arti) != NULL){
            P = cariKata(pl,arti);
        }
        else{
            P = alokasiParent(arti);
            insertLast(pl,P);
        }

        insertLast(rl,alokasi(P,Q));
    }
    cout << "Arti berhasil di tambahkan";

}

//add new for English
void addNew(ListRelation &rl,ListChild &cl,adrParent parent){
        cout << "Arti = ";
        string arti;
        cin >> arti;
        adrChild Q;
        if(cariKata(cl,arti) != NULL){
            Q = cariKata(cl,arti);
        }
        else{
            Q = alokasiChild(arti);
            insertLast(cl,Q);
        }

        cout << info(parent).kata << " = "<< info(Q).kata << endl;
        insertLast(rl,alokasi(parent,Q));


        cout << "Arti berhasil di tambahkan";
}

//add new for Indo
void addNew(ListRelation &rl,ListParent &pl,adrChild child){
        cout << "Arti = ";
        string arti;
        cin >> arti;
        adrParent P;

        if(cariKata(pl,arti) != NULL){
            P = cariKata(pl,arti);
        }
        else{
            P = alokasiParent(arti);
            insertLast(pl,P);
        }

        cout << info(child).kata << " = "<< info(P).kata << endl;
        insertLast(rl,alokasi(P,child));
        cout << "Arti berhasil di tambahkan";
}


void backToHome(ListParent &pl, ListRelation &rl, ListChild &cl){
    cout << endl;
    cout<<"Press Enter to back to home  . . . "<<endl;
    PressToContinue();
    clear_screen();
    mainView(pl,rl,cl);
}
