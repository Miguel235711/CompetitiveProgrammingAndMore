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

const int lim = 4008,limC = 91;

int n,k,p[lim],sz[lim],c[lim][lim]; // orig,dest 
vector<pii> edges[limC];

void initU(){
    for(int i = 0 ; i < n ; i ++)
        p[i]=i,sz[i]=1;
}

int findU(int x){
    while(p[x]!=x)
        x = p[x] = p[p[x]];
    return x;
}

void unionU(int aR,int bR){
    //cout << "aR: " << aR << " bR: " << bR << "\n";
    if(sz[aR]<sz[bR])
        swap(aR,bR);
    //sz[aR]>=sz[bR]
    sz[aR]+=sz[bR];
    p[bR]=aR;
    for(int i = 0 ; i < n ; i ++){
        auto iR = findU(i);
        if(aR!=iR){
            ///from iR to aR
            cout << "aR: " << aR << " bR: " <<  bR << "iR: " << iR << "\n";
            c[iR][aR] +=c[iR][bR];
            ///from aR to iR
            c[aR][iR] += c[bR][iR];
            if(c[aR][iR]<limC)
                edges[c[aR][iR]].pb({aR,iR});
        }
    }
    //nodes[aR].insert(nodes[aR].end(),nodes[bR].begin(),nodes[bR].end());
}

int solve(){
    if(n==k)
        return 0;
    int ans = 0 , kP = n ; 
    for(int iC = 0 ; iC < limC; iC++){
        for(size_t l = 0 ; l < edges[iC].size(); l++){
            //cout << "iC:  " << iC << "\n";
            int aR=findU(edges[iC][l].fi),bR=findU(edges[iC][l].se); 
            if(c[aR][bR] == iC && aR!=bR){
                cout << "aR: " << aR << " bR: " << bR << " cost: " << c[aR][bR] << " sz[aR]: " << sz[aR] << " sz[bR]: " << sz[bR] << "\n";
                unionU(aR,bR);
                ans += iC;
                kP--;
                cout << "ans: " << ans << "\n";
                if(kP==k)
                    return ans;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    initU();
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < n ; j ++){
            cin >> c[i][j];
            if(i<j)
                edges[c[i][j]].pb({i,j});
        }
    cout << solve() << "\n";
    return 0;
}