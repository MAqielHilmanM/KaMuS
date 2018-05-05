#include "SingleLinkList.h"


void createList(ListParent &L){
    first(L) = NULL;
}

adrParent alokasiParent(string kata){
    adrParent P = new elementParent;
    info(P).kata = kata;
    info(P).tanggal = CurrentTimestamp();
    info(P).counter = 0;
    next(P) = NULL;
    return P;
}

void insertFirst(ListParent &L, adrParent P){
    if (first(L) == NULL){
         first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(ListParent &L, adrParent P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        adrParent Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void insertAfter(ListParent &L, adrParent prec, adrParent P){
    if (first(L) == NULL){
        if (first(L) == NULL){
             first(L) = P;
        }else{
            next(P) = first(L);
            first(L) = P;
        }

    }else if (next(first(L))== NULL){
            if (first(L) == NULL){
            first(L) = P;
        }else{
            adrParent Q;
            while (next(Q) != NULL){
                Q = next(Q);
                next(Q) = P;
            }
        }
    }else{
        next(P) = next(prec);
        next(prec) = P;
    }
}

void deleteLast(ListParent &L, adrParent &P){
    if (first(L) == NULL){
        cout<<"DATA TIDAK DITEMUKAN";
    }else if (next(first(L)) == NULL){
         P = first(L);
         first(L) = NULL;
    }else{
        adrParent Q;
        P = first(L);
        while (next(next(P)) != NULL){
            P = next(P);
        Q = next(P);
        next(P) = NULL;
        }
    }
}
void deleteFirst(ListParent &L, adrParent &P){
    if (first(L) == NULL){
        cout<<"MOHON MAAF DATA KOSONG";
    }else if ( next(first(L)) == NULL ){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteAfter(ListParent &L, adrParent prec, adrParent &P){
    if (first(L) != NULL && prec != NULL){
        P = next(prec);
        if(next(P) != NULL)
            next(prec) = next(P);
        next(P) = NULL;
    }else if(first(L) != NULL && prec == NULL){
        deleteFirst(L,P);
    }else{
        cout<<"DATA TIDAK DITEMUKAN ";
    }
}

adrParent cariKata(ListParent L, string kata){
    if (first(L) != NULL){
        adrParent P;
        P = first(L);
        while ((next(P) != NULL) && (info(P).kata != kata)){
            P = next(P);
        }
        if (info(P).kata == kata){
            return P;
        } else {
            return NULL;
        }
    }else {
        return NULL;

    }
}

adrParent cariTanggal(ListParent L, long tanggal){
    if (first(L) != NULL){
        adrParent P;
        P = first(L);
        while ((P != NULL) && (info(P).tanggal != tanggal)){
            P = next(P);
        }
        if (info(P).tanggal == tanggal){
            return P;
        } else {
            return NULL;
    }
    }else {
        return NULL;

    }
}
void update(adrParent elemen_diubah, string kata){
    info(elemen_diubah).kata = kata;
}
void update(adrParent elemen_diubah, int counter){
    info(elemen_diubah).counter = counter;
}
void update(adrParent elemen_diubah, long tgl){
    info(elemen_diubah).tanggal = tgl;
}
void show(ListParent L){
    int i = 1;
    if(first(L) != NULL){
        adrParent P;
        P = first(L);
        while ( P  != NULL){
            cout<<"=====Indonesian Only==="<<endl;
            cout << i++ << "."<<endl;
            cout << "Kata : "<<info(P).kata<<endl;
            cout << "Tanggal : ";
            ShowFromTimestamp(info(P).tanggal);
            cout << "Counter : "<<info(P).counter<<endl;
            cout << endl;
            P = next(P);
        }
    }
}

void dealokasi(adrParent P){
    delete P;
}
void BanyakData(ListParent parentList){
    int i;
    i = 0;
    adrParent P = first(parentList);
    while (P != NULL){
        P = next(P);
        i = i + 1;
    }
    cout<<"Banyaknya Kata yang tersedia : "<<i<<endl;
}

int TotalData(ListParent L){
    int i = 0;
    if(first(L) != NULL){
        adrParent P = first(L);
        i++;
        while (P != NULL){
            P = next(P);
            i = i + 1;
        }
    }
    return i;
}

void ShowTopKeyword(ListParent L){
    if(first(L) != NULL){
        cout << "Top Keyword : ";
        ListParent NewL;
        createList(NewL);
        NewL = ShortingAscending(L);
        adrParent P = first(NewL);
        if(TotalData(NewL) > 3){
            for(int i = 0; i < 3; i++){
                cout << info(P).kata << ", ";
                P = next(P);
            }
        }else{
            do{
                cout << info(P).kata << ", ";
                P = next(P);
            }while(next(P) != NULL);
        }

    }
}

ListParent ShortingAscending(ListParent L){
    ListParent Lnew,Lold;
    Lold = L;
    createList(Lnew);
    adrParent P,Q;
    while(first(Lold) != NULL){
        deleteFirst(Lold,P);
        if(first(Lnew) == NULL || info(P).counter < info(first(Lnew)).counter){
            insertFirst(Lnew,P);
        }else{
            Q = first(Lnew);
            while(next(Q) != NULL && info(next(Q)).counter < info(P).counter){
                Q = next(Q);
            }
            if(next(Q) == NULL){
                insertLast(Lnew,P);
            }else if(info(Q).counter >= info(P).counter){
                insertAfter(Lnew,Q,P);
            }
        }
    }
    return Lnew;
}
