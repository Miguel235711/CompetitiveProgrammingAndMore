#include<bits/stdc++.h>

using namespace std;

int memo[1008][1008];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n , m ; 
    cin >> n >> m;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            cin >> memo[i][j];
    for(int i = n ; i > -1 ; i --)
        for(int j = m ; j > -1 ; j --)
            if(i+1 != n || j+1!=m)
                memo[i][j]+= min(i+1 == n ? INT_MAX : memo[i+1][j],j+1 == m ? INT_MAX : memo[i][j+1]);
    cout << memo[0][0] << "\n";
    return 0;
}