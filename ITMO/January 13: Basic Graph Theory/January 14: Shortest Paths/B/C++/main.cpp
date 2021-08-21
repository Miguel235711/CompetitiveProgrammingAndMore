#include <bits/stdc++.h>

using namespace std;

int minis[28][28],n,movs[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2}};
pair<int,int> start,ending;
pair<int,int> last[28][28];

bool insideLimits(pair<int,int> x){
    return x.first > 0 && x.first <= n && x.second > 0 && x.second <= n ; 
}

void f(){
    queue<pair<int,int> > q;
    q.push(start);
    minis[start.first][start.second]=1;
    while(!q.empty()){
        auto e = q.front();
        q.pop();
        for(int mov = 0 ; mov < 8 ; mov ++){
            auto next = e;
            next.first += movs[mov][0],next.second += movs[mov][1];
            if(insideLimits(next)&&!minis[next.first][next.second]){
                minis[next.first][next.second] = 1;
                last[next.first][next.second] = e;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> start.first >> start.second >> ending.first >> ending.second;
    f();
    vector<pair<int,int> > ans;
    for(;ending.first!=start.first || ending.second!=start.second ; ending = last[ending.first][ending.second]){
        ans.push_back(ending);
    }
    cout << ans.size() + 1 << "\n";
    cout << start.first << " " << start.second << "\n";
    for(int i = ans.size()-1 ; i > - 1 ; i --)
        cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}