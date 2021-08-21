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

typedef pair<int,string> pis;

typedef priority_queue<int> pqi;
typedef priority_queue<pi> pqii;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string line;
    while(getline(cin,line)){
        int H = stoi(line.substr(0,2)), M = stoi(line.substr(2,2)), S = stoi(line.substr(4,2)) , C = stoi(line.substr(6,2));
        int t =(36e4*H + 6000*M + 100*S + C)*125/108;
        int h = t / 1e6;
        t-=1e6*h;
        int m = t / 1e4;
        t -= 1e4*m;
        int s = t / 100;
        printf("%d%02d%02d%02d\n",h,m,s,t%100);
    }
    return 0;
}