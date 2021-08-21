#include<bits/stdc++.h>

#define mp make_pair 
#define pb push_back 
#define sz size
#define FOR(a, b, c) for ((a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for ((a) = (b); (a) <= (c); ++(a)) 
#define FORD(a, b, c) for ((a) = (b); (a) >= (c); --(a)) 
#define FORSQ(a, b, c) for ((a) = (b); (a) * (a) <= (c); ++(a)) 
#define REP(i, n) FOR(i, 0, n) 
#define REPN(i, n) FORN(i, 1, n) 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define SQR(x) ((x) * (x)) 
#define RESET(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end() 
#define SORT(v) sort(ALL(v)) 
#define PERMUTE next_permutation
#define fi first 
#define se second

#define MOD 1000000009 //1E9+9

using namespace std;

typedef int64_t LL;

typedef pair<LL,LL> pl;
typedef vector<LL> vl;
typedef vector<pl> vpl;
typedef vector <vl> vvl;

typedef double dl;
typedef long double ldl;
typedef pair<string, string> ps;

typedef pair<int,int> pi; 
typedef vector<int> vi;
typedef vector< pi > vii;
typedef vector< vi > vvi;

typedef priority_queue<int> pqi;
typedef priority_queue<pi> pqii;

bool change(int & y,int p){
    y-=p;
    if(y<0)
        return true;
    return false;
}

bool possible(const vvi & paraTkns,int x,int y,int p){
    if(p>x||p>y)
        return false;
    for(auto & tkns: paraTkns){
        int tmpX = x;
        //start new paragraph
        if(change(y,p))return false;
        size_t i=0;
        REP(i,tkns.sz()){
            int tknPlusOne = tkns[i] + (i?1:0);
            if(tmpX>=p*tknPlusOne)
                tmpX -= p*tknPlusOne;
            else{
                //start new paragraph
                if(change(y,p)) return false;
                tmpX = x - p*tkns[i];
                if(tmpX<0)
                    return false; 
            }
        }
    }
    return true;
}

int binS(const vvi & paraTkns,int x,int y){
    int l = 8, r = 28;
    while(l+1<r){
        int mid = (l+r)>>1;
        if(possible(paraTkns,x,y,mid))
            l = mid ;
        else
            r = mid - 1 ;
    }
    if(possible(paraTkns,x,y,r))
        return r;
    if(possible(paraTkns,x,y,l))
        return l;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    string line;
    cin >> n ; 
    while(n--){
        cin >> m ;
        cin.ignore(); 
        vvi paraTkns;
        while(m--){
            getline(cin,line);
            line.pb(' ');
            int x=0;
            vi tkn; 
            for(auto c : line){
                if(c==' '){
                    tkn.pb(x);
                    x=0;
                }else
                    x++;
            }
            paraTkns.pb(tkn);
        }
        int x,y;
        cin >> x >> y;
        int ans = binS(paraTkns,x,y);
        cout << ( ans ? to_string(ans) : "No solution" ) << "\n"; 
    }
    return 0;
}