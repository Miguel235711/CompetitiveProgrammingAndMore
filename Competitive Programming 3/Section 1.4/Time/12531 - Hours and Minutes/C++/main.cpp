#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int angleI;
    while(cin>>angleI){
        cout << (angleI%6?"N":"Y") << "\n";
    }
    return 0;
}