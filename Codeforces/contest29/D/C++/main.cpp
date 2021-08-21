#include<bits/stdc++.h>

using namespace std;

vector<set<int> > multiChildren(308,set<int>());
vector<int> graph[308];
vector<int> ans;
bool noPossible=false;
int leaves[308];
int k = 0,ki=0;

void getMulti(int node,int parent){
    for(int son:graph[node])
        if(son!=parent){
            getMulti(son,node);
            for(auto it : multiChildren[son])
                multiChildren[node].insert(it);
        }
    if(multiChildren[node].empty())
        k++;
    multiChildren[node].insert(node);
}

void f(int node,int parent){
    if(node==leaves[ki])
        ki++;
    ans.push_back(node);
    while(multiChildren[node].size()!=1&&!noPossible){
        auto it = multiChildren[node].find(leaves[ki]);
        if(it==multiChildren[node].end()){
            noPossible=true;
        }else{
            for(int son: graph[node]){
                if(multiChildren[son].find(leaves[ki])!=multiChildren[son].end()){
                    //substract
                    for(auto it: multiChildren[son])
                        multiChildren[node].erase(it);
                    f(son,node);
                    ans.push_back(node);
                    break;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,ai,bi;
    cin >> n;
    for(int i = 1 ; i < n ; i ++ ) {
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }
    getMulti(1,1);
    for(int i = 0 ; i < k ; i ++){
        cin >> leaves[i];
    }
    f(1,1);
    if(noPossible)
        cout << "-1";
    else
        for(int x: ans)
            cout << x << " ";
    cout << "\n";
    return 0;
}