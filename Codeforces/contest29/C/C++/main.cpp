#include<bits/stdc++.h>

using namespace std;

map<int,vector<int> >graph;

void transverse(int node){
    int parent = node;
    do{
        cout << node << " ";
        for(int son : graph[node])
            if(son!=parent){
                parent = node;
                node = son;
                break;
            }
    }while(graph[node].size()==2);
    cout << node << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,ai,bi;
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }
    for(auto it = graph.begin() ; it!= graph.end() ; it++){
        if(it->second.size()<2){
            transverse(it->first);
            break;
        }
    }
    return 0;
}