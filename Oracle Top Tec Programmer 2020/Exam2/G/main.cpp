#include<bits/stdc++.h>

using namespace std;

int blueberries[1002],memo[1002][1002],n,k;

int f(int i,int acum){
    if(i>n){
        return acum;
    }
    if(memo[i][acum]!=-1){
        return memo[i][acum];
    }
    return memo[i][acum]=max(blueberries[i]+acum<=k?f(i+2,acum+blueberries[i]):0,f(i+1,acum));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ; 
    cin >> t ; 
    for(int cs = 1 ; cs <= t ; cs ++ ){
        cin >> n >> k ; 
        for(int i = 1 ; i <= n ; i ++){
            cin >> blueberries[i];
        }
        memset(memo,-1,sizeof(memo));
        cout << "Scenario #" << cs << ": " << min(k,f(1,0))<<"\n";
    }
    return 0;
}