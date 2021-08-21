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

vector<int> graph[1008];
int v[1008];

int f(int no){
    if(v[no])
        return v[no];
    int mx = 0 ; 
    for(int c:graph[no])
        MAX(mx,f(c));
    return v[no] = mx+1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,r,a,b;
    cin >> t ;
    for(int cs = 1 ;t--;cs++){
        cin >> n >> r;
        while(r--){
            cin >> a >> b;
            graph[a].pb(b);
        }
        vii ans;
        for(int i = 0 ; i < n ; i ++){
            memset(v,0,sizeof(v));
            ans.pb({f(i),i});
            //cout << "ans: " << f(i) << "\n";
        }
        sort(ans.begin(),ans.end());
        for(int i = 0 ; i < n ; i++)
            graph[i].clear();
        cout << "Scenario #" << cs << ":\n\n";
        for(int i = 0 ; i < n ; i ++)
            cout << ans[i].fi << " " << ans[i].se << "\n\n";
    } 
    return 0;
}