#include<bits/stdc++.h>

using namespace std ; 

string s ;
int aS;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s ; 
    for(char x : s){
        if(x=='a'){
            aS++;
        }
    }
    cout << min((int)s.size(),aS+aS-1) << "\n";
    return 0;
}