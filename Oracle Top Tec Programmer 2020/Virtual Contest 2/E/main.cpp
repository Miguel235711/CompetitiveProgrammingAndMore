#include<bits/stdc++.h>

using namespace std ; 

bool isLucky(string x){
    for(char c : x ){
        if(c!='7' && c!='4'){
            return false;
        }
    }
    return true;
}

int n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    for(int i = 4 ; i <= n ; i ++){
        if(isLucky(to_string(i))&& n % i == 0){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}