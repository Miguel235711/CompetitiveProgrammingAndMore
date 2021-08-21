#include<bits/stdc++.h>
 
using namespace std;
 
vector<vector<pair<int,bool> > > graph; ///first is node, second is flag that stands for is real
vector<int> depth;
vector<vector<int> > binup;
vector<int> sum;
int bp;
 
void dfs(int v,int d,int p,int s){///dfs to calculate depth and binup for lca
    depth[v] = d;
    sum[v] = s;
    binup[v][0]=p;
    for(int i = 1 ; i <= bp; ++i)
        binup[v][i] = binup[binup[v][i-1]][i-1];
    for(auto to: graph[v])
        if(to.first!=p)
            dfs(to.first,d+1,v,s+(to.second?1:-1));
}
 
int lca(int a,int b){
    if(depth[a]>depth[b])
        swap(a,b);
    // depth[a]<=depth[b]
    // wanto to find q: q is ancestor of b and depth[q] == depth[a]
    for(int k = bp; k > -1 ; --k)
        if(depth[binup[b][k]]>=depth[a])
            b = binup[b][k];
    //depth[u] == depth[v]
    if(a==b) ///special case
        return a;
    for(int k = bp; k > -1 ; --k)
        if(binup[a][k]!=binup[b][k])
            a = binup[a][k], b=binup[b][k];
    return binup[a][0];
}

int depthDelta(int a,int lca){
    return depth[a]-depth[lca];
}

int lcaDepthDelta(int a,int lca){
    return sum[a]-sum[lca];
}

bool reachable(int a,int b){
    int lca_ab = lca(a,b);
    return depthDelta(a,lca_ab) == -lcaDepthDelta(a,lca_ab) 
    && depthDelta(b,lca_ab) == lcaDepthDelta(b,lca_ab);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,x,y,m;
    cin >> n;
    graph.resize(n);
    sum.resize(n);
    depth.resize(n);
    vector<bool> vis(n);
    bp = log2(n);
    binup = vector<vector<int> >(n,vector<int>(bp+1));
    for(int i = 1 ; i < n ; i ++){
        cin >> x >> y;
        --x,--y;
        vis[x]=1;
        graph[x].push_back(make_pair(y,true));
        graph[y].push_back(make_pair(x,false));
    }
    dfs(0,0,0,0);
    cin >> m ;
    while(m--){
        cin >> x >> y;
        --x,--y;
        cout << (reachable(x,y) ? "Yes" : "No") << "\n";
    }
    return 0;
}