#include<bits/stdc++.h>
#define lim 100008

using namespace std;

int type[lim];
vector<int> graph[lim];
map<int,int>typesOcurrences;

int mostRepeated = -1,dest ;

void f(int node,int parent,int length){
    if(node==dest){
        for(auto it = typesOcurrences.begin(); it!=typesOcurrences.end();it++){
            if(it->second>length/2)
                mostRepeated=it->first;
        }
        return;
    }
    for(int son:graph[node])
        if(son!=parent){
            typesOcurrences[type[son]]++;
            f(son,node,length+1);
            typesOcurrences[type[son]]--;
        }
}

int query(int a,int b){
    mostRepeated = -1, dest=b;
    typesOcurrences[type[a]]++;
    f(a,a,1);
    typesOcurrences.clear();
    return mostRepeated;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,a,b;
    cin >> N ; 
    for(int i = 1 ; i <= N ; i ++ )
        cin >> type[i];
    for(int i = 1 ; i < N ; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int Q,qType;
    cin >> Q;
    while(Q--){
        cin >> qType >> a >> b;
        if(qType==2)
            type[a]=b;
        else
            cout << query(a,b) << "\n";
    }
    return 0;
}