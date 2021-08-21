#include <bits/stdc++.h>
#define inf 3e8
#define maxNodes 30008

using namespace std;

int n,m;
vector<pair<int,int> > graph[maxNodes];
bool vis[maxNodes];
int d[maxNodes];

void dijkstra(){
    for(int i = 1 ; i <= n ; i ++)
        d[i] = inf;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0,1));
    d[1]=0;
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        if(!vis[e.second]){
            ///extend
            vis[e.second]=true;
            for(auto child: graph[e.second]){
                if(e.first+child.second < d[child.first])
                    d[child.first] = e.first+child.second, q.push(make_pair(d[child.first],child.first));
            }
        }
    } 
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    int a,b,xi;
    while(m--){
        cin >> a >> b >> xi;
        graph[a].push_back(make_pair(b,xi));
        graph[b].push_back(make_pair(a,xi));
    }
    dijkstra();
    for(int i = 1 ; i <= n ; i ++)
        cout << d[i] << " ";
    cout << "\n";
    return 0;
}