#include <bits/stdc++.h>
#define inf 2e13


using namespace std;

int n,start,finish;
vector<pair<int64_t,int> > graph[2008];
bool vis[2008];
int64_t d[2008];

void dijkstra(){
    for(int i = 1 ; i <= n ; i ++)
        d[i] = inf;
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,start));
    d[start]=0;
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        if(!vis[e.second]){
            ///extend
            for(auto child: graph[e.second]){
                if(e.first+child.second < d[child.first])
                    d[child.first] = e.first+child.second, q.push(make_pair(d[child.first],child.first));
            }
        }
    } 
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> start >> finish;
    int xi;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            cin >> xi;
            if(xi!=-1)
                graph[i].push_back(make_pair(j,xi));
        }
    }
    dijkstra();
    cout << ( d[finish] == inf ? -1 : d[finish]) << "\n";
    return 0;
}