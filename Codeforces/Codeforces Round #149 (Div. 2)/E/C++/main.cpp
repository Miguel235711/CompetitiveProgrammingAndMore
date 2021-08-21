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

vi a;
int n;
struct sg{
    int l,r,x,sz;
    vi p; //initialize in 20
}seg[400008];
i64 p[20];

inline void updateWithChilds(int d){
    for(int i = 0 ; i < 20 ; i ++)
        seg[d].p[i] = seg[d<<1].p[i] + seg[(d<<1)+1].p[i];
}

void build(int d,int l,int r){
    seg[d].l=l,seg[d].r=r,seg[d].sz = r-l+1;
    seg[d].p.resize(20);
    if(l==r){
        ///initialize
        for(int i = 0  , x = a[l]; x ;i ++,x>>=1)
            seg[d].p[i] += x&1;
        return;
    }
    int m = (l+r)>>1;
    build(d<<1,l,m),build((d<<1)+1,m+1,r);
    updateWithChilds(d);
}

inline void propagate(int d){
    if(seg[d].x){
        int sz = seg[d].sz;
        for(int i=0,x = seg[d].x; x ; x>>=1,i++){
            if(x&1)
                seg[d].p[i] = sz - seg[d].p[i];  
        }
        int d2 = d<<1;
        if(seg[d].l!=seg[d].r)
            seg[d2].x ^= seg[d].x, seg[d2+1].x ^= seg[d].x;
        seg[d].x = 0;
    }
}

i64 query(int d,int l,int r){
    if(seg[d].r < l || seg[d].l > r)
        return 0;
    propagate(d);
    if(l<=seg[d].l&&seg[d].r<=r){
        i64 s = 0 ;
        for(int i = 0; i < 20 ; i++)
            s += p[i] * seg[d].p[i];
        return s;
    }
    return query(d<<1,l,r) + query((d<<1)+1,l,r);
}

void update(int d,int l,int r,int x){
    propagate(d);
    if(seg[d].r < l || seg[d].l > r)
        return;
    if(l<=seg[d].l&&seg[d].r<=r){
        seg[d].x ^= x;
        propagate(d);
        return;
    }
    update(d<<1,l,r,x),update((d<<1)+1,l,r,x);
    updateWithChilds(d);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    p[0]=1;
    for(int i = 1 ; i < 20 ; i ++)
        p[i] = p[i-1]<<1;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n ; i ++)
        cin >> a[i];
    build(1,0,n-1);
    //cout << query(1,0,1) << "\n";
    ///queries
    int m,t,l,r,x;
    cin >> m;
    while(m--){
        cin >> t >> l >> r;
        l--,r--;
        if(t==1)
            cout << query(1,l,r) << "\n";
        else{
            cin >> x;
            update(1,l,r,x);
        }
    }
    return 0;
}