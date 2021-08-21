#include<bits/stdc++.h>
#define inf 2000

using namespace std;

string a,b;
int n,m;
int memo[1008][1008];

int f(int i , int j){
    if(i==n&&j==m) //done
        return 0;
    if(i==n || j == m)
        return max(n-i,m-j); 
    if(memo[i][j]!=-1)
        return memo[i][j];
    return memo[i][j] = 
        //replace, not doing anything
        min(
            f(i+1,j+1) + (a[i] != b[j]),
        ///insert/delete
            min(
                f(i+1,j) + 1,
                f(i,j+1) + 1
            )
        );
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b ;
    n = a.size(), m = b.size();
    memset(memo,-1,sizeof(memo));
    cout << f(0,0) << "\n";
    return 0;
}