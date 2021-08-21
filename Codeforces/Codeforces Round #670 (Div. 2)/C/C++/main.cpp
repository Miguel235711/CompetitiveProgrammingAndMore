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

int t,n,nO2,a,b;

void f(int v,int p, vi & sz,const vvi & graph,vi & centroids){
    bool isCent = true;
    for(int u : graph[v])
        if(u!=p){
            f(u,v,sz,graph,centroids);
            sz[v]+=sz[u];
            if(sz[u]>nO2)
                isCent = false;
        }
    if(n-sz[v]<=nO2&&isCent)
        centroids.push_back(v);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        cin >> n ;
        nO2 = n>>1;
        vvi graph(n+1,vi()); 
        vi sz(n+1,1);
        vi centroids;
        for(int i = 1 ; i < n ; i ++)
            cin >> a >> b , graph[a].push_back(b), graph[b].push_back(a);
        f(a,a,sz,graph,centroids);
        int parent=centroids[0], opPar = centroids[centroids.size()==2]; 
        int child = graph[parent][graph[parent][0]==opPar];
        cout << parent << " " << child << "\n" << opPar << " " << child << "\n"; 
    }
    return 0;
}