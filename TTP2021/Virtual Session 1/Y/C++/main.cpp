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

int t,n,m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        cin >> n >> m ; 
        vii blocks(m+2);
        map<int,int> to;
        for(int i = 0 ; i < m ; i ++)
            cin >> blocks[i].fi >> blocks[i].se,to[blocks[i].se];
        blocks[m] = {1,n+1}; 
        blocks[m+1] = {2,n+1};
        m+=2;
        to[n+1]; ///for limit
        int i = 0 ; 
        for(auto it = to.begin(); it!=to.end(); it++,i++){
            if((it->fi&1)!=(i&1))
                i++;
            it->se = i;
        }
        //cout << "i: " << i << "\n";
        vvi grid(2,vi(i));
        //cout << grid[0].size() << "\n";
        for(int i = 0 ; i < m ; i ++){
            //cout << "blocks[i].fi-1: " << blocks[i].fi-1 << " to[blocks[i].se]: " << to[blocks[i].se] << "\n";
            grid[blocks[i].fi-1][to[blocks[i].se]]=1;
        }
        //verify
        i--;
        bool pos = true;
        for(int j = 0 ; j < i ; j ++)
            if(grid[0][j]!=grid[1][j]){
                int which = !grid[1][j];
                if(grid[which][j+1]){
                    pos = false;
                    break;
                }else
                    grid[which][j+1] = 1;
            }
        cout << (pos?"YES":"NO") << "\n";
    }
    return 0;
}