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
vi a,b;
int n,m;

int memo[208][1028];

int f(int i,int vis){
    if(i==n)
        return vis;
    if(memo[i][vis]!=-1)
        return memo[i][vis];
    int ans = f(i+1,vis|(a[i]&b[0]));
    for(size_t j = 1 ; j < b.size(); j++){
        MIN(ans,f(i+1,vis|(a[i]&b[j])));
    }
    return memo[i][vis]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ; 
    memset(memo,-1,sizeof(memo));
    a.resize(n),b.resize(m);
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < m ; i ++)
        cin >> b[i];
    cout << f(0,0) << "\n";
    return 0;
}