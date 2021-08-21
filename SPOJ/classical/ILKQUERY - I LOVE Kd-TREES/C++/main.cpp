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

///operators overloading
void operator+=(pii& a,const pii&b){
    a.fi+=b.fi;
    a.se+=b.se;
}
pii operator+(const pii& a,const pii&b){
    return {a.fi+b.fi,a.se+b.se};
}

void operator-=(pii& a,const pii&b){
    a.fi-=b.fi;
    a.se-=b.se;
}
pii operator-(const pii& a,const pii&b){
    return {a.fi-b.fi,a.se-b.se};
}

struct sg{
    int l,r,v;
}seg[400008]; ///index from 1

int n,q,k,i,I;

void add(int d,int i){
    seg[d].v++;
    if(seg[d].l==seg[d].r)
        return;
    int d2 = d<<1;
    seg[d2].r<i ? add(d2+1,i) : add(d2,i);
}
void build(int d,int l,int r){
    seg[d].l=l,seg[d].r=r;
    if(l==r)
        return;
    int m = (l+r)/2;
    build(d*2,l,m),build(d*2+1,m+1,r);
}
int fV(int d,int k){
    if(seg[d].l==seg[d].r)
        return seg[d].l;
    int d2 = d<<1;
    return seg[d2].v<k ? fV(d2+1,k-seg[d2].v) : fV(d2,k);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    build(1,0,n-1);
    vi a(n);
    map<int,int> to;
    int c = 0; ///]
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i],to[a[i]];
    for(auto it = to.begin(); it!=to.end(); it++)
        it->second = ++c;
    vvi adj(c+1);
    for(int i = 0 ; i < n; i ++)
        a[i] = to[a[i]], adj[a[i]].pb(i);
    ///queries
    vii ordQ(q),qr(q);
    vi ans(q);
    for(int i = 0 ; i < q ; i ++)
        cin >> qr[i].fi >> ordQ[i].fi >> qr[i].se, ordQ[i].se=i;
    sort(ordQ.begin(),ordQ.end());
    int j = -1 ; //]
    for(int i = 0 ; i < q ; i ++){
        while(j<ordQ[i].fi)
            j++,add(1,a[j]);
        int qrI = ordQ[i].se;
        int v = fV(1,qr[qrI].fi);
        size_t indA = qr[qrI].se-1;
        ans[qrI] =  indA < adj[v].size() ? adj[v][indA]:-1;
    }
    for(int i = 0 ; i < q ; i ++)
        cout << ans[i] << "\n";
    return 0;
}