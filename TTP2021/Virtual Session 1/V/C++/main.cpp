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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,m;
    i64 xi;
    cin >> t ; 
    const i64 zero = 0;
    while(t--){
        cin >> n >> m ;
        v64 a(n+1),mx(n+1); 
        mx[0]=-1e9;
        for(int i = 1 ; i <= n ; i ++)
            cin >> a[i],a[i]+=a[i-1],mx[i] = max(a[i],mx[i-1]);
        while(m--){
            cin >> xi;
            i64 j = a[n]<1 ? 0 : ceil((double)max(zero,xi-mx[n])/a[n]);
            xi -= j * a[n];
            i64 ans = j*n;
            if(xi>0){
                auto it = lower_bound(mx.begin()+1,mx.end(),xi);
                if(it==mx.end())
                    ans=0;
                else 
                    ans += distance(mx.begin(),it);
            }
            cout << ans - 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}