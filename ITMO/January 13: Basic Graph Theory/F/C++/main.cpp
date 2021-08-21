#include <bits/stdc++.h>
#define maxNodes 100008

using namespace std;

vector<int> graph[maxNodes];
int n,m,color=0;

int vis[maxNodes];

void dfs(int node){ ///how much can be visited
    vis[node]=color;
    for(int child: graph[node])
        if(!vis[child])
            dfs(child);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ; 
    int a,b;
    while(m--){
        cin >> a >> b ;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i ++){
        if(!vis[i])
            color++,dfs(i);
    }
    cout << color << "\n";
    for(int i = 1 ; i <= n ; i ++)
        cout << vis[i] << " ";
    cout << "\n";
    return 0;
}