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

int t,n,xi;
const int lim = 200001;
vi sieve(lim);

void calcSieve(){
    for(int i = 2 ; i < lim ; i +=2)
        sieve[i] = 2;
    for(i64 i = 3 ; i < lim ; i +=2){
        if(!sieve[i]){
            ///prime
            sieve[i]=i;
            for(i64 j = i * i; j < lim ; j+=i)
                sieve[j]=i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    calcSieve();
    cin >> t ; 
    while(t--){
        vi b(lim),m(lim);
        cin >> n ; 
        int mx = 0 ;
        for(int i = 0 ; i < n ; i ++)
            cin >> xi,b[xi]++,MAX(mx,xi);
        //dp
        int ans = 0;
        for(int i = mx ; i ; i --){
            m[i]+=b[i];
            if(b[i])
                MAX(ans,m[i]);
            if(m[i]){
                set<int> fcs;
                for(int xi = i; sieve[xi] ; xi/=sieve[xi])
                    fcs.insert(sieve[xi]);
                //calculate for every factor
                for(auto f : fcs){
                    MAX(m[i/f],m[i]);
                }
                //cout << "\n";
            }
        }
        //cout << "." << m[4] << "\n";
        cout <<  n - ans << "\n";
    }
    return 0;
}