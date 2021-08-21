#include<bits/stdc++.h>

using namespace std;

double H,D;
double U,F;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>H>>U>>D>>F,H){
        double pos = 0 ; 
        F = U * F / 100;
        int day=0;
        for(; 0<=pos && pos <= H ;){
            day++;
            pos += max(0.0,U);
            if(pos>H)
                break;
            pos -= D ; 
            U -= F ; 
        }
        cout << (pos<0?"failure":"success") << " on day " << day << "\n";
    }
}