#ifndef DOUBLELINKLIST_H_INCLUDED
#define DOUBLELINKLIST_H_INCLUDED

#include "SingleLinkList.h"
#include "mainHeader.h"
#include "CircularDoubleLinkList.h"

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

adrRelation cariRelation(ListRelation L, adrParent parent, adrChild child);

void update(adrRelation elemen_diubah, adrParent parent);
void update(adrRelation elemen_diubah, adrChild child);
void update(adrRelation elemen_diubah, int counter);
void show(ListRelation L);
void dealokasi(adrRelation P);

void BanyakData(ListRelation L);

int totalAkses(ListRelation L, adrChild P);
int totalAkses(ListRelation L, adrParent P);

void ShowTop(ListRelation L,int type);
ListRelation ShortingAscending(ListRelation L);


int totalMultipleFromChild(ListRelation L, adrChild child);
int totalMultipleFromParent(ListRelation L, adrParent parent);

void ShowMultipleFromParent(ListRelation L, adrParent parent);
void ShowMultipleFromChild(ListRelation L, adrChild child);


int TotalData(ListRelation L);
void ShowTop(ListRelation L, int type);
#endif // DOUBLELINKLIST_H_INCLUDED
