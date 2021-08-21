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
#define inf 1e9+1

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

///seg begin

struct seg{
    int l, r,v;
}sg[400008]; ///of mins

void build(int d,int l,int r){
    sg[d].l = l, sg[d].r = r,sg[d].v = inf;
    if(l==r)
        return;
    int m = (l+r)>>1;
    build(d<<1,l,m),build((d<<1)+1,m+1,r);
}

void update(int d,int p,int v){
    if(sg[d].l==sg[d].r){
        sg[d].v = v;
        return;
    }
    int d2 = d<<1;
    sg[d2].r < p ? update(d2+1,p,v) : update(d2,p,v);
    sg[d].v = min(sg[d2].v,sg[d2+1].v);
}

/*int query(int d,int l,int r){
    return sg[d].l>r||sg[d].r<l ? inf:
        l<=sg[d].l&&sg[d].r<=r ? sg[d].v : min(query(d<<1,l,r),query((d<<1)+1,l,r));
}*/

///seg end

int N,M;

struct es{
    int S,C,L,D;
    bool operator<(es o)const{
        return L < o.L;
    }
    es(){}
    es(int S,int C,int L,int D):S(S),C(C),L(L),D(D){}
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> N >> M){
        vi E(N);
        vector<es> A(M);
        vii D; //until which position,pack
        for(int i = 1 ; i <= N ; i ++)
            cin >> E[i],E[i]+=E[i-1];
        for(int i = 0 ; i < M ; i ++) ///find breaking point
            cin >> A[i].L >> A[i].S >> A[i].C;
        sort(A.begin(),A.end());
        A.pb(es(0,0,N,0)),M++;
        for(int i = 0 ; i < M ; i ++){
            int p = A[i].L, s = A[i].S;
            int l = i, r = M;
            while(l+1<r){
                int m = (l+r)>>1;
                if(E[A[m].L]-E[p-1]>s)
                    r = m;
                else 
                    l = m;
            }
            ///l has the D answer
            A[i].D =  E[A[l].L]-E[p-1]>s ? -1 : l+(A[l+1].L!=A[l].L&&l+2<M&&E[A[l+1].L-1]-E[p-1]<=s);
            D.pb({A[i].D,i}); ///until which m it resists or that does not resist and the pack
        }
        sort(D.begin()+1,D.end());
        /*cout << "D\n";
        for(int i = 0 ; i < M ; i ++){
            cout << D[i].fi << " " << D[i].se << "\n";
        }*/
        int j = 0;
        build(1,0,M-1);
        for(int i = 0 ; i < M ; i ++){
            ///kill previous
            for(;j<M && D[j].fi<i;j++)
                update(1,D[j].se,inf);
            if(A[i].D!=-1){
                ///update with the min
                //cout << "cost[i]: " << (A[i].L == 1 ?0:sg[1].v)+A[i].C << "\n";
                update(1,i,(A[i].L == 1 ?0:sg[1].v)+A[i].C);
            }
        }
        cout << (sg[1].v < inf ? sg[1].v : -1) << "\n";
    }
    return 0;
}