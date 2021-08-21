#include<bits/stdc++.h>

#define mp make_pair 
#define pb push_back 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define SQR(x) ((LL)(x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v)) 
#define PERMUTE next_permutation
#define fi first 
#define se second

#define MOD 1000000009 //1E9+9

using namespace std;

typedef int64_t i64;

typedef pair<i64,i64> p64;
typedef vector<i64> v64;
typedef vector<p64>  v6464;
typedef vector < v64 > vv64;

typedef double dle;
typedef long double ldle;

typedef pair<int,int> pii; 
typedef vector<int> vi;
typedef vector< pii > vii;
typedef vector< vi > vvi;

int amounts[100008],n,xi;
priority_queue<pii> sides;
void add1(int xi){
    amounts[xi]++;
    sides.push(mp(amounts[xi],xi));
}
void remove1(int xi){
    amounts[xi]--;
    sides.push(mp(amounts[xi],xi));
}
vector<pii> getFirst3(){
    vector<pii> ans;
    for(;ans.size()<3&&!sides.empty();){
        if(amounts[sides.top().second]==sides.top().first&&(ans.empty()||sides.top().second!=ans.back().second))
            ans.push_back(sides.top());
        sides.pop();
    }
    return ans;
}
vector<int> def={4,2,2};

bool possible(int x,vector<pii> & planks){
    for(auto & c :  planks)
        if(c.first>=x){
            c.first-=x;
            return true;
        }
    return false;
}

void retur(vector<pii>&planks){
    for(auto p : planks)
        sides.push(p);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        cin >> xi;
        add1(xi);
    }   
    int q;
    cin >> q;
    char sign;
    while(q--){
        cin >> sign >> xi;
        if(sign=='+')
            add1(xi);
        else
            remove1(xi);
        auto first3 = getFirst3();
        //cout << "first 3:\n";
        auto copyFirst3 = first3;
        string ans="YES";
        for(auto x: def)
            if(!possible(x,copyFirst3)){
                ans="NO";
                break;
            }
        cout << ans << "\n";
        //for(auto x: first3)
        //    cout << x.first << " " << x.second << " | ";
        retur(first3);
    }
    return 0;
}