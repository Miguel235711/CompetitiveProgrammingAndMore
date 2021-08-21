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

i64 worstAns;

i64 cost(p64 x,i64 ai){
    return x.se>worstAns ? LLONG_MAX : x.fi*ai+x.se;
}

double xInt(p64 a,p64 b){
    return ((double)(b.se - a.se))/((double)(a.fi-b.fi)); 
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n ;
    vi a(n),b(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> b[i];
    v64 m(n);
    for(int i = 1 ; i < n ; i ++){
        m[i] = LLONG_MAX;
        for(int j = i - 1 ; j > -1 ; j --)
            m[i] = min((i64)b[j]*a[i]+m[j],m[i]);
    }
    cout << m[n-1] << "\n";
    return 0;
}