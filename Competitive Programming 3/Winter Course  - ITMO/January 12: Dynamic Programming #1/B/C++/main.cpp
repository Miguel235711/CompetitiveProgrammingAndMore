#include<bits/stdc++.h>

using namespace std;

int memo[32];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin >> n >> k ;
    memo[n]=1; 
    for(int i = n - 1 ; i ; i --){
        int limK = min(k,n-i)+1;
        for(int j = 1 ; j < limK ; j ++)
            memo[i] += memo[j+i];
    }
    cout << memo[1] << "\n";
    return 0;
}