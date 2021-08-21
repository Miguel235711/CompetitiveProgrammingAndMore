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

struct edge{
    int u,v,w,sz;
    bool c;
};
vector<edge> edges;
vector<vii> graph; // node, edge index
int t,n,lim,c;
i64 s;

int calcSize(int u,int p,i64 & sP,i64 & sP2){
    int subS = 0;
    for(auto c : graph[u])
        if(c.fi!=p){
            subS+=edges[c.se].sz=calcSize(c.fi,u,sP,sP2);
            auto inter = (i64)edges[c.se].sz*edges[c.se].w;
            sP+=inter;
            if(edges[c.se].c)
                sP2+=inter;
        }
    return max(subS,1);
}

i64 calcD(int i){
    return (i64)(edges[i].w - edges[i].w/2)*edges[i].sz;
} 
pair<i64,int> toPush(int i){
    return mp(calcD(i),i);
}
void mov(int i){
    edges[i].w>>=1;
}

priority_queue<p64> initPQ(bool c){
    priority_queue<p64> p;
    for(int i = 0 ; i < lim ; i ++)
        if(edges[i].c==c)
            p.push(mp(calcD(i),i));
    return p;
}

p64 getNext(priority_queue<p64> & p){
    auto x =  p.top();
    p.pop();
    return x;    
}

void solve(i64 sP,i64 sP2){
    v64 twoS={sP2};
    auto pQ2 = initPQ(1);
    if(!pQ2.empty()){
        for(auto cur = getNext(pQ2);twoS.back();cur = getNext(pQ2)){
            twoS.push_back(twoS.back()-cur.first);
            mov(cur.se);
            cur.fi = calcD(cur.se);
            pQ2.push(cur);
        }
    }
    int j = twoS.size()-1,i=0,ans=INT_MAX;
    auto pQ1 = initPQ(0);
    for(auto sP1 = sP - sP2 ; ;i++){
        //cout << "before: "<< " twoS[j]+sP1: " << twoS[j]+sP1 << " sP1: " << sP1 << " twoS[j]: " << twoS[j] << "\n";
        //find corresponding j index
        for(;j&&twoS[j-1]+sP1<=s;j--);
        //cout << "i: " << i << " j: " << j  << " twoS[j]+sP1: " << twoS[j]+sP1 << "\n";
        if(twoS[j]+sP1<=s)
            MIN(ans,i+j*2);
        if(!sP1)
            break;
        auto cur = getNext(pQ1);
        sP1-= cur.fi;
        mov(cur.se);
        cur.fi = calcD(cur.se);
        pQ1.push(cur);
        
    }
    //cout << "ans: " << ans << "\n";
    cout << ans << "\n";
    /*for(auto tX: twoS)
        cout << "tX: " << tX << "\n";*/
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        cin >> n >> s ;
        lim = n - 1 ; 
        edges.resize(lim);
        graph.clear();
        graph.resize(n+1); //index nodes in 1
        for(int i = 0 ; i < lim ; i ++)
            cin >> edges[i].v>>edges[i].u>>edges[i].w>>c,edges[i].c = c == 2,
            graph[edges[i].v].push_back(mp(edges[i].u,i)),
            graph[edges[i].u].push_back(mp(edges[i].v,i));
        i64 sP=0,sP2=0;
        calcSize(1,1,sP,sP2);
        //cout << "sP: " << sP << " sP2: " << sP2 << "\n";
        //cout << "sP initial: " << sP << "\n";
        solve(sP,sP2);
    }
    return 0;
}