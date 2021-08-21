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

char grid[1008][1008];

pii rightCell[4]={mp(1,0),mp(0,1),mp(-1,0),mp(0,-1)};

void turnleft(int & dir){
    dir = (dir+1)%4;
}

bool rightIsFree(pii coord, int dir){
    return grid[coord.first +rightCell[dir].first][coord.second+rightCell[dir].second]!='\0';
}
bool frontIsBlocked(pii coord,int dir){
    turnleft(dir);
    return grid[coord.first + rightCell[dir].first][coord.second + rightCell[dir].second]=='\0';
}
void advanceG(int dir,pii & coord){
    turnleft(dir);
    coord.first += rightCell[dir].first;
    coord.se += rightCell[dir].se;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int b,w;
    while(cin>>b>>w,b){
        RESET(grid,'\0');
        vi visitings(5);
        for(int i = 1 ; i <= b ; i++)
            for(int j = 1 ; j <= w ; j ++){
                cin >> grid[i][j];
                if(grid[i][j]=='0')
                    visitings[0]++;
                else 
                    grid[i][j]='\0';
            }
        int dir = 0;
        for(pii coord = mp(b,1);;){
            //move to next
            visitings[grid[coord.fi][coord.se]-'0']--;
            grid[coord.fi][coord.se]++;
            visitings[grid[coord.fi][coord.se]-'0']++;
            if(rightIsFree(coord,dir))
                dir = (dir+3)%4;    
            else
                while(frontIsBlocked(coord,dir))
                    turnleft(dir);
            advanceG(dir,coord);
            if(coord.fi==b&&coord.se==1)
                break;
        }
        for(auto visit : visitings)
            cout << setw(3) << visit;
        cout << "\n";
    }
    return 0;
}