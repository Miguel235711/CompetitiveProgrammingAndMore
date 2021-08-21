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
    int t,n;
    char c;
    cin >> t ; 
    while(t--){
        cin >> n ; 
        vector<vector<bool>> a(n,vector<bool>(n));
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < n ; j ++)
                cin >> c, a[i][j]=c-'0';
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < n ; j ++)
                cin >> c, a[i][j] = a[i][j] == (c-'0');
        bool pos = 1;
        for(int i = 1 ; i < n ; i ++){
            bool equal=1,opos=1;
            for(int j = 0 ; j < n ; j ++)
                equal &= a[0][j] == a[i][j], opos &= a[0][j] != a[i][j];
            if(!equal&&!opos){
                pos = 0;
                break;
            }
        }
        cout << (pos ? "YES" : "NO") << "\n";
    }
    return 0;
}