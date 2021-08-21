#include<bits/stdc++.h>
 
using namespace std;
 
int64_t ms[12];
int m;
map<int64_t,bool> memo;
map<int64_t,bool> divi;

bool f(int64_t x){ /// 0 loses, 1 wins
    auto it = memo.find(x);
    if(it!=memo.end())
        return it->second;
    bool wins = 0,divisible = 0;
    for(int i = 0 ; i < m ; i ++)
        if(x%ms[i]==0){
            divisible = 1;
            bool ans = f(x/ms[i]);
            if((ans&&!(ms[i]&1))||(!ans&&(ms[i]&1))||!divi[x/ms[i]])
                wins=1;
        }
    divi[x]=divisible;
    memo[x]=wins;
    return wins;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int64_t n;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++)
        cin >> ms[i];
    cout << (f(n) ? "First" : "Second") << "\n"; 
    return 0;
}