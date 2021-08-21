#include<bits/stdc++.h>
#define maxL 300008

using namespace std;

  
int n,m,a,b;

string toAns[3]={"DRAW","SECOND","FIRST"};
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int cs = 0;cin >> n >> m;cs++){
        queue<int> toPro;
        vector<vector<int> >graph(n+1);
        vector<int> vis(n+1), outDeg(n+1);// 1 loser , 2 winner, 0 not visited yet
        while(m--)
            cin >> a >> b, graph[b].push_back(a),outDeg[a]++;
        for(int i = 1 ; i <= n; i++ )
            if(!outDeg[i])
                toPro.push(i), vis[i]=1;
        while(!toPro.empty()){
            int u = toPro.front();
            toPro.pop();
            if(vis[u]==1){//loser
                for(int to : graph[u])
                    if(!vis[to])
                        vis[to]=2,toPro.push(to);
            }else if(vis[u]==2){ // winner
                for(int to: graph[u]){
                    //cout << "u: " << u << " to: " << to << " outDeg[to]: " << outDeg[to] << "\n";
                    outDeg[to]--;
                    if(!outDeg[to])
                        vis[to]=1,toPro.push(to);
                }
            }
        }
        if(cs)
            cout << "\n";
        for(int i = 1; i <= n ; i ++)
            cout << toAns[vis[i]] << "\n";
    }
    return 0;
}