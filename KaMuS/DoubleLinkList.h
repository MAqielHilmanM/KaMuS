#ifndef DOUBLELINKLIST_H_INCLUDED
#define DOUBLELINKLIST_H_INCLUDED

#include "mainHeader.h"
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define last(L) L.last

using namespace std;
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
    address prev;
};
struct linklist{
    address first;
    address last;
};





void createList(linklist &L);
address alokasi(string kata, int ID);
void insertFirst(linklist &L, address P);
void insertLast(linklist &L, address P);
void insertAfter(linklist &L, address prec, address P);
void deleteLast(linklist &L, address P);
void deleteFirst(linklist &L, address P);
void deleteAfter(linklist &L, address prec, address &P);
address cari(linklist L, string kata);
void update(address elemen_diubah, string kata);
void show(linklist L);
void dealokasi(address P);



#endif // DOUBLELINKLIST_H_INCLUDED
