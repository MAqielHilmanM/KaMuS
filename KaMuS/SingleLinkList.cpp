#include "SingleLinkList.h"


void createList(linklist &L){
    first(L) = NULL;
}

address alokasi(string kata, int ID){
    address P = new elemen;
    info(P).kata = kata;
    info(P).ID = ID;
    next(P) = NULL;
    return P;
}

void insertFirst(linklist &L, address data){
    if (next(data) = NULL){
        first(L) = next(data);
        data = next(data);
    } else{
        first(L) = data;
    }
}
void show(linklist L){
    if(first(L) != NULL){
        address P;
        P = first(L);
        while (P  != NULL){
            cout<<"Kata : "<<info(P).kata<<endl;
            P = next(P);
        }
    }
}
void dealokasi(address P){
    delete P;
}

void insertAfter(linklist &L, address data, int x){
    if (first(L) != NULL){
        address P;
        P = first(L);
        int i = 1;
        while (P = NULL && i < x){
            P = next(P);
            i++;
        }
        if (P != NULL){
            next(data) = next(P);
            next(P) = data;
        }else{
            insertFirst(L, data);
        }
    }
}
void insertLast(linklist &L, address data){
    if (first(L) != NULL){
        address P;
        P = first(L);
        while (next(P) != NULL){
            P = next(P);
        }
        next(P) = data;
        data = NULL;
    }else{
        insertFirst(L,data);
    }
}
void deleteFirst(linklist &L){
    if (first(L) != NULL){
        address P;
        P = first(L);
        first(L) = next(P);
        dealokasi(P);
    }else {
        cout << "LIST SUDAH KOSONG"<<endl;
    }
}
void deleteAfter(linklist &L, address prec, address &data){
    if (first(L) != NULL && prec != NULL){
        address P;
        P = next(first(L));
        next(first(L)) = next(P);
        next(P) = NULL;

}
}
void deleteLast(linklist &L, int i){
    if (first(L) != NULL){
        address P;
        P = first(L);
        if (next(P) == NULL){
            deleteFirst(L);
        }else {
            address Q;
            Q = P;
            P = next(Q);
            while (next(P) != NULL){
                Q = P;
                P = next(Q);
            }
            next(Q) = NULL;
            dealokasi(P);
        }
    }
}
address cari(linklist L, string kata){
    if (first(L) != NULL){
        address P;
        P = first(L);
        while (P != NULL && info(P).kata != kata){
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
void update(address elemen_diubah, string kata){
    info(elemen_diubah).kata = kata;
}
