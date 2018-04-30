#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include "mainHeader.h"
#include "tools.h"
#include "CircularDoubleLinkList.h"
#include "SingleLinkList.h"
#include "DoubleLinkList.h"

void mainView(ListParent pl, ListRelation rl, ListChild cl);
void InputView(ListParent pl, ListRelation rl, ListChild cl,int menu);
void IngToInd(ListParent lp,ListRelation lr,ListChild lc,string kata);

void addNew(ListParent &pl,ListRelation &rl,ListChild &cl,string kata,int type);
void addNew(ListRelation &rl,ListChild &cl,adrParent parent);
void addNew(ListRelation &rl,ListParent &pl,adrChild child);
#endif // VIEW_H_INCLUDED
