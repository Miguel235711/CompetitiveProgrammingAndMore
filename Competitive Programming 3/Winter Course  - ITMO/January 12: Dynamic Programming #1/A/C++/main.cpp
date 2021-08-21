#include<bits/stdc++.h>

using namespace std;

int memo[102],c[102],n;

int f(int i){
    if(i>n)
        return INT_MIN;
    if(i==n)
        return c[i];
    if(memo[i]!=INT_MIN)
        return memo[i];
    return memo[i] = max(f(i+1),f(i+2))+c[i];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n ;
    memo[0]=INT_MIN;
    for(int i = 1 ; i <= n ; i ++)
        cin >> c[i] , memo[i]=INT_MIN;
    cout << f(0) << "\n";
    return 0;
}