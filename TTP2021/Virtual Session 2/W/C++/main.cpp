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

///operators overloading
void operator+=(pii& a,const pii&b){
    a.fi+=b.fi;
    a.se+=b.se;
}
pii operator+(const pii& a,const pii&b){
    return {a.fi+b.fi,a.se+b.se};
}

void operator-=(pii& a,const pii&b){
    a.fi-=b.fi;
    a.se-=b.se;
}
pii operator-(const pii& a,const pii&b){
    return {a.fi-b.fi,a.se-b.se};
}

const int lim = 2508, inf = 1e9+1;

int n,xi,si;

int cost[lim][lim],p[lim];

int prim(){
    int ans = 0 ;
    p[0]=0;
    for(int i = 1 ; i <= n ; i ++)
        p[i] = cost[0][i];
    for(int i = 0 ; i < n ; i ++){
        int mnC = inf,bJ=1;
        for(int j = 1 ; j <= n ; j ++){
            if(p[j]){
                if(mnC>p[j])
                    mnC = p[j],bJ = j;
            }
        }
        p[bJ]=0;
        for(int j = 1 ; j <= n ; j ++)
            MIN(p[j],cost[bJ][j]); 
        ans+=mnC;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> xi >> si;
        for(int j = 0 ; j <= n ; j ++)
            cin >> cost[j][i];
        cost[xi][i] = si;
    }
    cout << prim() << "\n";
    return 0;
}