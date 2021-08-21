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

int t,n,U,R,D,L;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        cin >> n >> U >> R >> D >> L ; 
        int nMinus2 = n-2;
        bool ans = 0;
        for(int g11 = 0 ; g11 <= 1 ; g11++){
            for(int g1m = 0 ; g1m <= 1 ; g1m++){
                for(int gnm = 0 ; gnm <= 1 ; gnm++){
                    for(int gn1 = 0 ; gn1 <= 1 ; gn1++){
                        int a = U-g11-g1m, b = R-g1m-gnm, c = D-gnm-gn1, d = L-gn1-g11;
                        ans|=a<=nMinus2&&
                            b<=nMinus2&&
                            c<=nMinus2&&
                            d<=nMinus2&&
                            a>=0&&b>=0&&c>=0&&d>=0;
                    }
                }
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}