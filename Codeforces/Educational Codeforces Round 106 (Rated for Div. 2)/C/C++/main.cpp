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

int n,t;

int left(int i){
    return n-i/2;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n ; 
        v64 c(n+1);
        for(int i = 0 ; i < n ; i ++)
            cin >> c[i];
        i64 s0=0,s1=0,minC0=LLONG_MAX,minC1=LLONG_MAX;
        i64 lastS1 = LLONG_MAX,ans = LLONG_MAX;
        for(int i = 0 ; i < n ; i +=2){
            MIN(minC1,c[i+1]);
            s1+=c[i+1];
            i64 l = left(i)-1, takeNextS1 = s1+l*minC1;
            MIN(minC0,c[i]);
            s0+=c[i];
            MIN(ans,s0+l*minC0+min(lastS1,i+1<n?takeNextS1:(i64)LLONG_MAX));
            lastS1=takeNextS1;
        }
        cout << ans << "\n";
    }
    return 0;
}