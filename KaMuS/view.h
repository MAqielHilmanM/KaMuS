#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include "mainHeader.h"
#include "tools.h"
#include "CircularDoubleLinkList.h"
#include "SingleLinkList.h"
#include "DoubleLinkList.h"

void mainView(ListParent &pl, ListRelation &rl, ListChild &cl);
void subMenu(ListParent &pl, ListRelation &rl, ListChild &cl);
void InputView(ListParent &pl, ListRelation &rl, ListChild &cl,int menu);
void IngToInd(ListParent &pl,ListRelation &rl,ListChild &cl,string kata);
void IndoToIng(ListParent &parentList, ListRelation &relationList, ListChild &childList, string kata);
void addNew(ListParent &pl,ListRelation &rl,ListChild &cl,string kata,int type);
void addNew(ListRelation &rl,ListChild &cl,adrParent parent);
void addNew(ListRelation &rl,ListParent &pl,adrChild child);
void backToHome(ListParent &pl, ListRelation &rl, ListChild &cl);
#endif // VIEW_H_INCLUDED
