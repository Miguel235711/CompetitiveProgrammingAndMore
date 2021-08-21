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

int sqrt2(int x){
    return max((int)sqrt(x),2);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n ; 
        int x=n,i = n - 1 ; 
        vii ans;
        int inf = sqrt2(x);
        while(x>2){
            for(;i>inf&&i>2;i--)
                ans.push_back({i,n});
            ans.push_back({n,inf});
            x = ceil((double)x / inf);
            inf = sqrt2(x);
        }
        if(x!=1)
            ans.push_back({n,2});
        cout << ans.size() << "\n";
        for(auto p : ans)
            cout << p.fi << " " << p.se << "\n";
    }
    return 0;
}