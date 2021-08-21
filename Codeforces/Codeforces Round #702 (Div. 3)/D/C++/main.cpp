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

int a[108],d[108];

int findMax(int l, int r){
    int maxI = l,maxE = a[l];
    l++;
    for(;l<=r;l++)
        if(maxE<a[l])
            maxE = a[l], maxI = l;
    return maxI;
}

void f(int l,int r,int depth){
    if(l>r)
        return;
    int maxI = findMax(l,r);
    d[maxI]=depth;
    f(l,maxI-1,depth+1);
    f(maxI+1,r,depth+1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;
    cin >> t ;
    while(t--){
        cin >> n ; 
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        f(0,n-1,0);
        for(int i = 0 ; i < n ; i ++)
            cout << d[i] << " ";
        cout << "\n";
    }
    return 0;
}