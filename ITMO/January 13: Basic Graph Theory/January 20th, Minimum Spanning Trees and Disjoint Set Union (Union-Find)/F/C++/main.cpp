#include<bits/stdc++.h>
#define maxL 200008

using namespace std;

int depth[maxL],parent[maxL],n,m;
pair<int,pair<int,int> > edges[maxL];

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
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        depth[i]=1,parent[i]=i;
    for(int i = 1 ; i <= m ; i++)
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    sort(edges+1,edges+m+1);
    int ans = 0 ;
    for(int i = 1 ; i <= m ; i ++){
        if(edges[i].first!=edges[i-1].first){
            ///calculate which ones can be added
            for(int j = i ; j<=m&&edges[j].first==edges[i].first; j++){
                int a = find(edges[j].second.first), b = find(edges[j].second.second);
                if(a!=b)
                    ans++;
            }
        }
        int a = find(edges[i].second.first), b = find(edges[i].second.second);
        if(a!=b)
            ans--,merge(a,b);
    }
    cout << ans << "\n";
    return 0;
}