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
    int l,r,mn,mx,i; /// b -> {0,1} ///inversions
    bool p;
}seg[400008];
string P,T;
vi df;
int k,N;

void build(int d,int l,int r){
    seg[d].l=l,seg[d].r=r;
    if(l==r){
        seg[d].mn = seg[d].mx = df[l];
        return;
    }
    int m = (l+r)>>1,d2=d<<1;
    build(d2,l,m),build(d2+1,m+1,r);
    seg[d].mn = min(seg[d2].mn,seg[d2+1].mn);
    seg[d].mx = max(seg[d2].mx,seg[d2+1].mx);
}

//inverted

void prgI(int d){
    if(seg[d].l!=seg[d].r&&seg[d].i){
        int d2 = d<<1;
        seg[d2].i = (seg[d2].i+seg[d].i) & 1;
        seg[d2+1].i  = (seg[d2+1].i + seg[d].i) &1;
        seg[d].i = 0 ; 
    }
}

void invert(int d,int l,int r){
    if(seg[d].r<l||seg[d].l>r)
        return;
    if(l<=seg[d].l&&seg[d].r<=r){
        seg[d].i = (seg[d].i+1)&1;
        return;
    }
    invert(d<<1,l,r),invert((d<<1)+1,l,r);
}

int qI(int d,int p){
    prgI(d);
    return seg[d].l == seg[d].r ? seg[d].i :
        seg[d*2].r<p ? qI((d<<1)+1,p) : qI(d<<1,p);
}

///min max

void prg(int d){
    if(seg[d].p){
        int mn =  seg[d].mn;
        seg[d].mn = k - seg[d].mx,seg[d].mx = k - mn;
        if(seg[d].l!=seg[d].r){
            int d2 = d<<1;
            seg[d2].p = (seg[d2].p + seg[d].p)&1;
            seg[d2+1].p = (seg[d2+1].p+seg[d].p)&1;
        }
        seg[d].p=0;
    }
}

void updateMNX(int d,int l,int r){
    if(seg[d].r<l||seg[d].l>r)
        return;
    if(l<=seg[d].l&&seg[d].r<=r){
        seg[d].p = (seg[d].p+1)&1;
        return;
    }
    updateMNX(d<<1,l,r),updateMNX((d<<1)+1,l,r);
}

int qMX(int d,int l,int r){
    if(seg[d].r<l||seg[d].l>r)
        return -1;
    if(l<=seg[d].l&&seg[d].r<=r){
        prg(d);
        return seg[d].mx;
    }
    return max(qMX(d<<1,l,r),qMX((d<<1)+1,l,r));
}

///update single

void reconstruct(int d,int l,int r){
    prg(d);
    if(seg[d].l==seg[d].r){
        seg[d].mn = seg[d].mx = df[seg[d].l]; 
        return;
    }
    int d2=d<<1;
    reconstruct(d2,l,r),reconstruct(d2+1,l,r);
    seg[d].mn = min(seg[d2].mn,seg[d2+1].mn);
    seg[d].mx = max(seg[d2].mx,seg[d2+1].mx);
}

char invC(char c){
    return islower(c) ? toupper(c) : tolower(c);
}

void updateBrute(int l,int r){///[l,r]
    for(;l<=r;l++){ ///update 
        int d = qI(1,l); 
        if(d){
            ///switch
            ///update every df that includes it
            for(int i = max(l - k +1,0) ; i <= l ; i++){
                df[i]+= P[i] == T[l-i] ? -1:+1;
            }   
        }
    } 
    ///reconstruct  
    reconstruct(1,l-k+1,r);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> T >> P;
    k=T.size();
    df.resize(P.size());
    ///calc sDf
    for(int i = 0 ; i < P.size() ; i ++)
        
    build(1,0,N-1);
    return 0;
}