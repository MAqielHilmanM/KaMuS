#include "SingleLinkList.h"


void SLLcreateList(linklist &L){
    first(L) = NULL;
}

address SLLalokasi(string kata, int ID){
    address P;
    P = new elemen;
    info(P).kata = kata;
    info(P).ID = ID;
    next(P) = NULL;
    return P;
}
void SLLinsertFirst(linklist L, address P){
    if (first(L) == NULL){
         first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void SLLinsertLast(linklist L, address P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        address Q;
        while (next(Q) != NULL){
            Q = next(Q);
        next(Q) = P;
        }
    }
}
void SLLinsertAfter(linklist &L, address prec, address P){
    if (first(L) == NULL){
        if (first(L) == NULL){
             first(L) = P;
        }else{
            next(P) = first(L);
            first(L) = P;
        }

    }else if (next(first(L))== NULL){
            if (first(L) == NULL){
            first(L) = P;
        }else{
            address Q;
            while (next(Q) != NULL){
                Q = next(Q);
            next(Q) = P;
            }
        }
    }else{
        next(P) = next(prec);
        next(prec) = P;
    }
}

void SSLdeleteFirst(linklist &L, address P){
    if (first(L) == NULL){
        cout<<"MOHON MAAF DATA KOSONG";
    }else if ( next(first(L)) == NULL ){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void SLLdeleteAfter(linklist &L, address prec, address &P){
    if (first(L) != NULL && prec != NULL){
        address P;
        P = next(first(L));
        next(first(L)) = next(P);
        next(P) = NULL;

    }
}


void SLLshow(linklist L){
    if(first(L) != NULL){
        address P;
        P = first(L);
        while ( P  != NULL){
            cout<<"Kata : "<<info(P).kata<<endl;
            P = next(P);
        }
    }
}
address SLLcari(linklist L, string kata){
    if (first(L) != NULL){
        address P;
        P = first(L);
        while ((P != NULL) && (info(P).kata != kata)){
            P = next(P);
        }
        if (P != NULL){
            return P;
        } else {
            return NULL;
    }
    }else {
        return NULL;

    }
}
void SLLupdate(address elemen_diubah, string kata){
    info(elemen_diubah).kata = kata;
}

void SLLdealokasi(address P){
    delete P;
}
