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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,p,n,k;
    cin >> t;
    while(t--){
        cin >> n >> p >> k ; 
        vi m(n+k+1);
        string a;
        p--;
        cin >> a;
        int x,y;
        cin >> x >> y;
        for(int i = n - 1 ; i > -1 ; i --){
            m[i] = (a[i]=='0') + m[i+k];
            //cout << "i: " << i << "m[i]: " << m[i] << " m[i+k]: " << m[i+k] << "\n";
        }
        int ans = INT_MAX;
        for(int i = p ; i < n ; i ++){
            MIN(ans,m[i]*x+y*(i-p));
        }
        cout << ans << "\n";
    }
    return 0;
}