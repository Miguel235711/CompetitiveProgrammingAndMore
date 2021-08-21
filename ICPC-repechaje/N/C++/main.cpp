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


typedef pair<string,string> pss;
typedef vector<string> vs;
typedef vector<pss> vss;

typedef pair<int,string> pis;
typedef vector<pis> vis;
typedef pair<string,int> psi;
typedef vector<psi> vsi;

typedef map<string,string> mss;
typedef map<int,string> mis;
typedef map<string,int> msi;

int allVisited;

bool calced[102][102][2052],memo[102][102][2052];
int ps[18],fs[18];
vector<pair<int,int> > graph[102];

bool f(int i,int F,int vis){
    if(i==1 && vis==allVisited)
        return true;
    if(calced[i][F][vis])
        return memo[i][F][vis];
    bool ans = false;
    for(auto c: graph[i]){
        bool newVis = if()
        if(F>=c.second)
            ans |= memo[c.first][F][vis];
    }
    calced[i][F][vis]=true;
    return memo[i][F][vis] = ans;
}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M,K,F,a,b,c;
    cin >> N >> M >> K >> F;
    for(int i = 0 ; i < M ; i ++){
        cin >> a >> b >> c ; 
        graph[a].push_back(make_pair(b,c));
    }
    for(int i = 0 ; i < K ; i ++)
        cin >> ps[i] >> fs[i];
    allVisited = (1 << K) -1;
    for(int i = 0 ; i < F ; i ++){
        if(f(1,i,0)){
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}