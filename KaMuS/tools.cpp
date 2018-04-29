#include "tools.h"

int CurrentTimestamp(){
    time_t now = time(0);
    return now;
}
void ShowFromTimestamp(long timestamp){
    time_t time = timestamp / 1000;
    cout<<ctime(time)<<endl;
}
void ShowCurrentTime(){
   time_t now = time(0);
   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << ltm->tm_mday << " ";
   cout << 1 + ltm->tm_mon<< " ";
   cout << 1900 + ltm->tm_year << " , ";
   cout << ltm->tm_hour << ":";
   cout << 1 + ltm->tm_min << ":";
   cout << 1 + ltm->tm_sec ;
}

void clrscr(){
    cout << "\033[2J\033[1;1H";
}

//Debugger For check Link List
void DebuggerRelation(){
    ListRelation L;

    cout << endl;

    cout << endl;
    cout << "Cheking . . . " << "Create List : ";
    createList(L);
    if(first(L) == NULL) cout << "Success";
    else cout << "Failed";

    cout << endl;
    cout << "Cheking . . . " << "alokasi : " << endl;
    adrChild child = alokasi("test");
    adrParent parent = alokasi("tes");
    adrRelation P = alokasi(parent,child);
    cout << "create element : ";
    if(P != NULL) cout << "Success";
    else cout << "Failed";
    cout << "info : ";
    if(info(P). != ) cout << "Success";
    else cout << "Failed";

}

void DebuggerChild(){

}

void DebuggerParent(){

}
