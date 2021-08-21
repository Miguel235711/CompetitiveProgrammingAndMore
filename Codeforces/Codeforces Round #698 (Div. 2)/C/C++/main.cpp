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

bool all2(map<i64,int> & x){
    for(auto & e : x)
        if(e.se!=2 || e.fi&1)
            return false;
    return true; 
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;
    i64 di;
    cin >> t;
    while(t--){
        cin >> n ; 
        int n2 = n<<1;
        map<i64,int> x;
        for(int i = 0 ; i < n2 ; i ++){
            cin >> di;
            x[di]++;
        }
        bool possible = all2(x);
        if(possible){
            i64 acum = 0,nextAi=-1;
            size_t p=x.size();
            for(auto it = x.end();it!=x.begin();p--){
                it--;
                auto y = (it->fi>>1) - acum;
                if(y<=0||y%p!=0||y/p==nextAi){
                    possible=false;
                    break;
                }
                nextAi = y/p, acum  += nextAi;
            }
        }
        cout << (possible ? "YES":"NO") << "\n";
    }
    return 0;
}