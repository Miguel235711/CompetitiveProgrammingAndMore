#include<bits/stdc++.h>
#define maxL 100008

using namespace std;

int n,m,s,a,b,nimber[maxL];
vector<int> graph[maxL];
bool vis[maxL];

int dfs(int i){
    if(vis[i])
        return nimber[i];
    vis[i]=true;
    set<int> nums;
    for(int to: graph[i])
        nums.insert(dfs(to));
    for(;nums.find(nimber[i])!=nums.end();nimber[i]++);
    return nimber[i];
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 1 ; i <= n ; i ++)
        cout << dfs(i) << "\n";
    return 0;
}