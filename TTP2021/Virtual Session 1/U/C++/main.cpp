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

int n,m,ai,bi,eq,dif;
char com,ci;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    map<pair<int,int>,char> edges;
    while(m--){
        cin >> com >> ai;
        if(com!='?')
            cin >> bi; 
        if(com=='+')
            cin >> ci;
        ///process
        if(com=='?')
            cout << (eq||(dif&&(ai&1)) ? "YES" : "NO") << "\n";
        else if(com=='+'){
            auto it = edges.find({bi,ai});
            if(it!=edges.end())
                ///increment one of the operators
                it->se == ci ? eq ++ : dif ++;
            edges[{ai,bi}]=ci;
        }else{
            auto it = edges.find({bi,ai});
            auto toR = edges.find({ai,bi}); ///always exists
            if(it!=edges.end())
                ///decrement one of the operators
                it->se == toR->se ? eq -- : dif --;
            edges.erase(toR);
        }   
    }
    return 0;
}