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

///operators overloading
void operator+=(pii& a,const pii&b){
    a.fi+=b.fi;
    a.se+=b.se;
}
pii operator+(const pii& a,const pii&b){
    return {a.fi+b.fi,a.se+b.se};
}

map<char,pii> movs={
    {'L',{-1,0}},
    {'R',{1,0}},
    {'D',{0,-1}},
    {'U',{0,1}}
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    string s ; 
    cin >> t ;
    while(t--){
        cin >> s ;
        vii coords(s.size());
        pii c,ans; 
        for(size_t i = 0 ; i < s.size() ; i ++)
            c+=movs[s[i]],coords[i]=c;
        for(size_t i = 0 ; i < s.size() ; i ++){
            c={0,0};
            for(size_t j = 0 ; j < s.size() ; j ++){
                auto n = c+movs[s[j]];
                if(n!=coords[i])
                    c = n;
            }
            if(c==(pii){0,0}){
                ans=coords[i];
                break;
            }
        }
        cout << ans.fi << " " << ans.se << "\n";
    }
    return 0;
}