#include <bits/stdc++.h>

#define inf 1e9
#define maxNodes 308

using namespace std;

vector<pair<int,int> > graph[308];
int n,d[maxNodes];
pair<int,int> last[maxNodes]; ///first -> parent node, position in graph[node]
bool vis[maxNodes];

int dijkstra(bool withLast){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    fill(d+1,d+n+1,inf);
    memset(vis,0,sizeof(vis));
    d[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        //cout << "node in dijkstra: " << e.second << "\n";
        if(!vis[e.second]){
            vis[e.second]=1;
            int i = 0 ;
            for(auto child: graph[e.second]){
                if(d[child.first]>d[e.second]+child.second){
                    d[child.first]=d[e.second]+child.second,q.push(make_pair(d[child.first],child.first));
                    if(withLast)
                        last[child.first] = make_pair(e.second,i);
                }
                i++;
            }
        }
    }
    return d[n];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,u,v,l;
    cin >> n >> m; 
    while(m--){
        cin >> u >> v >> l;
        graph[u].push_back(make_pair(v,l)),graph[v].push_back(make_pair(u,l));      
    }
    ///calculate minimum path with dijkstra
    int orig = dijkstra(1), maximized = orig;
    //cout << "orig: " << orig << "\n";
    ///make a dijkstra for each duplicated edge of minimum path
    //cout << "last[n].first: " << last[n].first << " last[n].second: " << last[n].second << "\n";
    for(auto current = last[n]; current.first ; current = last[current.first]){
        //cout << "node: " << current.first << " index in graph: " << current.second << "\n";
        graph[current.first][current.second].second<<=1;
        maximized = max(maximized,dijkstra(0));
        graph[current.first][current.second].second>>=1;
    }
    cout << maximized - orig << "\n";
    return 0;
}