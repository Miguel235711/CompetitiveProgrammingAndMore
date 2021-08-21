#include <bits/stdc++.h>
#define maxLength 1000002

using namespace std ; 

struct date{
    int day,month,year;
    bool operator<(date other)const{
        return month == other.month ? (day==other.day?year>other.year:day<other.day) : month < other.month ;  
    }
}birthdays[maxLength];
int n ; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    for(int i = 0 ; i < n ; i ++){
        cin >> birthdays[i].day >> birthdays[i].month >> birthdays[i].year;
    }
    sort(birthdays,birthdays+n);
    for(int i = 0 ; i < n ; i ++){
        cout << birthdays[i].day << " " << birthdays[i].month << " " << birthdays[i].year << "\n";
    }
    return 0 ; 
}