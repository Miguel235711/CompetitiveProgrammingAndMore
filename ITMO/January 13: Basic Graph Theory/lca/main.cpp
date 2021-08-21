#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
vector<int> depth;
vector<vector<int> > binup;
int bp;

void dfs(int v,int d,int p){///dfs to calculate depth and binup for lca
    depth[v] = d;
    binup[v][0]=p;
    for(int i = 1 ; i < bp; ++i)
        binup[v][i] = binup[binup[v][i-1]][i-1];
    for(int to: graph[v])
        if(to!=p)
            dfs(to,d+1,v);
}

int lca(int a,int b){
    if(depth[a]>depth[b])
        swap(a,b);
    // depth[a]<=depth[b]
    // wanto to find q: q is ancestor of b and depth[q] == depth[a]
    for(int k = bp - 1; k > -1 ; --k)
        if(depth[b]-(1<<k)>=depth[a])
            b = binup[b][k];
    //depth[u] == depth[v]
    if(a==b) ///special case
        return a;
    for(int k = bp - 1; k > -1 ; --k)
        if(binup[a][k]!=binup[b][k])
            a = binup[a][k], b=binup[b][k];
    return binup[a][0];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,a,b;
    cin >> n;
    graph.resize(n);
    depth.resize(n);
    bp = log2(n);
    binup = vector<vector<int> >(n,vector<int>(bp));
    for(int i = 1 ; i < n ; i ++){
        cin >> a >> b;
        --a,--b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return 0;
}