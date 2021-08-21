#include<bits/stdc++.h>
#define maxL 100008

using namespace std;

int depth[maxL],parent[maxL],n,m,qs[maxL];
int64_t ans[maxL],sum[maxL];
bool vis[maxL];

void merge(int a,int b){
    if(a==b)
        return;
    if(depth[a]>depth[b])
        swap(a,b);
    ///depth[a]<=depth[b]
    parent[a]=b;
    sum[b]+=sum[a];
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
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> sum[i],depth[i]=1,parent[i]=i;
    for(int i = 1 ; i <= n ; i ++)
        cin >> qs[i];
    for(int i = n ; i ; i --){
        int iRoot = find(qs[i]);
            /*for(int i = 1 ; i <= n ; i++)
                cout << "vis[i]: " << vis[i] << "\n";*/
            //cout << "to unify qs[i]: " << qs[i] << "\n";
        if(qs[i]>1 && vis[qs[i]-1]){
            merge(find(qs[i]-1),iRoot);
            iRoot = find(qs[i]);
        }
        if(qs[i] < n && vis[qs[i]+1])
            merge(iRoot,find(qs[i]+1));
        vis[qs[i]]=true;
        //cout << "qs[i]: " << qs[i] << " find(qs[i]): " << find(qs[i]) << "\n";
        ans[i-1] = max(sum[find(qs[i])],ans[i]);
    }
    for(int i = 1 ; i <= n ; i ++)
        cout << ans[i] << "\n";
    return 0;
}