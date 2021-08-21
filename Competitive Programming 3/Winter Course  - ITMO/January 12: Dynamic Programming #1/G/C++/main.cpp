#include<bits/stdc++.h>

using namespace std;

int n;
string s;
string b = "abc";

int64_t memo[100008][3];

int64_t f(int i, int j){
    if(j==3)
        return 1;
    if(i==n)
        return 0;
    if(memo[i][j]!=-1)
        return memo[i][j];
    return memo[i][j] = (s[i] == b[j] ? f(i+1,j+1) : 0) + f(i+1,j);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> s , n = s.size();
    memset(memo,-1,sizeof(memo));
    cout << f(0,0) << "\n";
    return 0;
}