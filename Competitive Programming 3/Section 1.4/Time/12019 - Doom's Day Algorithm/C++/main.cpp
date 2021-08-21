#include<bits/stdc++.h>

using namespace std;

int daysM[12]={
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};
string days[7]={
    "Monday",
    "Tuesday",
    "Wednesday", 
    "Thursday", 
    "Friday", 
    "Saturday", 
    "Sunday"
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ; 
    cin >> t;
    while(t--){
        int m,d;
        cin >> m >> d ;
        m--; 
        d+=4;
        for(int i = 0 ; i < 12 ; i ++){
            if(m==i){
                cout << days[d%7] << "\n";
                break;
            }else{
                d+=daysM[i];
            }
        }
    }
    return 0;
}