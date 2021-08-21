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

const int lim = 2008;

int maxUp[lim][lim],maxDown[lim][lim],lDP[lim],rDP[lim],n,m;
char grid[lim][lim];

inline bool same(int i1,int j1,int i2,int j2){
    return grid[i1][j1]==grid[i2][j2];
}
inline void dpD(){
    for(int i = n ; i ; i --)
        for(int j = 1 ; j <= m ; j ++)
            maxDown[i][j]=1+(same(i+1,j,i,j)?maxDown[i+1][j]:0);
}
inline void dpU(){
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j++)
            maxUp[i][j]=1+(same(i-1,j,i,j)?maxUp[i-1][j]:0);
}

inline void dpL(int i){
    lDP[1]=1;
    for(int j = 2 ; j <= m ; j ++)
        lDP[j]=min((same(i,j-1,i,j) ? lDP[j-1]:0)+1, min(maxUp[i][j],maxDown[i][j]));
}
inline void dpR(int i){
    rDP[m]=1;
    for(int j = m-1 ; j ; j --)
        rDP[j]=min((same(i,j+1,i,j) ? rDP[j+1]:0)+1, min(maxUp[i][j],maxDown[i][j]));
}

inline i64 dpLR(){
    i64 ans = 0 ;
    for(int i = 1 ; i <= n ; i ++){
        dpL(i);
        dpR(i);
        for(int j = 1 ; j <= m ; j ++)
            ans += min(lDP[j],rDP[j]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ; 
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= m ; j++)
            cin >> grid[i][j];
    dpD();
    dpU();
    cout << dpLR() << "\n";
    return 0;
}