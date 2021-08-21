#include<bits/stdc++.h>
#define length 2002

using namespace std ; 

int colorVis[length],n,m,colorGlobal=1; //paint with t + 1
bool colorType[length];
vector<int> graph[length]; 

void dfs(int node,bool color){
    colorType[node]=color;
    for(int child: graph[node]){
        if(colorVis[child]!=colorGlobal){
            colorVis[child]=colorGlobal;
            dfs(child,!color);
        }
    }
}

bool valid(){
    for(int i = 1 ; i <= n ; i ++ ){
        for(int child: graph[i]){
            if(colorType[child]==colorType[i]){
                return false;
            }
        }
    }
    return true;
}

void init(){
    for(int i = 1 ; i <= n ; i ++){
        graph[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,a,b;
    cin >> t ;
    for(;colorGlobal<=t;colorGlobal++){
        cin >> n >> m ; 
        while(m--){
            cin >> a >> b ; 
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 1 ; i <= n ; i ++ ){
            if(colorVis[i]!=colorGlobal){
                colorVis[i]=colorGlobal;
                dfs(i,0);
            }
        }
        cout << "Scenario #"<<colorGlobal<<":\n";
        if(valid()){
            cout << "No suspicious bugs found!";
        }else{
            cout << "Suspicious bugs found!";
        }
        cout << "\n";
        init();
    }
    return 0;
}