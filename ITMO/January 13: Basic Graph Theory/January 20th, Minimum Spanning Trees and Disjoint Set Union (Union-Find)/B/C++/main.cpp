#include<bits/stdc++.h>
#define maxNodes 50008
#define maxEdges 100008

using namespace std;

int depth[maxNodes],parent[maxNodes],n,m,k,a,b;
pair<bool,pair<int,int> > queries[150008];
vector<bool> ans;

void merge(int a,int b){
    if(depth[a]>depth[b])
        swap(a,b);
    ///depth[a]<=depth[b]
    parent[a]=b;
    if(depth[a]==depth[b])
        depth[b]++;
}

int find(int x){
    if(x==parent[x])
        return x;
    return parent[x]=find(parent[x]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i ++)
        depth[i]=1,parent[i]=i;
    for(int i = 0 ; i < m ; i++)
        cin >> a >> b;
    string q;
    for(int i = 0 ; i < k ; i ++)
        cin >> q >> queries[i].second.first >> queries[i].second.second, queries[i].first = q[0] == 'c';
    for(int i = k - 1; i > -1 ; i --){
        int a = find(queries[i].second.first), b = find(queries[i].second.second);
        if(queries[i].first){
            if(a!=b)
                merge(a,b);
        }else
            ans.push_back(a==b);
    }
    for(int i = ans.size()-1 ; i > -1 ; i --)
        cout << (ans[i]?"YES":"NO") << "\n";
    return 0;
}