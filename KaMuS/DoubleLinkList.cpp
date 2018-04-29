#include "DoubleLinkList.h"

void createList(ListRelation &L){
    first(L) = NULL;
    last(L) = NULL;
}

adrRelation alokasi(adrParent kata, adrChild child){
    adrRelation P;
    P = new elementRelation;
    info(P).kata =kata;
    info(P).ID = ID;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void insertFirst(ListRelation &L, adrRelation P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLast(ListRelation &L, adrRelation P){
    if (first(L) != NULL){
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }else{
        insertFirst(L,P);
    }
}
void insertAfter(ListRelation &L, adrRelation prec, adrRelation &P){
    if ((first(L) != NULL) && (prec != NULL)){
        if (next(prec) != NULL){
            prev(P) = prec;
            next(P) = next(prec);
            prev(next(prec)) = P;
            next(prec) = P;

        }else{
            insertLast(L,P);
        }
    }else{
        insertFirst(L,P);
    }
}
void deleteLast(ListRelation &L, adrRelation P){
    if (first(L) !=  NULL){
        P = last(L);
        if (last(L) != first(L){
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }else{
            createList(L);
        }
    }else{
        cout<<"DATA TIDAK DITEMUKAN";
    }
}
void dealokasi(adrRelation P){
    delete P;
}
void deleteFirst(ListRelation &L, adrRelation P){
  if (first(L) != NULL){
    P = first(L) ;
    if (first(L) != last(L)){
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }else{
        createList(L);
    }
  }else{
    cout<<"DATA TIDAK DITEMUKAN ";
 }
}
void deleteAfter(ListRelation &L, adrRelation &P){
    if (first(L) != NULL) && (prec !=  NULL){
        if (prec != last(L)){
            P = next(prec);
            next(prec) = next(P);
            prev(next(prec)) = prec;
            next(P) = NULL;
            prev(P) = NULL;
        }else{
            deleteFirst(L,P);
        }
    }else{
        cout<<"DATA TIDAK DITEMUKAN";
    }
}

address cari(ListRelation L, string kata){
    if (first(L) != NULL){
        adrRelation P;
        while(next(P) != NULL) && (info(P) != info(kata)){
            P = next(P);
        }
        if (info(P) = info(kata)){
            return P;
        }else{
            return NULL;
        }
    }else{
        cout <<"DATA TIDAK ADA";
    }
}
void show(ListRelation L){
    if (first(L) != NULL){
        last(L) = first(L);
        while (next(last(L)) != NULL){
            cout<< info(last(L));
            last(L) = next(last(L));
        }
    }









