#include "tools.h"

int CurrentTimestamp(){
    time_t now = time(0);
    return now;
}
void ShowFromTimestamp(long timestamp){
    time_t time = timestamp;
    cout<<ctime(&time);
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

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

void PressToContinue()
{
#ifdef WINDOWS
    system("pause");
#else
    // Assume POSIX
    system("read");
#endif
}
