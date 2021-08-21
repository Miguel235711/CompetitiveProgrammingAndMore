#include <bits/stdc++.h>

using namespace std;

vector<int> graph[108];
int n,ans=0,x;

bool vis[108];

int dfs(int node){ ///how much can be visited
    vis[node]=true;
    int ans = 1;
    for(int child: graph[node])
        if(!vis[child])
            ans+=dfs(child);
    return ans;
}

bool connected(){
    return dfs(0) == n; 
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cin>>x,ans+=x;
            if(x)
                graph[i].push_back(j);
        }
    }
    cout << (connected()&&ans/2+1==n ? "YES" : "NO") << "\n" ; 
    return 0;
}