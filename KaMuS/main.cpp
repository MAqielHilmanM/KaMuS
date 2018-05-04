#include "view.h"
void Database(ListParent &parentList, ListRelation &relationList, ListChild &childList);

int main()
{
    ListParent parentList;
    ListChild childList;
    ListRelation relationList;

    createList(parentList);
    createList(childList);
    createList(relationList);

    Database(parentList,relationList,childList);

    mainView(parentList,relationList,childList);
//    show(relationList);
//    system("cls");
//    clrscr();
    return 0;
}

void Database(ListParent &parentList, ListRelation &relationList, ListChild &childList){
    adrParent parent1 = alokasiParent("aku");
    adrParent parent2 = alokasiParent("saya");
    adrParent parent3 = alokasiParent("ane");
    adrParent parent4 = alokasiParent("gua");

    adrChild child1 = alokasiChild("i");

    insertFirst(parentList,parent1);
    insertFirst(parentList,parent2);
    insertFirst(parentList,parent3);
    insertFirst(parentList,parent4);
    insertFirst(childList,child1);
    insertFirst(relationList,alokasi(parent1,child1));
    insertFirst(relationList,alokasi(parent2,child1));
    insertFirst(relationList,alokasi(parent3,child1));
    insertFirst(relationList,alokasi(parent4,child1));
}
