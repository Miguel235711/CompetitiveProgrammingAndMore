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

int n,m;
int pos[200008];
string s,t;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m ;
    cin >> s >> t ;
    int j = n - 1 ; 
    for(int i = m - 1 ; i > - 1 ; i --){
        for(;s[j]!=t[i];j--);
        pos[i] = j,j--;
    }
    int ans = 0 ; 
    j = 0 ; 
    for(int i = 1 ; i < m ; i ++){
        for(;s[j]!=t[i-1];j++);
        ans = max(pos[i]-j,ans),j++;
    }
    cout << ans << "\n";
    return 0;
}