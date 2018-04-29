#ifndef SINGLELINKLIST_H_INCLUDED
#define SINGLELINKLIST_H_INCLUDED

#include "mainHeader.h"
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next


struct infotypeParent{
    string kata;
    long tanggal;
    int counter;
};

typedef struct elementParent *adrParent;

struct elementParent{
    infotypeParent info;
    adrParent next;
};

struct ListParent{
    adrParent first;
};


void createList(ListParent &L);
adrParent alokasi(string kata);
void insertFirst(ListParent &L, adrParent P);
void insertLast(ListParent &L, adrParent P);
void insertAfter(ListParent &L, adrParent prec, adrParent P);
void deleteLast(ListParent &L, adrParent P);
void deleteFirst(ListParent &L, adrParent P);
void deleteAfter(ListParent &L, adrParent prec, adrParent &P);
adrParent cari(ListParent L, string kata);
void update(adrParent elemen_diubah, string kata);
void show(ListParent &L);
void dealokasi(adrParent P);
void cari(ListParent L, string kata)

#endif // SINGLELINKLIST_H_INCLUDED
