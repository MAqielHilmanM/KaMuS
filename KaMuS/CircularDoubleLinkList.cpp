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
        next(P) = first(L);
    }else{
        next(P) = first(L);
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter(ListChild &L, adrChild prec, adrChild P){
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
    }else if(next(first(L)) != first(L)){
        P = first(L);
        first(L) = next(P);
        prev(next(P)) = prev(P);
        next(prev(P)) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        P = first(L);
        first(L) = NULL;
        prev(P) = NULL;
        next(P) = NULL;
    }
}

void deleteAfter(ListChild &L, adrChild prec, adrChild &P){
    if(first(L) == NULL){
        cout << "DATA KOSONG";
    }else if(next(prec) != prec){
        next(prec) = P;

        next(prec) = next(P);
        prev(next(P)) = prec;

        prev(P) = NULL;
        next(P) = NULL;
    }else{
        deleteFirst(L,P);
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
            return NULL;
        }
    }else{
        return NULL;
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
    int i = 1;
    if(first(L) != NULL){
        adrChild P = first(L);
        do{
            cout << i++ << "."<<endl;
            cout << "Kata : "<<info(P).kata<<endl;
            cout << "tanggal : ";
            ShowFromTimestamp(info(P).tanggal);
            cout << "total akses : "<<info(P).counter<<endl;
            cout << endl;
            P = next(P);
        }while(P != first(L));
    }
}
void BanyakData(ListChild L){
    int i = 0;
    if(first(L) != NULL){
        adrChild P = first(L);
        do{
            i++;
            P = next(P);
        }while(P != first(L));
        cout << "Banyak Terjemahan yang tersedia : " <<i<<endl;
    }
}

int TotalData(ListChild L){
    int i = 0;
    if(first(L) != NULL){
        adrChild P = first(L);
        do{
            i++;
            P = next(P);
        }while (P != first(L));
    }
    return i;
}

void ShowTopKeyword(ListChild L){
    if(first(L) != NULL){
        cout << "Top Keyword : ";
        ListChild NewL = ShortingAscending(L);
        adrChild P = first(NewL);
        if(TotalData(NewL) > 3){
            for(int i = 0; i < 3; i++){
                cout << info(P).kata << ", ";
                P = next(P);
            }
        }else{
            do{
                cout << info(P).kata << ", ";
                P = next(P);
            }while(P != first(NewL));
        }

    }
}

ListChild ShortingAscending(ListChild L){
    ListChild Lnew,Lold;
    Lold = L;
    createList(Lnew);
    adrChild P,Q;
    while(first(Lold) != NULL){
        deleteFirst(Lold,P);
        if(first(Lnew) == NULL || info(P).counter < info(first(Lnew)).counter){
            insertFirst(Lnew,P);
        }else{
            Q = first(Lnew);
            while(next(Q) != NULL && info(next(Q)).counter < info(P).counter){
                Q = next(Q);
            }
            if(next(Q) == NULL){
                insertLast(Lnew,P);
            }else if(info(Q).counter >= info(P).counter){
                insertAfter(Lnew,Q,P);
            }
        }
    }
    return Lnew;
}
