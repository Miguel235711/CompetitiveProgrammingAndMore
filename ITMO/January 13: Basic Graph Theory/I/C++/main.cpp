#include <bits/stdc++.h>
 
#define maxNodes 10008
 
using namespace std;
 
int n,m,a,b,color=0;
int vis[maxNodes],vis2[maxNodes];
vector<int> graph[maxNodes],rGraph[maxNodes], topoAns;
set<pair<int,int> > visitedSCC;
 
 
void f(int node){
    vis[node]=1;
    //cout << "node: " << node << "\n";
    for(int child: graph[node])
        if(vis[child]==0)
            f(child);
    topoAns.push_back(node);
}
 
void g(int node){
    vis2[node] = color;
    //cout << "g():: node: " << node << "\n";
    //if(node==2)
     //   cout << "what: " << rGraph[node][0] << "\n";
    for(int child: rGraph[node])
        if(vis2[child]==0)
            g(child);
        else if(vis2[child]!=color&&visitedSCC.find(make_pair(color,vis2[child]))==visitedSCC.end())
            //cout << "color: " << color << " vis2[child]: " << vis2[child] << " node:  " << node << " child: " << child << "\n";
            visitedSCC.insert(make_pair(color,vis2[child]));
}           
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
        rGraph[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i ++){
        if(!vis[i]){
            f(i);
        }
    }
    //cout << "graph[2][0]: " << rGraph[2][0] << "graph[2][1]: " << rGraph[2][1] << "\n";
    for(int i = topoAns.size() - 1 ; i > -1 ; i --){
        //cout << "topoAns[i]: " << topoAns[i] << "\n";
        if(!vis2[topoAns[i]]){
            //cout << "going to start: " << topoAns[i] << "\n";
            color++,g(topoAns[i]);
            //cout << "colors: ";
            /*for(int  j = 1 ; j <= n ; j ++)
                cout << vis2[j] << " ";
            cout << "\n";*/
        }
    }
    cout << visitedSCC.size() << "\n";
    return 0;
}