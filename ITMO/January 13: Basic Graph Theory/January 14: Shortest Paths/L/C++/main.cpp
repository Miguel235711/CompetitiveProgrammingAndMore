#include <bits/stdc++.h>

#define inf 1e12

using namespace std;

int movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}},n,m,grid[502][502];
int64_t d[502][502];
bool vis[502][502];

struct coord{
    int i,j;
    coord(int i,int j):i(i),j(j){}
    coord(){}
    bool operator<(coord other)const{
        return true;
    }
};

int64_t dijkstra(){
    priority_queue<pair<int64_t,coord>, vector<pair<int64_t,coord> >, greater<pair<int64_t,coord> > > q;
    q.push(make_pair(0,coord(1,1)));
    for(int i = 1 ; i <= n; i++)
        fill(d[i]+1,d[i]+m+1,inf);
    d[1][1]=0;
    while(1){
        auto e = q.top();
        q.pop();
        if(e.second.i == n && e.second.j == m)
            return e.first;
        if(!vis[e.second.i][e.second.j]){
            vis[e.second.i][e.second.j]=1;
            for(int mov = 0 ; mov < 4; mov ++){
                auto next = e;
                next.second.i += movs[mov][0], next.second.j += movs[mov][1];
                if(d[next.second.i][next.second.j]>d[e.second.i][e.second.j]+grid[next.second.i][next.second.j]){
                   d[next.second.i][next.second.j] = d[e.second.i][e.second.j]+grid[next.second.i][next.second.j];
                   next.first = d[next.second.i][next.second.j];
                   q.push(next);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ; 
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j ++)
            cin >> grid[i][j];
    cout << dijkstra() << "\n";
    return 0;
}