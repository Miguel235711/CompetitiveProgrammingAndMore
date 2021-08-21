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

const int lim = 500008;

int n,k;
pair<int,int> mnL[26],mnR[26],ch[lim],m[lim][26];
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k >> s;
    for(int i = 0 ; i < n ; i ++)
        s[i]-='A';
    int kMinus1 = k-1;
    auto mx = mp(INT_MAX,0);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < k ; j ++){
            m[i][j] = min(j?mnL[j-1]:mx,j<kMinus1?mnR[j+1]:mx);
            m[i][j].fi+=(s[i]!=j);
        }
        mnL[0]={m[i][0].fi,0};
        for(int j = 1 ; j < k ; j ++)
            mnL[j] = min(mnL[j-1],{m[i][j].fi,j});
        mnR[kMinus1]={m[i][kMinus1].fi,kMinus1};
        for(int j = kMinus1-1 ; j > -1 ; j --)
            mnR[j] = min(mnR[j+1],{m[i][j].fi,j});
    }
    auto ans = mp(INT_MAX,0);
    for(int j = 0 ; j < k ; j ++)
        MIN(ans,mp(m[n-1][j].fi,j));
    cout << ans.fi << "\n";
    vi a(n); 
    for(int i = n - 1; i > -1 ; i --){
        a[i]=ans.se;
        ans.se = m[i][ans.se].se;
    }
    for(int i = 0 ; i < n ; i ++)
        cout << (char)(a[i]+'A');
    cout << "\n";
    return 0;
}