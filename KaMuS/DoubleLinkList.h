#ifndef DOUBLELINKLIST_H_INCLUDED
#define DOUBLELINKLIST_H_INCLUDED

#include "SingleLinkList.h"
#include "CircularDoubleLinkList.h"
#include "mainHeader.h"


#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define child(P) P->child
#define parent(P) P->parent
#define last(L) L.last



typedef int infotype;

typedef struct elementRelation *adrRelation;

struct elementRelation{
    adrRelation next;
    adrRelation prev;
    adrChild child;
    adrParent parent;
    infotype info;
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

void deleteLast(ListRelation &L, adrRelation &P);
void deleteFirst(ListRelation &L, adrRelation &P);
void deleteAfter(ListRelation &L, adrRelation prec, adrRelation &P);

adrRelation cariParent(ListRelation L, adrChild child);
adrRelation cariChild(ListRelation L, adrParent parent);

void update(adrRelation elemen_diubah, string kata);
void show(ListRelation L);
void dealokasi(adrRelation P);



#endif // DOUBLELINKLIST_H_INCLUDED
