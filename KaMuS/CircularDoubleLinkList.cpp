#include "CircularDoubleLinkList.h"

void createList(ListChild &L){
    first(L) = NULL;
}

adrChild alokasi(string kata){
    adrChild P;
    P = new elementChild;
    info(P).kata = kata;
    info(P).tanggal = CurrentTimestamp();
    info(P).counter = 0;
    next(P) = P;
    prev(P) = P;
    return P;
}

void insertFirst(ListChild &L, adrChild P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(ListChild &L, adrChild P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        adrChild Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        prev(first(L)) = P;
        prev(P) = Q;
        next(Q) = P;
    }
}
void insertAfter(ListChild &L, adrChild prec, adrChild &P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = next(prec);
        next(prec) =  P;
        prev(P) = prec;
        prev(next(P)) = P;
    }
}
void deleteLast(ListChild &L, adrChild P){
    if(first(L) == NULL){
        cout<< "DATA KOSONG";
    }else{
        adrChild Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        P = Q;
        Q = prev(Q);
        Q = first(L);
        prev(first(L)) = Q;
        dealokasi(P);
    }
}
void dealokasi(adrChild P){
    delete P;
}

/*
void deleteFirst(ListChild &L, adrChild P){
    if(first(L) == NULL){
        cout << "DATA KOSONG";
    }else if(next(first(L))== NULL){
        adrChild P;
        P = first(L);
        first(L) = NULL;
        dealokasi(P);
    }else {
        adrChild P;
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
        delete P;
    }
}
*/
