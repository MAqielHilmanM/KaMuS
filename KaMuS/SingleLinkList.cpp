#include "SingleLinkList.h"


void createList(linklist *P){
    first(P) = NULL;
}

address alokasi(string kata, int ID){
    address P = new elemen;
    info(P).kata = kata;
    info(P).ID = ID;
    next(P) = NULL;
    return P;
}

void insertFirst(linklist *P, address data);
void show(linklist P);
void insertAfter(linklist *P, address data, int i);
void insertLast(linklist *P);
void deleteFirst(linklist *P);
void deleteAfter();
void deleteLast(linklist *P, int i);
address cari(linklist P, string kata);
void update(address elemen_diubah, string kata);
