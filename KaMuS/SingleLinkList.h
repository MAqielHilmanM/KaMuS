#ifndef SINGLELINKLIST_H_INCLUDED
#define SINGLELINKLIST_H_INCLUDED

#include "mainHeader.h"
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define stdlib.h

struct parent{
    int ID;
    string kata;
    long tanggal;
    int hint;
};

typedef struct elemen *address;

struct elemen{
    parent info;
    address next;
};
struct linklist{
    address first;
};


void createList(linklist &L);
address alokasi(string kata, int ID);
void insertFirst(linklist &L, address data);
void show(linklist L);
void insertAfter(linklist &L, address data, int i);
void insertLast(linklist &L);
void deleteFirst(linklist &L);
void deleteAfter();
void deleteLast(linklist &L, int i);
address cari(linklist L, string kata);
void update(address ele9men_diubah, string kata);

#endif // SINGLELINKLIST_H_INCLUDED
