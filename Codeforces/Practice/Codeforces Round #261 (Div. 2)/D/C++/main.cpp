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

#define MAXN 1000008

struct seg{
    int l,r,v;
}sg[MAXN*4]; //indexed from 1

void build(int v,int l,int r){
    sg[v].l=l;
    sg[v].r=r;
    if(l!=r){
        //it is not leaf
        int v2 = v<<1,m=(l+r)>>1;
        build(v2,l,m),build(v2+1,m+1,r);
    }
}
int sum(int v,int l,int r){
    if(l>sg[v].r || r < sg[v].l)
        return 0;
    if(l<=sg[v].l&&sg[v].r<=r)
        return sg[v].v;
    int v2=v<<1;
    return sum(v2,l,r)+sum(v2+1,l,r);
}
void update(int v,int i){
    sg[v].v++;
    if(sg[v].l==sg[v].r)
        return;
    int v2=v<<1;
    update(v2+(i>sg[v2].r?1:0),i);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vi a(n),l(n),r(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> a[i];
    map<int,int> bL,bR;
    for(int i = 0 ; i < n ; i ++){
        l[i]=++bL[a[i]];
    }
    build(1,1,n);
    int64_t ans = 0;
    for(int i = n - 2 ; i > -1 ; i --){
        update(1,++bR[a[i+1]]);
        ans += sum(1,1,l[i]-1);
    }
    cout << ans << "\n";
    return 0;
}