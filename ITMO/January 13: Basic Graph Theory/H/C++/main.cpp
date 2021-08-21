#include <bits/stdc++.h>
#define maxNodes 100008

using namespace std;

int n,m,a,b,vis[maxNodes];
vector<int> graph[maxNodes], topoAns;
bool invalid = false;

//if cycles, -1

void f(int node){
    vis[node]=1;
    //cout << "node: " << node << "\n";
    for(int child: graph[node]){
        if(vis[child]==0)
            f(child);
        else if(vis[child]==1)
            //cout << "child: " << child << " what\n";
            ///cycle
            invalid = true;
    }
    topoAns.push_back(node);
    vis[node]=2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 1 ; i <= n ; i ++){
        if(vis[i]==0){
            f(i);
            if(invalid)
                break;
        }
    }
    if(invalid)
        cout << "-1";
    else{
        for(int i = topoAns.size()-1 ; i > -1 ; i --)
            cout << topoAns[i] << " ";
        
    }
    cout << "\n";
    return 0;
}