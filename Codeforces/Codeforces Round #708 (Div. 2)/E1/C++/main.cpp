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
#define MOD2 1000000123 //1E9+123
#define p 1000000007

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

const int lim = 1e7;

vi sieve(lim+1);

void calcSieve(){
    for(int i = 2 ; i <= lim ; i +=2)
        sieve[i] = 2;
    for(i64 i = 3 ; i <= lim ; i +=2){
        if(!sieve[i]){
            sieve[i]=i;
            for(i64 j = i*i;j <= lim; j+=i)
                sieve[j]=i;
        }
    }
}

int mod(i64 x,int m){
    //cout << "x: " << x << "m: " << m  << " x%MOD " << x%MOD << "\n";
    return x%m;
}

int getHash(const map<int,int> & x,int m){
    i64 hash = 0 ;
    for(auto it = x.begin(); it!=x.end();it++){
        if(it->se)
            hash =  mod(hash * p + it->fi+1,m);
    }
    return hash;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k,t,xi;
    calcSieve();
    cin >> t ;
    while(t--){
        cin >> n >> k ; 
        int ans = 1 ; 
        set<pair<int,int> > v;
        for(int i = 0 ; i < n ; i ++){
            cin >> xi;
            ///get factorization
            map<int,int> f ; 
            for(int x = xi ; sieve[x]; x /= sieve[x])
                f[sieve[x]] = !f[sieve[x]];
            pair<int,int> h = {getHash(f,MOD),getHash(f,MOD2)};
            //cout << "hash for xi: " << xi << " -> " << h.fi << " " << h.se << "\n";
            if(v.find(h)!=v.end())
                ans++,v.clear();
            v.insert(h);
        }
        cout << ans << "\n";
    }
    return 0;
}