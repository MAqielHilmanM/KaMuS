#ifndef CIRCULARDOUBLELINKLIST_H_INCLUDED
#define CIRCULARDOUBLELINKLIST_H_INCLUDED

//Circullar Double Link List without pointer last used as Child (English word Storage)
#include "tools.h"
#include "mainHeader.h"

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

// InfoType :
// kata = used for save english keyword
// tanggal = used for save timestamp (conversion of date time)


struct infotypeChild{
    string kata;
    long tanggal;
    int counter;
};

typedef struct elementChild *adrChild;

struct elementChild{
    infotypeChild info;
    adrChild next;
    adrChild prev;
};

struct ListChild{
    adrChild first;
};



void createList(ListChild &L);

adrChild alokasiChild(string kata);
void dealokasi(adrChild P);

void insertFirst(ListChild &L, adrChild P);
void insertAfter(ListChild &L, adrChild prec, adrChild P);
void insertLast(ListChild &L, adrChild P);

void deleteFirst(ListChild &L, adrChild &P);
void deleteAfter(ListChild &L, adrChild prec, adrChild &P);
void deleteLast(ListChild &L, adrChild &P);

adrChild cariKata(ListChild L, string kata);
adrChild cariTanggal(ListChild L, long tanggal);
void update(adrChild &elemen_diubah, string kata);
void update(adrChild &elemen_diubah, int counter);
void update(adrChild &elemen_diubah, long tanggal);
void show(ListChild L);

void BanyakData(ListChild L);



#endif // CIRCULARDOUBLELINKLIST_H_INCLUDED
