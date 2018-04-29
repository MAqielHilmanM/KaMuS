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

typedef struct elemen *adrRelation;

struct elemen{
    parent info;
    address next;
    address prev;
};
struct linklist{
    address first;
    address last;
};





void dllcreateList(linklist &L);
address alokasi(string kata, int ID);
void dllinsertFirst(linklist &L, address P);
void dllinsertLast(linklist &L, address P);
void dllinsertAfter(linklist &L, address prec, address P);
void dlldeleteLast(linklist &L, address P);
void dlldeleteFirst(linklist &L, address P);
void dlldeleteAfter(linklist &L, address prec, address &P);
address dllcari(linklist L, string kata);
void dllupdate(address elemen_diubah, string kata);
void dllshow(linklist L);
void dlldealokasi(address P);



#endif // DOUBLELINKLIST_H_INCLUDED
