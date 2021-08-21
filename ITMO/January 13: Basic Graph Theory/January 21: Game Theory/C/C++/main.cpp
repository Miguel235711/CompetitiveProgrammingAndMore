#include<bits/stdc++.h>
#define maxL 100008

using namespace std;

int n,m,s,a,b;
vector<int> graph[maxL];
int winner[maxL][3]; /// 1 , 2 -> 0 if not visited yet

int invert(int x){
    return x == 2 ? 1 : 2;
}

int dfs(int i,int player){
    if(winner[i][player])
        return winner[i][player];
    int otP = invert(player);
    winner[i][player]=otP;
    for(int to: graph[i]){
        int nWinner = dfs(to,otP);
        if(nWinner==player)
            winner[i][player]=player;
    }
    return winner[i][player];
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> s;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    cout << (dfs(s,1)==2 ? "Second":"First") << " player wins\n";
    return 0;
}