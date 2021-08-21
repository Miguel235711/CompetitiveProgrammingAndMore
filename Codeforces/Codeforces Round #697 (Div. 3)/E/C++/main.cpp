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

#define MOD 1000000007 //1E9+9

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

int fact[1008];

int exp(int base,int power){
    if(!power) return 1 ;
    int x = exp(base,power/2);
    x=(i64)x*x%MOD;
    if(power&1) x=(i64)x*base%MOD;
    return x ;
}

int division(int a , int b ){
    ///return (a%m)/(b%m)
    return (i64)a*exp(b,MOD-2)%MOD;
}

int b(int n,int k){
    return division(fact[n],(i64)fact[k]*fact[n-k]%MOD);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,k; 
    //precalc factorial
    fact[0]=1;
    for(int i = 1 ; i <= 1000; i++)
        fact[i] = (i64)i * fact[i-1] % MOD;
    cin >> t ; 
    while(t--){
        cin >> n >> k; 
        vi a(n);
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        sort(a.begin(),a.end());
        ///count equal
        int eI = n-k;
        int e = a[eI],c=0,d=0 ; 
        for(int i = eI-1; i > -1 && a[i]==e ; i --,d++);
        for(int i = eI ; i < n && a[i]==e ; i ++,c++);
        cout << b(c+d,c) << "\n";
    }
    return 0;
}