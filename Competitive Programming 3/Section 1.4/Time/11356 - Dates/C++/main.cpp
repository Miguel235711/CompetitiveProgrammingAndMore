#include<bits/stdc++.h>

#define mp make_pair

using namespace std;

int daysM[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string,int> month={
    mp("January",1),
    mp("February",2), 
    mp("March",3), 
    mp("April",4), 
    mp("May",5),
    mp("June",6),
    mp("July",7),
    mp("August",8),
    mp("September",9),
    mp("October",10),
    mp("November",11),
    mp("December",12)
};
string months[12]={
    "January",
    "February", 
    "March", 
    "April", 
    "May", 
    "June",
    "July", 
    "August",
    "September",
    "October",
    "November",
    "December"
};
bool leap(int y){
    return y%4==0 && (y%100!=0||y%400==0); 
}
int getDaysM(int m,int y){
    return leap(y) && m == 2 ? 29 : daysM[m-1];
}

int getRemainYearDays(int d,int m,int y){
    int daysT = 0;
    for(;m<13;m++){
        int days = getDaysM(m,y);
        daysT += days-d+1;
        d=1;
    }
    return daysT;
}
//1,1,y
void jumpYears(int & d,int &y,int & remainD){
    while(1){
        int days = leap(y)? 366:365;
        if(remainD>=days-d+1){
            //cout << "enteredYearn";
            remainD-=days-d+1,y++;
            d=1;
        }else
            return;
    }
}

//1,m,fixedY
void jumpMonths(int & d,int &m,int & remainD,int y){
    while(1){
        int days = getDaysM(m,y);
        //cout << "days: " << days << "\n";
        if(remainD>=days-d+1){
            //cout << "enteredDays\n";
            remainD-=days-d+1,m++;
            d=1;
        }else
            return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /*vector<int>tests={1900,1904,1908,1996,2000,2100};
    for(int y : tests){
        cout << leap(y) << "\n";
    }*/
    int t,remainDays,d,m,y;
    cin >> t; 
    for(int cs = 1 ; cs <= t ; cs++){
        string monthS;
        char g;
        cin >> y,cin>>g,cin>>monthS;
        d=stoi(monthS.substr(monthS.size()-2,2));
        monthS=monthS.substr(0,monthS.size()-3);
        m = month[monthS];
        cin >> remainDays;
        int remainDaysYear = getRemainYearDays(d,m,y);
        //cout << "remainDaysYear: " << remainDaysYear << "\n";
        if(remainDays>=remainDaysYear){
            //cout << "enteredToBegNextYear:\n";
            remainDays-=remainDaysYear,y++,m=1,d=1;
        }
        jumpYears(d,y,remainDays);
        //cout << "remainDays: " << remainDays << "d: " << d << "\n";
        jumpMonths(d,m,remainDays,y);
        printf("Case %d: %d-%s-%02d\n",cs,y,months[m-1].c_str(),d+remainDays);
    }
    return 0;
}