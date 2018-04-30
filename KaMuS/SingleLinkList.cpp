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
        next(Q) = P;
        }
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

void deleteLast(ListParent &L, adrParent P){
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
void deleteFirst(ListParent &L, adrParent P){
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
        adrParent Q;
        Q = next(first(L));
        next(first(L)) = next(P);
        next(P) = NULL;

    }else{
        cout<<"DATA TIDAK DITEMUKAN ";
    }
}

adrParent cariKata(ListParent L, string kata){
    if (first(L) != NULL){
        adrParent P;
        P = first(L);
        while ((P != NULL) && (info(P).kata != kata)){
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
            cout << i++ << "."<<endl;
            cout << "Kata : "<<info(P).kata<<endl;
            cout << "tanggal : ";
            ShowFromTimestamp(info(P).tanggal);
            cout << "counter : "<<info(P).counter<<endl;
            cout << endl;
            P = next(P);
        }
    }
}

void dealokasi(adrParent P){
    delete P;
}
