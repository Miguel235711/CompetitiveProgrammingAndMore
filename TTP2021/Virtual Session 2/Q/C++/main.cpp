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

vi a,lN,rN;
int m[5008][5008];
int n;

int f(int i,int j){
    bool bJ = j==n;
    bool bI = i==1;
    if(bI&&bJ)
        return 0;
    if(m[i][j]!=-1)
        return m[i][j];
    return m[i][j] = (a[i-1]==a[j+1] ? f(lN[i-1],rN[j+1]) : min(bI?INT_MAX:f(lN[i-1],j),bJ?INT_MAX:f(i,rN[j+1])))+1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    a.resize(n+2),lN.resize(n+1),rN.resize(n+1);
    memset(m,-1,sizeof(m));
    int ls = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(a[i]!=a[i-1])
            ls = i;
        lN[i]=ls;
    }
    ls = 0 ;
    for(int i = n ; i; i --){
        if(a[i]!=a[i+1])
            ls = i;
        rN[i]=ls; 
    }
    int ans = INT_MAX;
    for(int i = 1 ; i <= n ; i ++)
        MIN(ans,f(lN[i],rN[i]));
    cout << ans << "\n";
    return 0;
}