#include "DoubleLinkList.h"

void createList(ListRelation &L){
    first(L) = NULL;
    last(L) = NULL;
}

adrRelation alokasi(adrParent parent, adrChild child){
    adrRelation P = new elementRelation;
    parent(P) = parent;
    child(P) = child;
    info(P) = 0;
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
void insertAfter(ListRelation &L, adrRelation prec, adrRelation P){
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
void deleteLast(ListRelation &L, adrRelation &P){
    if (first(L) !=  NULL){
        P = last(L);
        if (last(L) != first(L)){
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

void deleteFirst(ListRelation &L, adrRelation &P){
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
void deleteAfter(ListRelation &L, adrRelation prec, adrRelation &P){
    if ((first(L) != NULL) && (prec !=  NULL)){
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

adrRelation cariParent(ListRelation L, adrChild child){
    if (first(L) != NULL){
        adrRelation P = first(L);
        while(next(P) != NULL && child(P) != child){
            P = next(P);
        }
        if (child(P) == child){
            return P;
        }else{
            return NULL;
        }
    }else{
        cout <<"DATA TIDAK ADA";
    }
}


adrRelation cariChild(ListRelation L, adrParent parent){
    if (first(L) != NULL){
        adrRelation P = first(L);
        while(next(P) != NULL && parent(P) != parent){
            P = next(P);
        }
        if (parent(P) == parent){
            return P;
        }else{
            return NULL;
        }
    }else{
        cout <<"DATA TIDAK ADA";
    }
}
void update(adrRelation elemen_diubah, adrParent parent){
    parent(elemen_diubah) = parent;
}
void update(adrRelation elemen_diubah, adrChild child){
    child(elemen_diubah) = child;
}
void update(adrRelation elemen_diubah, int counter){
    info(elemen_diubah) = counter;
}


void show(ListRelation L){
    int i = 1;
    if (first(L) != NULL){
        last(L) = first(L);
        cout << i++ << ". " << info(parent(last(L))).kata << " = "<< info(child(last(L))).kata << endl;
        while(next(last(L)) != NULL){
            cout << i++ << ". " << info(parent(last(L))).kata << " = "<< info(child(last(L))).kata << endl;
            last(L) = next(last(L));
        }
    }
}


void dealokasi(adrRelation P){
    delete P;
}






