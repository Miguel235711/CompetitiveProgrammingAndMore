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

int t,n,q;

const int lim = 300002;

i64 memo[lim][2];
int arr[lim];

i64 f(int pos,bool negative){
    if(pos==n)
        return 0;
    if(memo[pos][negative]!=LLONG_MIN)
        return memo[pos][negative];
    return memo[pos][negative]=max(f(pos+1,negative),f(pos+1,!negative)+arr[pos]*(negative?-1:1));
}

void initMemo(){
    for(int i = 0 ; i < n ; i ++)
        memo[i][0]=memo[i][1]=LLONG_MIN;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        initMemo();
        for(int i = 0; i < n ; i ++)
            cin >> arr[i];
        cout << f(0,false) << "\n";
    }
    return 0;
}