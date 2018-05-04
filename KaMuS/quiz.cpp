
void quizIndIng(){
    int i;
    i = 0;
    cout<<"Selamat datang di quiz ini "<<endl;
    cout<<"Quiz terdiri dari 2 pertanyaan"<<endl;
    cout<<"Let's Go"<<endl;
    cout<<"1. Apa arti dari kata saya "<<endl;
    cout<<"A. me"<<endl;
    cout<<"B. they"<<endl;
    cout<<"C. we"<<endl;
    cout<<"D. you"<<endl;
    string pil;
    cout<<"Pilih jawaban anda : ",cin>>pil;
    if (pil==A){
        i = i + 50;
    }else if(pil == B) || (pil == C) || (pil == D){
        i = i ;
    }
    string kata;
    cout<<"Lanjut ke soal berikutnya ? [Y/T]",cin>>kata;
    if (kata == "Y"){
        system("cls");
        soal2();
    }else{
        system("cls");
        adrParent pl;
        adrRelation rl;
        adrChild cl;
        mainView(pl,rl,cl);
    }
}
void quizIngInd(){
    int i;
    i = 0;
    cout<<"Welcome to the quiz "<<endl;
    cout<<"There are 2 question"<<endl;
    cout<<"Let's Go"<<endl;
    cout<<"1. a arti dari kata me "<<endl;
    cout<<"A. saya"<<endl;
    cout<<"B. mereka"<<endl;
    cout<<"C. kita"<<endl;
    cout<<"D. kamu"<<endl;
    string pil;
    cout<<"Pilih jawaban anda : ",cin>>pil;
    if (pil==A){
        i = i + 50;
    }else if(pil == B) || (pil == C) || (pil == D){
        i = i ;
    }
    string kata;
    cout<<"Lanjut ke soal berikutnya ? [Y/T]",cin>>kata;
    if (kata == "Y"){
        system("cls");
        soal2();
    }else{
        system("cls");
        adrParent pl;
        adrRelation rl;
        adrChild cl;
        mainView(pl,rl,cl);
    }
}

void soal2(){
    cout<<"2. Apa arti dari kata mereka "<<endl;
    cout<<"A. me"<<endl;
    cout<<"B. they"<<endl;
    cout<<"C. we"<<endl;
    cout<<"D. you"<<endl;
    string pil;
    cout<<"Pilih jawaban anda : ",cin>>pil;
    if (pil==B){
        i = i + 50;
    }else if(pil == A) || (pil == C) || (pil == D){
        i = i ;
    }
    cout<<"Selesai"<<endl;
    cout<<"Nilai anda adalah : "<<i<<endl;
    string kata;
    cout<<"Kembali ke menu ? [Y/T]",cin>>kata;
    if (kata == "Y"){
        system("cls");
        adrParent pl;
        adrRelation rl;
        adrChild cl;
        mainView(pl,rl,cl);
    }
}
