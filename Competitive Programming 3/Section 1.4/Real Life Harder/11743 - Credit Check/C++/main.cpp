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

int digitSum(int x){
    int sum=0;
    for(;x;x/=10)
        sum += x%10;
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    char xi;
    cin >> n ;
    while(n--){
        int sum=0;
        for(int i = 0 ; i < 16 ; i ++){
            cin >> xi;
            if(i&1)
                sum+=xi-'0'; 
            else
                sum+=digitSum((xi-'0')<<1);
            
        }
        cout << (sum%10==0 ? "Valid":"Invalid")<<"\n";
    }
    return 0;
}