#include "CircularDoubleLinkList.h"

void createList(List &L){
    first(L) = NULL;
}

address alokasi(string kata){
    address P;
    P = new element;
    info(P).kata = kata;
    next(P) = P;
    prev(P) = P;
    return P;
}

void insertFirst(List &L, address P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
/*
void insertLast(List &L, address P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = last(L);
        prev(last(L)) = P;
        last(L) = P;
    }
}
void insertAfter(List &L, address prec, address &P){
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
void deleteLast(List &L, address P){
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
void deleteFirst(List &L, address P){
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
*/
