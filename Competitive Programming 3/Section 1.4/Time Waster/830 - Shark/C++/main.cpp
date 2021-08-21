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

typedef vector<vector<string> > vvs;

int maxI,maxJ,minI,minJ,L,C;
char c;
char grid[64][64]; ///indexed from 0
int movs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

bool insideLimits(int i,int j){
    return i>-1 && j >-1 && i < L && j < C ; 
}

int dfs(int i,int j){
    if(grid[i][j]!=c||!insideLimits(i,j)) // outside limits or not valid c
        return 0;
    //visit cell
    grid[i][j]='.';
    int visitedC = 1;
    //calculate paremeters
    MAX(maxI,i),MAX(maxJ,j),MIN(minI,i),MIN(minJ,j);
    for(int m = 0 ; m < 4 ; m ++)
        visitedC+=dfs(i+movs[m][0],j+movs[m][1]);
    return visitedC;
}

int getDimension(int b,int e){
    return e-b+1;
}

pii getDimensionsOrShark(int i,int j){
    ///first i stands for greater, second i stands for smaller, 0 , 0 stands for shark
    maxI=maxJ=-1;
    minI=L,minJ=C;
    c=grid[i][j];
    int dfsA = dfs(i,j);
    auto ans = mp(getDimension(minI,maxI),getDimension(minJ,maxJ));
    if(ans.fi<ans.se)
        swap(ans.fi,ans.se);
    if(dfsA!=ans.fi*ans.se)
        ans.fi=ans.se=0;
    return ans;
}


map<int,int> espG = {
    mp(2,3),
    mp(3,5),
    mp(4,6)
};

void countEspecies(){
    vi total(8);
    for(int i = 0 ; i < L ; i ++)
        for(int j = 0 ; j < C ; j ++)
            if(grid[i][j]!='.'){
                auto dimensions = getDimensionsOrShark(i,j);
                total[
                    dimensions.fi==0&&dimensions.se==0?7:
                    (
                            dimensions.se==1?(
                                dimensions.fi==1?0:
                                    (
                                        dimensions.fi==2?1:2
                                    )       
                            ):
                            dimensions.fi==dimensions.se?4:espG[dimensions.se]
                    )
                ]++;
            }
    for(int i = 0 ; i < 7 ; i ++)
        cout << total[i] << " ";
    cout << total[7] <<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t ;
    cin >> t;
    for(int cs = 0 ; cs < t ; cs++){
        if(cs)
            cout << "\n";
        cin >> L >> C;
        for(int i = 0 ; i < L ; i++) cin >>grid[i];
        countEspecies();
    }
    return 0;
}