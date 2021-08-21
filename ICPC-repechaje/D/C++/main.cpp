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
#define maxL 1000002
#define lim 1000004

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

int sieve[lim],N,K;

void precalcSieve(){
    for(int i = 2 ; i <= maxL ; i +=2)
        sieve[i]=2;
    for(int i = 3 ; i <= maxL; i+=2){
        if(!sieve[i]){
            sieve[i]=i;
            for(int64_t j = (int64_t)i * i ; j <= maxL ; j+= i)
                sieve[j]=i;
        }
    }
}

void addToSet(int x,set<int> & s){
    for(;sieve[x];x/=sieve[x])
        //cout << "x: " << x << " sieve[x]: " << sieve[x] << "\n";
        if(sieve[x]!=2)
            s.insert(sieve[x]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    precalcSieve();
    cin >> N ; 
    while(N--){
        cin >> K;
        set<int> numbers;
        addToSet(K+2,numbers);
        if(numbers.empty())
            cout << -1 << "\n";
        else{
            size_t i = 1 ; 
            for(auto xi : numbers){
                cout << xi;
                if(i!=numbers.size())
                    cout << " ";
                i++;
            }
            cout << "\n";
        }
    }
    return 0;
}