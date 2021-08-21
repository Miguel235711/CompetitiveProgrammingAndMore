#include<bits/stdc++.h>

using namespace std;

vector<string> subs;

bool valid(int x){
    string xS = to_string(x);
    for(string sub : subs){
        int lim = xS.size()-sub.size()+1;
        for(int i = 0; i < lim; i++)
            if(xS.substr(i,sub.size())==sub)
                return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,n;
    cin >> m;
    
    string s;
    for(int i = 0 ; i < m ; i ++){
        cin >> s;
        subs.push_back(s);
    }
    cin >> n ; 
    for(int i = 0,number = 1 ; ;number++ ){
        if(valid(number)){
            i++;
            if(i==n){
                cout << number << "\n";
                return 0 ;
            }
        }
    }
    return 0;
}