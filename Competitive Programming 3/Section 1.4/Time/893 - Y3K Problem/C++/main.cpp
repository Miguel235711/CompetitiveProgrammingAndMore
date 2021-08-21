#include<bits/stdc++.h>

using namespace std;

int daysM[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
    int remainDays,d,m,y;
    while(cin >> remainDays>>d>>m>>y,remainDays){
        int remainDaysYear = getRemainYearDays(d,m,y);
        //cout << "remainDaysYear: " << remainDaysYear << "\n";
        if(remainDays>=remainDaysYear){
            //cout << "enteredToBegNextYear:\n";
            remainDays-=remainDaysYear,y++,m=1,d=1;
        }
        jumpYears(d,y,remainDays);
        jumpMonths(d,m,remainDays,y);
        cout << d+remainDays << " " << m << " " << y << "\n";
    }
    return 0;
}