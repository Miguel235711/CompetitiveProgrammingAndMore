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

i64 over2Ceil(i64 x){
    return (x>>1) + (x&1);
}

i64 f(size_t i,const v64 & a){
    return max(a[i],(i64)0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q,l,r,x;
    cin >> n ; 
    v64 a(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    i64 k = 0;
    for(int i = n - 1 ; i ; i --)
        a[i]=a[i]-a[i-1], k += f(i,a); 
    cout << over2Ceil(a[0]+k) << "\n";
    cin >> q ;
    while(q--){
        cin >> l >> r >> x ; 
        if(l==1)
            a[0]+=x;
        l--;
        if(l)
            k-=f(l,a),a[l]+=x,k+=f(l,a);
        if(r&&r<n)
            k-=f(r,a),a[r]-=x,k+=f(r,a);
        cout << over2Ceil(a[0]+k) << "\n";
    }
    return 0;
}