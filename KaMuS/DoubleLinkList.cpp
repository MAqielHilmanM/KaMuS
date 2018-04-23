#include "DoubleLinkList.h"

void createList(linklist &L){
    first(L) = NULL;
    last(L) = NULL;
}

address alokasi(string kata, int ID){
    address P;
    P = new elemen;
    info(P).kata = kata;
    info(P).ID = ID;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void insertFirst(linklist &L, address P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLast(linklist &L, address P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = last(L);
        prev(last(L)) = P;
        last(L) = P;
    }
}
void insertAfter(linklist &L, address prec, address &P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = next(prec);
        next(prec) =  P;
        prev(P) = prec;
        prev(next(P)) = P;
    }
}
void deleteLast(linklist &L, address P){
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
        next(last(L)) = NULL;
        prev(P) = NULL;
        delete P;
    }
}
void dealokasi(address P){
    delete P;
}
void deleteFirst(linklist &L, address P){
    if(first(L) == NULL){
        cout << "DATA KOSONG";
    }else if(next(first(L))== NULL){
        address P;
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
        dealokasi(P);
    }else {
        address P;
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
        delete P;
    }
}









