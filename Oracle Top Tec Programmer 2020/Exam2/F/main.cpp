#include<bits/stdc++.h>

#define lim 6102

using namespace std;

int memo[lim][lim];
string s;

int f(int i,int j){
    if(i>=j){
        return 0 ; 
    }
    if(s[i]==s[j]){
        return f(i+1,j-1);
    }
    if(memo[i][j]!=-1)
        return memo[i][j];
    return memo[i][j] = min(f(i+1,j),f(i,j-1))+1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ; 
    cin >> t ; 
    while(t--){
        cin >> s ; 
        memset(memo,-1,sizeof(memo));
        cout << f(0,s.size()-1) << "\n";
    }
    return 0;
}