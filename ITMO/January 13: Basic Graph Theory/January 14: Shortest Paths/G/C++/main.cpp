#include<bits/stdc++.h>
#define inf 5e15
#define linf 2e15

#define maxNodes 2008
 
using namespace std;
 
int64_t d[maxNodes],wi;
bool disq[maxNodes];
int n,m,s,ai,bi;
vector<pair<int,int64_t> > graph[maxNodes];
 
void disqualify(int x){
    disq[x]=true;
    for(auto child: graph[x])
        if(!disq[child.first])
            disqualify(child.first);
}

bool vis[maxNodes];
map<pair<int,int>,int> edV;
void f(int i){
    vis[i]=true;
    for(auto to:graph[i])
        if(!vis[to.first])
            f(to.first);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> s;
    while(m--){
        cin >> ai >> bi >> wi;
        if(ai==bi&&wi<0)
            disq[ai]=true;
        auto pAB = make_pair(ai,bi);
        auto it = edV.find(pAB);
        if(it==edV.end())
            graph[ai].push_back(make_pair(bi,wi)),edV[pAB]=graph[ai].size()-1;
        else if(graph[ai][it->second].second>wi)
            graph[ai][it->second].second=wi;
    }
    fill(d,d+n+1,inf);
    //bellman-ford
    d[s] = 0;
    bool flag = true;
    for(int it = max(n,m);flag&&it;it--){
        flag = false;
        for(int i = 1 ; i <= n ; i ++)
            for(auto child: graph[i])
                if(d[child.first]>d[i]+child.second)
                    d[child.first] = d[i]+child.second,flag = true;
    }
    for(int i = 1 ; i <= n ; i ++)
        for(auto child: graph[i])
            if(d[child.first]>d[i]+child.second&&!disq[child.first])
                disqualify(child.first);
    f(s);
    for(int i = 1 ; i <= n ; i ++)
        cout << (!vis[i] ? "*" : (disq[i]?"-":to_string(d[i]))) << "\n";
    return 0;
}