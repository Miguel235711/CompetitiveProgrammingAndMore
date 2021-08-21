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

int n,v[200008],ans=0;
vi a,c;

int f(int x){
    if(v[x])
        return v[x];
    v[x]=INT_MAX;
    int ch = a[x];
    if(v[ch]==INT_MAX){
        //cout << "entered\n";
        int b = c[x];
        for(int i = a[x] ; i != x ; i = a[i])
            MIN(b,c[i]);
        for(int i = a[x]; i != x ; i = a[i])
            MIN(v[i],b);
        MIN(v[x],b);
        ans += b;
    }else
        MIN(v[x],f(ch));
    return v[x];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    a.resize(n),c.resize(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> c[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i],a[i]--;
    for(int i = 0 ; i < n ; i ++)
        f(i);
    cout << ans << "\n";
    return 0;
}