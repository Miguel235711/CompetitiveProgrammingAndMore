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

int parent[508],sz[508],label[508],labelCopy[508],cost[508][508],p,n;
vi c;
vector<bool> used;

int find(int a){
    while(a!=parent[a])
        a = parent[a] = parent[parent[a]];
    return a;
}
void joinU(int a,int b,int costV,int & labelOfParent){
    //a = find(a), b = find(b);
    //cout << "a: " << a << " b: " << b << "\n";
    if(sz[a]<sz[b])
        swap(a,b);
    ///sz[a]>=sz[b]
    sz[a]+=sz[b];
    parent[b] = a;
    if(!used[a]&&!used[b]){
        label[a] = ++p;
        c.pb(costV);
    }else
        MAX(label[a],label[b]);
    used[a]=used[b]=1;
    labelOfParent = label[a];
}

void initU(){
    for(int i = 1 ; i <= n ; i ++)
        parent[i]=i,sz[i]=1,label[i]=i;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    initU();
    p=n;
    map<int,vector<pii>> coords;
    c.resize(n+1);
    for(int i = 1 ; i <= n ; i ++ )
        for(int j = 1 ; j <= n ; j ++){
            cin >> cost[i][j];
            if(i!=j){
                auto it = coords.find(cost[i][j]);
                if(it==coords.end())
                    coords[cost[i][j]] = {{i,j}};
                else
                    it->second.pb({i,j});
            }else
                c[i]=cost[i][j];
        }
    set<pair<int,int> > edges;
    for(auto coord : coords){
        used.clear();
        used.resize(n+1);
        copy(label,label+n+1,labelCopy);
        for(auto c: coord.second){
            int i = c.fi , j = c.se;
            if(i!=j){
                int labelParent = 1;
                int iR = find(i), jR = find(j);
                if(iR!=jR){
                    int lI = labelCopy[iR] , lJ = labelCopy[jR];
                    joinU(iR,jR,cost[i][j],labelParent);
                    edges.insert({lI,labelParent}),edges.insert({lJ,labelParent});
                }

            }
        }
    }
    int sC = c.size();
    cout << sC - 1 << "\n";
    for(int i = 1 ; i < sC ; i ++)
        cout << c[i] << " ";
    cout << "\n";
    cout << p << "\n";
    for(auto edge: edges){
        cout << edge.fi << " " << edge.se << "\n";
    }
    return 0;
}