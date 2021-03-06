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
#ifdef _WIN32
    std::system("cls");
#elif  __linux__
    // Assume POSIX
    std::system ("clear");
#else

#endif
}

void PressToContinue()
{
#ifdef _WIN32
    system("pause");
#elif  __linux__
    // Assume POSIX
    system("read");
#else

#endif
}
