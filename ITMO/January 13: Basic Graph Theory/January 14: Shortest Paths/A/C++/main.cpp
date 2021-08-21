#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1008];
int d[1008];

int n,x; 

void f(){
    queue<int> q;
    d[x]=1;
    q.push(x);
    while(!q.empty()){
        auto e = q.front();
        q.pop();
        //cout << "e: " << e << "\n";
        //cout << "graph[e].size(): " << graph[e].size() << "\n";
        for(auto child: graph[e])
            if(!d[child])
                d[child] = d[e] + 1, q.push(child);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> x ;
    int xi;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            cin >> xi ; 
            if(xi)
                graph[i].push_back(j);
        }
    }
    f();
    for(int i = 1 ; i <= n ; i ++)
        cout << d[i] - 1 << " ";
    cout << "\n";
    return 0;
}