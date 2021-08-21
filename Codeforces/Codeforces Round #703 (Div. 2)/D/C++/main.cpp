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

int n,k;
vi a;

int toOneValue(int i,int x){
    return a[i]<x?-1:1;
}

bool possible(int x){
    vi sums(n);
    sums[0]=toOneValue(0,x);
    for(int i = 1 ; i < n ; i ++)
        sums[i]=sums[i-1]+toOneValue(i,x);
    int minS = 0;
    for(int i = k-1 ; i < n ; i ++){
        if(sums[i]-minS>0)
            return true;
        minS = min(minS,sums[i-k+1]);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k ; 
    set<int> nums;
    a.resize(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i],nums.insert(a[i]);
    vi ns(nums.begin(),nums.end());
    //binary search
    int l = 0 , r = ns.size()-1;
    while(l+1<r){
        int m = (l+r)>>1;
        if(possible(ns[m]))
            l = m ;
        else
            r = m - 1 ; 
    }
    cout << ns[possible(ns[r])?r:l] << "\n";
    return 0;
}