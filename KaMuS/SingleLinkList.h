#ifndef SINGLELINKLIST_H_INCLUDED
#define SINGLELINKLIST_H_INCLUDED

using namespace std;

struct parent{
    int ID;
    string kata;
    long int tanggal;
    int hint;
};

typedef struct elemen *address;

struct elemen{
    parent info;
    address next;
};
struct linklist{
    address firts;
};


void createList(linklist *P);
address alokasi(string kata, int ID);
void insertFirst(linklist *P, address data);
void show(linklist P);
void insertAfter(linklist *P, address data, int i);
void insertLast(linklist *P);
void deleteFirst(linklist *P);
void deleteAfter();
void deleteLast(linklist *P, int i);
address cari(linklist P, string kata);
void update(address elemen_diubah, string kata);

#endif // SINGLELINKLIST_H_INCLUDED
