#include<bits/stdc++.h>
#define mp make_pair

using namespace std;


bool isLeap(int y){
    return y %4 == 0 && (y%100!=0 || y%400==0);
}

map<string,int> monthN = {
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

bool leftTest(int m,bool leapYear){
    return leapYear && (m<2 || m==2);
}
bool rightTest(int m,int d,bool leapYear){
    return leapYear && (m>2 || (m==2&&d==29));
}

int leapAbs(int x){
    return x/4-x/100+x/400;
}

int leapRange(int b,int e){
    return leapAbs(e)-leapAbs(b-1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,d1,y1,m1,d2,y2,m2;
    cin >> n ;
    string monthS; 
    for(int cs = 1 ; cs <= n ; cs++){
        cin >> monthS;
        m1= monthN[monthS];
        cin >> d1>>monthS;
        cin >> y1;
        cin >> monthS;
        m2= monthN[monthS];
        cin >> d2>>monthS;
        cin >> y2;
        bool leapYear1 = isLeap(y1), leapYear2 = isLeap(y2);
        bool lT = leftTest(m1,leapYear1), rT = rightTest(m2,d2,leapYear2);
        int leapDays=0;
        if(y1==y2){
            if(lT&&rT)
                leapDays=1;
        }else{
            leapDays=(lT?1:0)+(rT?1:0)+leapRange(y1+1,y2-1);         
        }
        cout << "Case " << cs << ": " << leapDays << "\n";
    }
    return 0;
}