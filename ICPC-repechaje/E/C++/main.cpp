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

const int maxL = 1000000;

vi tree[maxL+2],invertedTopo;
int parent[maxL+2],root=1;
int64_t val[maxL+2],subTreeVal[maxL+2],toPropagateUpdated[maxL+2],toPropagateSubtree[maxL+2];

void calcTopo(){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        auto e = q.front();
        q.pop();
        invertedTopo.push_back(e);
        for(int child: tree[e])
            q.push(child);
    }
}
int n,m,q,ti,li,v;

void propagate(){
    for(int i = n-1 ; i>-1 ; i --){
        int x = invertedTopo[i];
        ///single val calculation
        val[x]+=toPropagateUpdated[x];
        toPropagateUpdated[parent[x]]+=toPropagateUpdated[x];
        ///subtree val calculation
        subTreeVal[x]+=toPropagateSubtree[x]+val[x];
        toPropagateSubtree[parent[x]]+=subTreeVal[x];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1 ; i <= n ; i ++){
        cin >> parent[i];
        if(!parent[i])
            root = i;
        else
            tree[parent[i]].push_back(i);
    }
    calcTopo();
    while(m--){
        cin >> ti >> li >> v;
        if(ti==1){
            val[li]+=v;
        }else
            toPropagateUpdated[li]+=v;
    }
    propagate();
    while(q--){
       cin >> ti >> li;
       cout << (ti == 1 ?  val[li] : subTreeVal[li]) << "\n"; 
    }
    return 0;
}