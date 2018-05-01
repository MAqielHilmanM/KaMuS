#include "view.h"

int main()
{
    ListParent parentList;
    ListChild childList;
    ListRelation relationList;

    createList(parentList);
    createList(childList);
    createList(relationList);

    adrParent parent1 = alokasiParent("aku");
    adrChild child1 = alokasiChild("i'm");

    insertFirst(parentList,parent1);
    insertFirst(childList,child1);
    insertFirst(relationList,alokasi(parent1,child1));

    mainView(parentList,relationList,childList);
//    show(relationList);
//    system("cls");
//    clrscr();
    return 0;
}
