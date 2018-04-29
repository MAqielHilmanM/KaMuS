#ifndef DOUBLELINKLIST_H_INCLUDED
#define DOUBLELINKLIST_H_INCLUDED

#include "mainHeader.h"
#include "SingleLinkList.h"
#include "CircularDoubleLinkList.h"
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define last(L) L.last

struct infotypeRelation{
    adrParent idParent;
    adrChild;
    int i;
};

typedef struct elementRelation *adrRelation;

struct elementRelation{
    infotypeRelation info;
    adrRelation next;
    adrRelation prev;
};
struct ListRelation{
    adrRelation first;
    adrRelation last;
};

void createList(ListRelation &L);
adrRelation alokasi(adrParent parent, adrChild child);
void insertFirst(ListRelation &L, adrRelation P);
void insertLast(ListRelation &L, adrRelation P);
void insertAfter(ListRelation &L, adrRelation prec, adrRelation P);
void deleteLast(ListRelation &L, adrRelation P);
void deleteFirst(ListRelation &L, adrRelation P);
void deleteAfter(ListRelation &L, adrRelation prec, adrRelation &P);
adrRelation cari(ListRelation L, string kata);
void update(adrRelation elemen_diubah, string kata);
void show(ListRelation L);
void dealokasi(adrRelation P);



#endif // DOUBLELINKLIST_H_INCLUDED
