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

const int lim = 100008, inf = 1e9+1;

int n,m,ai,bi,wi;
vii graph[lim];
int cost[lim];
bool v[lim];

void dijkstra(){
    cost[1]=0;
    fill(cost+2,cost+n+1,inf);
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(mp(0,1));
    while(!q.empty()){
        auto t = q.top();
        //cout << "t.fi: " << t.fi << " t.se: " << t.se << "\n";
        q.pop();
        if(!v[t.se]){
            v[t.se]=1;
            for(auto cc: graph[t.se]){
                for(auto c:graph[cc.fi]){
                    int newCost = pow(cc.se+c.se,2) + t.fi;
                    //cout << "from: " << t.se << " to: " << c.fi << "\n" << "cost: " << c.se+t.fi << "beforeCost: " << cost[c.fi] << "v[c.fi]: " << v[c.fi] << "\n";
                    if(!v[c.fi]&&newCost<cost[c.fi])
                        cost[c.fi]=newCost,q.push(mp(newCost,c.fi));
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; i ++)
        cout << (cost[i] == inf ? -1 : cost[i]) << " ";
    cout << "\n";  
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    while(m--){
        cin>>ai>>bi>>wi;
        graph[ai].push_back(mp(bi,wi));
        graph[bi].push_back(mp(ai,wi));
    }
    dijkstra();
    return 0;
}