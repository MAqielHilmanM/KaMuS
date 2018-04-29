#include "SingleLinkList.h"


void createList(ListParent &L){
    first(L) = NULL;
}

adrParent alokasi(string kata){
    adrParent P;
    P = new elemen;
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
        adrParent Q;
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
        address P;
        P = next(first(L));
        next(first(L)) = next(P);
        next(P) = NULL;

    }
}


void show(ListParent &L){
    if(first(L) != NULL){
        adrParent P;
        P = first(L);
        while ( P  != NULL){
            cout<<"Kata : "<<info(P).kata<<endl;
            P = next(P);
        }
    }
}
address cari(ListParent L, string kata){
    if (first(L) != NULL){
        address P;
        P = first(L);
        while ((P != NULL) && (info(P).kata != kata)){
            P = next(P);
        }
        if (P != NULL){
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

void dealokasi(adrParent P){
    delete P;
}
