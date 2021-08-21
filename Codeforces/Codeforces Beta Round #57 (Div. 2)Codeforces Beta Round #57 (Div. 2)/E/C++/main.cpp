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

const int MAXN = 4000008;

struct seg{
    int l,r,v;
}sg[MAXN*4]; //indexed from 1

int build(int v,int l,int r){
    sg[v].l=l;
    sg[v].r=r;
    if(l!=r){
        //it is not leaf
        int v2 = v<<1,m=(l+r)>>1;
        sg[v].v = build(v2,l,m) + build(v2+1,m+1,r);
    }
    return sg[v].v;
}
void restart(int v){
    sg[v].v = 0 ;
    if(sg[v].l == sg[v].r)
        return;
    restart(v<<1);
    restart((v<<1)+1);
}
int sum(int v,int l,int r){
    if(l>sg[v].r || r < sg[v].l)
        return 0;
    if(l<=sg[v].l&&sg[v].r<=r)
        return sg[v].v;
    int v2=v<<1;
    return sum(v2,l,r)+sum(v2+1,l,r);
}
void set_i_with_1(int v,int i){
    int v2=v<<1;
    sg[v].v++;
    if(sg[v].l != sg[v].r) 
        set_i_with_1(v2+(i>sg[v2].r?1:0),i);
}

//a= [5,3,1,6,2]
//sg=[1,1,1,1,1]
//r= [3,2,0,1,0]
//l= [0,1,2,0,3]

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; // 3 <= n <= 10^6
    cin >> n;
    vii a(n+1);
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(),a.end());
    vi r(n+1);
    build(1,1,n);
    for(int i = 1 ; i <= n ; i ++){
        int iP = a[i].se;
        r[iP]=sum(1,iP+1,n);
        set_i_with_1(1,iP);
    }
    // for(int i = 1 ; i <= n ; i ++)
    //     cout << r[i] << " ";
    //cout << "\n";
    restart(1);
    int64_t ans = 0 ;
    for(int i = n ; i ; i --){
        int iP = a[i].se;
        //a=[3,2,1]
        //r=[2,1,0]
        //l=[0,1,2]
        ans+=(int64_t)r[iP]*sum(1,1,iP-1);
        set_i_with_1(1,iP);
    }
    cout << ans << "\n";
    return 0;
}