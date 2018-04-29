#include "DoubleLinkList.h"

void dllcreateList(linklist &L){
    first(L) = NULL;
    last(L) = NULL;
}
void dlldealokasi(adrRelation P){
    delete P;
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
void dllinsertFirst(linklist &L, address P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void dllinsertLast(linklist &L, address P){
    if (first(L) != NULL){
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }else{
        dllinsertFirst(L,P);
    }
}
void dllinsertAfter(linklist &L, address prec, address &P){
   if (first(L) != NULL) && (prec != NULL){
        if (next(prec) != NULL){
            prev(P) = prec;
            next(P) = next(prec);
            prev(next(prec)) = P;
            next(prec) = P;
        }else{
            dllinsertLast(L,P);
        }
   }else{
        dllinsertFirst(L,P);
    }
}
void dlldeleteLast(linklist &L, address P){
    if (first(L) != NULL){
        P = last(L);
        if (last(L) != first(L)){
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }else{
            dllcreateList(L);
        }
    }else{
        cout<<"DATA KOSONG";
    }
}

void dlldeleteFirst(linklist &L, address P){
    if (first(L) != NULL){
        P = first(L);
        if (first(L) != Last(L)){
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }else{
            dllcreateList(L);
        }
    }else{
        cout<<"DATA KOSONG:;
    }
}
void dlldeleteLast(linklist &L, adrRelation P){
    if(last(L) == NULL){
        P = last(L);
        if (last(L) != first(L){
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }else{
            createList(L);
        }
    }else{
        cout<<"DATA KOSONG";
    }
}

void dllcari(linklist L, adrRelation P){
    if (first(L) != NULL){
        Q = first(L);
        while (next(Q) != NULL) && (info(P) != info(P){
                Q = next(Q);
        }if (info(Q) == info(P)){
            return info(Q);
        }else{
            return NULL;
        }
    }else{
        cout<< "DATA TIDAK ADA";
    }
}
void dllshow(linklist L){
    if (first(L) != NULL){
        Last(L) = first(L);
        while (next(Last(L)) != NULL){
            cout<<info(last(L));
            Last(L) = next(last(L));
        }
    }
}




