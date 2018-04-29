#ifndef CIRCULARDOUBLELINKLIST_H_INCLUDED
#define CIRCULARDOUBLELINKLIST_H_INCLUDED

//Circullar Double Link List without pointer last used as Child (English word Storage)
#include "mainHeader.h"

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

// InfoType :
// kata = used for save english keyword
// tanggal = used for save timestamp (conversion of date time)
// counter = used for save how many this data been accessed

struct infotypeChild{
    string kata;
    long tanggal;
    int counter;
};

typedef struct elementChild *adrChild;
typedef struct elementaChild *adrChild;

struct elementaChild{
    infotypeChild info;
    adrChild next;
    adrChild prev;
};

struct ListChild{
    adrChild first;
    adrChild last;
};


void createList(ListChild &L);

adrChild alokasi(string kata);
void dealokasi(adrChild P);

void insertFirst(ListChild &L, adrChild P);
void insertAfter(ListChild &L, adrChild prec, adrChild P);
void insertLast(ListChild &L, adrChild P);

void deleteFirst(ListChild &L, adrChild P);
void deleteAfter(ListChild &L, adrChild prec, adrChild &P);
void deleteLast(ListChild &L, adrChild P);

adrChild cari(ListChild L, string kata);
void update(adrChild elemen_diubah, string kata);
void show(ListChild L);



#endif // CIRCULARDOUBLELINKLIST_H_INCLUDED
