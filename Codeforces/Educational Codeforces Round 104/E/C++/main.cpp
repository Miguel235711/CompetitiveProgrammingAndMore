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
#define inf 4e8+1

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

int ns[4],m,x,y;
int memo[4][150002];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 0 ; i < 4 ; i ++)
        cin >> ns[i];
    for(int i = 0 ; i < 4 ; i ++)
        for(int j = 1 ; j <= ns[i];j++)
            cin >> memo[i][j];
    for(int i = 1 ; i < 4 ; i ++){
        cin >> m ; 
        vector<pii> memAndXGlobal;
        vector<vector<pii> >memAndXLocal(ns[i]+1);
        ///get for each x its memo[i-1] value and store it as (memo[i-1][x],x)
        int iMinus1 = i-1;
        for(int j = 1 ; j <= ns[iMinus1]; j++)
            memAndXGlobal.pb(mp(memo[iMinus1][j],j));
        sort(memAndXGlobal.begin(),memAndXGlobal.end());
        for(int j = 0 ; j < m ; j ++){
            cin >> x >> y;
            memAndXLocal[y].pb(mp(memo[iMinus1][x],x));
        }
        for(int j = 1 ; j <= ns[i]; j ++)
            sort(memAndXLocal[j].begin(),memAndXLocal[j].end());
        for(int j = 1 ; j <= ns[i] ; j++){
            if(memAndXLocal[j].size()==memAndXGlobal.size()){
                memo[i][j]=inf;
                continue;
            }
            int ind = memAndXLocal[j].size();
            for(size_t k = 0 ; k < memAndXLocal[j].size() ; k ++){
                if(memAndXLocal[j][k] != memAndXGlobal[k]){
                    ind = k;
                    break;
                }
            }
            memo[i][j]+=memAndXGlobal[ind].first;
        }
    }
    int minAns = inf;
    for(int i = 1 ; i <= ns[3]; i ++)
        minAns = min(memo[3][i],minAns);
    cout << (minAns < inf? minAns : -1) << "\n";
    return 0;
}