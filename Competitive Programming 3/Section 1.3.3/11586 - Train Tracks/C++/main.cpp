#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cases;
    cin >> cases;
    cin.ignore();
    string line;
    while(cases--){
        getline(cin,line);
        int FFs=0,MMs=0,amount=0;
        istringstream iss(line);
        for(;iss>>line;amount++){
            if(line=="FF"){
                FFs++;
            }else if(line=="MM"){
                MMs++;
            }
        }
        cout << (amount==1||abs(FFs-MMs)>0?"NO LOOP":"LOOP") << "\n";
    }
    return 0;
}