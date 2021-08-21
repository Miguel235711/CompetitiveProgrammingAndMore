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

int leftSubIndex[108][108],rightSubIndex[108][108]; ///sub index of i in j is [i][j]
char mapV[108][108];
int paired[20208];///limit is tricky!!!
vi sonsOfLeft[10108]; ///limit is tricky
bool vis[10108];///limit is tricky

int N ;

int leftLimit = 0 ;

int newN = 1 ;

void generateGraph(){
    ///left index
    for (int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if ( mapV[i][j]=='\0'){///current is X
                if(mapV[i][j-1]!='\0'){
                    ///if before was not X
                    newN++;
                }
            }else{
                ///current is '.'
                leftSubIndex[i][j]=newN;
            }
        }
        newN ++  ;
    }
    leftLimit = newN - 1 ; ///tricky!!!!
    ///right index
    for (int j=1;j<=N;j++){
        for(int i=1;i<=N;i++){
            if ( mapV[i][j]=='\0'){///current is X
                if(mapV[i-1][j]!='\0'){
                    ///if before was not X
                    newN++;
                }
            }else{
                ///current is '.'
                rightSubIndex[i][j]=newN;
            }
        }
        newN ++;
    }
    ///generate graph , hyper trick
    for ( int i = 1 ; i <= N ; i ++ ) {
        for (int j=1;j<=N;j++){
            sonsOfLeft[leftSubIndex[i][j]].pb(rightSubIndex[i][j]);
        }
    }
}

bool dfs(int leftNode){
    if ( vis[leftNode] ) return false ;
    vis[leftNode]=true;
    for(int son:sonsOfLeft[leftNode]){
        if(paired[son]==-1 || dfs(paired[son])){
            paired[son]=leftNode;
            return true ;
        }
    }
    return false ;
}

void kuhn(){
    int ans = 0 ;
    memset(paired,-1,sizeof(paired));
    for ( int i = 1 ; i <= leftLimit; i ++ ){
        memset(vis,0,sizeof(vis));
        if ( dfs(i)){
            ans ++ ;
        }
    }
    cout << ans << "\n" ;
}

void emptyGlobalVariables(){
    for ( int i = 1 ; i <= N ; i ++ ) {
        for (int j=1;j<=N;j++){
            sonsOfLeft[leftSubIndex[i][j]].clear();
        }
    }
    memset(leftSubIndex,0,sizeof(leftSubIndex));
    memset(rightSubIndex,0,sizeof(rightSubIndex));
    newN = 1 ;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> N){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                cin>>mapV[i][j];
                if (mapV[i][j]=='X'){
                    mapV[i][j]='\0';
                }
            }
        }
        generateGraph();
        kuhn();
        emptyGlobalVariables();
    }
    return 0;
}
