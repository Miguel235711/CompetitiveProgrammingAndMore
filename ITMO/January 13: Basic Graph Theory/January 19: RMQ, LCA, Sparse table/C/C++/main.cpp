#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<int> depth;
vector<vector<int> > binup;
vector<vector<int> > mini;
int bp;

void dfs(int v,int d,int p){///dfs to calculate depth and binup for lca
    depth[v] = d;
    for(int i = 1 ; i <= bp; ++i)
        binup[v][i] = binup[binup[v][i-1]][i-1],mini[v][i] =  min(mini[binup[v][i-1]][i-1],mini[v][i-1]);
    for(int to: graph[v])
        if(to!=p)
            dfs(to,d+1,v);
}

int lca(int a,int b){
    if(depth[a]>depth[b])
        swap(a,b);
    // depth[a]<=depth[b]
    // wanto to find q: q is ancestor of b and depth[q] == depth[a]
    int ans = INT_MAX;
    for(int k = bp; k > -1 ; --k)
        if(depth[binup[b][k]]>=depth[a])
            ans = min(ans,mini[b][k]),b = binup[b][k];
    //depth[u] == depth[v]
    if(a==b) ///special case
        return ans;
    for(int k = bp; k > -1 ; --k)
        if(binup[a][k]!=binup[b][k])
            ans = min(ans,mini[a][k]),ans=min(ans,mini[b][k]),a = binup[a][k], b=binup[b][k];
    return min(ans,min(mini[a][0],mini[b][0]));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,x,y,m;
    cin >> n;
    graph.resize(n);
    depth.resize(n);
    bp = log2(n);
    binup = vector<vector<int> >(n,vector<int>(bp+1));
    mini = vector<vector<int> >(n,vector<int>(bp+1));
    mini[0][0]=INT_MAX;
    for(int i = 1 ; i < n ; i ++){
        cin >> x>> y; /// y is cost
        --x;
        graph[i].push_back(x);
        graph[x].push_back(i);
        binup[i][0]=x, mini[i][0]=y; 
    }
    dfs(0,0,0);
    cin >> m ;
    while(m--){
        cin >> x >> y;
        cout << lca(x-1,y-1) << "\n";
    }
    return 0;
}