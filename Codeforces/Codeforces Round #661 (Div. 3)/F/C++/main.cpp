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

int t,n;
int memo[3001][3001];
int nextBegAfterEnd[3001];
vii segs(3001);

bool c(int a,int b){
    return segs[a].fi>segs[b].se;
}

int calcNextBegAfterEnd(int i){
    int l = 1 , r = n - i ;
    while(l + 1 < r){
        int mid = (l+r)/2;
        if(c(i+mid,i))
            r = mid ;
        else
            l = mid + 1 ; 
    } 
    int add = c(i+l,i) ? l : (c(i+r,i)?r:0); 
    return add?i+add:-1;  
}

void calcNextBegAfterEnds(){
    for(int i = 1 ; i <= n ; i ++)
        nextBegAfterEnd[i]=calcNextBegAfterEnd(i);
}

int f(int i,int li){
    if(i>n)
        return 0;
    if(!(segs[li].fi<=segs[i].fi&&segs[i].se<=segs[li].se))
        return f(i+1,li);
    if(memo[i][li]!=-1)
        return memo[i][li];
    int nextIEx = nextBegAfterEnd[i];
    //cout << "i: " << i << " " << nextIEx << " " << segs[i].fi << " " << segs[i].se << "\n";
    return memo[i][li] = max(f(i+1,li),f(i+1,i)+(nextIEx==-1?0:f(nextIEx,li))+1);
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    segs[0].se = 2e5+1;
    while(t--){
        cin >> n ; 
        memset(memo,-1,sizeof(memo));
        for(int i = 1 ; i <= n ; i ++ )
            cin >> segs[i].fi >> segs[i].se;
        sort(segs.begin(),segs.begin()+n+1,[](auto a,auto b){
            return a.fi<b.fi||(a.fi==b.fi&&a.se>b.se);
        });
        calcNextBegAfterEnds();
        cout << f(1,0) << "\n";
    }
    return 0;
}