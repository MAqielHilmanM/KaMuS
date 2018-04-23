#ifndef SINGLELINKLIST_H_INCLUDED
#define SINGLELINKLIST_H_INCLUDED

#include "mainHeader.h"
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#include <stdlib.h>


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


void SLLcreateList(linklist &L);
address alokasi(string kata, int ID);
void SLLinsertFirst(linklist &L, address P);
void SLLinsertLast(linklist &L, address P);
void SLLinsertAfter(linklist &L, address prec, address P);
void SLLdeleteLast(linklist &L, address P);
void SLLdeleteFirst(linklist &L, address P);
void SLLdeleteAfter(linklist &L, address prec, address &P);
address cari(linklist L, string kata);
void SLLupdate(address elemen_diubah, string kata);
void SLLshow(linklist L);
void SLLdealokasi(address P);

#endif // SINGLELINKLIST_H_INCLUDED
