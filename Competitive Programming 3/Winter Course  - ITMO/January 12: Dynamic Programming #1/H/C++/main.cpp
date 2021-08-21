#include<bits/stdc++.h>

using namespace std;

int n,memo[5008],times[5008][3];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < 3 ; j ++)
            cin >> times[i][j];
    for(int i = n - 1 ; i > -1 ; i --){
        int lim = min(n - i,3);
        memo[i] = INT_MAX;
        for(int j = 0 ; j < lim ; j++)
            memo[i] = min(memo[i+j+1]+times[i][j],memo[i]);
    }
    cout << memo[0] << "\n";
    return 0;
}