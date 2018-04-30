#include "view.h"

int main()
{
    ListParent parentList;
    ListChild childList;
    ListRelation relationList;

    createList(parentList);
    createList(childList);
    createList(relationList);

    mainView(parentList,relationList,childList);
    system("cls");
    return 0;
}
