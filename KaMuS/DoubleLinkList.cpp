#include "DoubleLinkList.h"


void createList(linklist &L){
    first(L) = NULL;
    last(L) = NULL;
}

address alokasi(){
    address P;
    P = new elemen;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

insertFirst(linklist &L, address data){
    if (first(L) == NULL){
        first(L) = data;
        last(L) = data;
    }else{
        next(data) = first(L);
        prev(first(L)) = data;
        first(L) = data;
    }
}

insertLast(linklist &L, address data){
    if (first(L) == NULL){
        first(L) = data;
        last(L) = data;
    }else{
        prev(data) = last(L);
        next(last(L)) = data;
        last(L) = data;
    }
}

void show(linklist L){
    if (first(L) == NULL){
        cout<< "DATA KOSONG";
    }else{
        address P;
        P = first(L);
        while( P != NULL){
            cout<< "blabla";
            P = next(P);
        }
    }
}

void deleteLast(linklist &L){
    if(first(L) == NULL){
        cout<< "DATA KOSONG";
    }else if(first(L) == last(L)){
        address P;
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        delete P;
    }else{
        address P;
        P = last(L);
        last(L) = prev(P);
        next(last(P)) = NULL;
        prev(P) = NULL;
        delete P;
    }
}

void deleteFirst(linklist &L){
    if(first(L) == NULL){
        cout << "DATA KOSONG";
    }else{
        address P;
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        delete P;
    }else {
        address P;
        P = first(L);
        first(L) = next(P);
        (prev(first(L)) = NULL;
        next(P) = NULL;
        delete P;
    }
}

void cari(linklist L, address data);
    if(first(L) == NULL){
        return NULL;
    }else{}








