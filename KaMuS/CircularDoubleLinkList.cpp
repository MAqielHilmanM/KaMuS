#include "CircularDoubleLinkList.h"

void createList(ListChild &L){
    first(L) = NULL;
}

adrChild alokasiChild(string kata){
    adrChild P = new elementChild;
    info(P).kata = kata;
    info(P).tanggal = CurrentTimestamp();
    info(P).counter = 0;
    next(P) = P;
    prev(P) = P;
    return P;
}

void dealokasi(adrChild P){
    delete P;
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

void insertLast(ListChild &L, adrChild P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(P)) = P;
        prev(first(L)) = P;
    }
}


void deleteFirst(ListChild &L, adrChild &P){
    if(first(L) == NULL){
        cout << "DATA KOSONG";
    }else {
        P = first(L);
        first(L) = next(P);
        prev(next(P)) = prev(P);
        next(prev(P)) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfter(ListChild &L, adrChild prec, adrChild &P){
    if(first(L) == NULL){
        cout << "DATA KOSONG";
    }else{
        next(prec) = P;

        next(prec) = next(P);
        prev(next(P)) = prec;

        prev(P) = NULL;
        next(P) = NULL;
    }
}

void deleteLast(ListChild &L, adrChild &P){
    if(first(L) == NULL){
        cout<< "DATA KOSONG";
    }else{
        P = prev(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
        dealokasi(P);
    }
}


adrChild cariKata(ListChild L, string kata){
    if(first(L) != NULL){
        adrChild child = first(L);
        do{
            child = next(child);
        }while(child != first(L) && info(child).kata != kata);

        if(info(child).kata == kata){
             return child;
        }else{
             cout << "Data Not Found";
        }
    }
}

void update(adrChild &elemen_diubah, string kata){
    if(elemen_diubah != NULL){
        info(elemen_diubah).kata = kata;
    }
}
void update(adrChild &elemen_diubah, int counter){
    if(elemen_diubah != NULL){
        info(elemen_diubah).counter = counter;
    }
}
void update(adrChild &elemen_diubah, long tanggal){
    if(elemen_diubah != NULL){
        info(elemen_diubah).tanggal = tanggal;
    }
}

void show(ListChild L){
    if(first(L) != NULL){
        adrChild P = first(L);
        do{
            cout << "Kata : "<<info(P).kata<<endl;
            cout << "tanggal : "<<info(P).tanggal<<endl;
            cout << "counter : "<<info(P).counter<<endl;
            P = next(P);
        }while(P != first(L));
    }
}
