#include<bits/stdc++.h>

const char * weekday[] = { 
    "Sunday", "Monday","Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"
};

using namespace std ; 

int main ()
{
  ios_base::sync_with_stdio(0);//cin.tie(0);
  time_t rawtime;
  struct tm * timeinfo;
  int year, month ,day;
  
  /* prompt user for date */
  cout << "Enter year: " ;
  cin >> year ;
  cout << "Enter month: "; 
  cin >> month;
  cout << "Enter day: "; 
  cin >> day;

  /* get current timeinfo and modify it to the user's choice */
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;

  /* call mktime: timeinfo->tm_wday will be set */
  mktime ( timeinfo );

  cout << "That day is a " <<  weekday[timeinfo->tm_wday] << "\n";
  return 0;
}