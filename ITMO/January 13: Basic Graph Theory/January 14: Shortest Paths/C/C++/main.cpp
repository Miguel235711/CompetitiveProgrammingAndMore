#include <bits/stdc++.h>

using namespace std;

int start,ending;

int last[10000];
queue<int> q;

void manage(int e,int previous){
    //cout << "previous: " << previous << " next: " << e << "\n";
    if(!last[e]){
        q.push(e);
        last[e] = previous;
    }
}

void f(){
    q.push(start);
    last[start] = 1;
    while(!q.empty()){
        auto e = q.front();
        q.pop();
        if(e<9000){
            ///+1 to 1° digit
            auto next = e + 1000;
            manage(next,e);
        }
        if(e%10>1){
            ///-1 to 4° digit
            manage(e-1,e);
        }
        //right shift
        manage(e / 10 + 1000*(e%10),e);
        //left shift
        manage(e/1000 + e%1000 * 10,e);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> start >> ending;
    f();
    vector<int>ans;
    for(;ending!=1;ending = last[ending]){
        ans.push_back(ending);
    }
    for(int i = ans.size()-1 ; i > -1 ; i --)
        cout << ans[i] << "\n";
    return 0;
}