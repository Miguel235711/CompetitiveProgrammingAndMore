#include<bits/stdc++.h>
#define maxL 300008

using namespace std;

int depth[maxL],parent[maxL],nex[maxL],n,x;
void merge(int a,int b,int bestNex){
    if(depth[a]>depth[b])
        swap(a,b);
    ///depth[a]<=depth[b]
    parent[a]=b;
    if(depth[a]==depth[b])
        depth[b]++;
    nex[b]=bestNex;
}

int find(int x){
    if(x==parent[x])
        return x;
    return parent[x]=find(parent[x]);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
        depth[i]=1,parent[i]=i,nex[i]=i;
    for(int i = 0 ; i < n ; i ++){
        cin >> x;
        int a = find(x), b = find(nex[a]%n+1);
        cout << nex[a] << " ";
        merge(a,b,nex[b]);
    }
    cout << "\n";
    return 0;
}