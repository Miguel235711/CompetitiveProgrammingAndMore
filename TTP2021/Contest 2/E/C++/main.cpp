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

int t,m,n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> m >> n;
        vi a(n);
        vvi r(n,vi(m));
        for(int i = 0 ; i < n ; i ++)
            cin >> a[i];
        for(int i = 0 ; i < n ; i ++){
            int cs = 0,ans=INT_MAX;
            for(int j = i ;j > -1 && cs+a[j]+j-i<=m; j --){
                cs+=a[j];
                //cout << "what: " << pow(m-cs-j+i,2) << "\n";
                //cout << "m: " << m << " " << i << " " << j << " " << cs << "\n";
                MIN(ans,(int)pow(m-cs-j+i,2)+r[j]);
            }
            r[i]=ans;
            cout << "r[i]: " << r[i] << "\n";
        }
        cout << r[n-1] << "\n"; 
    }
    return 0;
}