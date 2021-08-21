#include <bits/stdc++.h>
#define inf 2e9
 
using namespace std;
 
int n,s,memo[10008][108];
vector<pair<int,int> > graph[10008];
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,k,ai,bi,wi;
    cin >> n >> m >> k >> s;
    while(m--){
        cin >> ai >> bi >> wi;
        graph[bi].push_back(make_pair(ai,wi));
    }
    for(int i = 1 ; i <= n ; i ++)
        memo[i][0] = inf;
    memo[s][0] = 0;
    for(int i = 1 ; i <= k ; i ++)
        for(int j = 1 ; j <= n ; j ++){
            memo[j][i]=inf;
            for(auto child: graph[j])
                memo[j][i] = min(memo[j][i], memo[child.first][i-1]+child.second);
        }
    for(int i = 1 ; i <= n ; i ++)
        cout << (memo[i][k] == inf ? -1 : memo[i][k]) << "\n";
    return 0;
}