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

void operator-=(pii& a,const pii&b){
    a.fi-=b.fi;
    a.se-=b.se;
}
pii operator-(const pii& a,const pii&b){
    return {a.fi-b.fi,a.se-b.se};
}

int n,x,y;
string s;
map<char,pii> movs ={
    {'U',{0,1}},
    {'D',{0,-1}},
    {'L',{-1,0}},
    {'R',{1,0}}
};

i64 absDif(const pii & a,const pii & b){
    return  abs(a.fi-b.fi)+abs(a.se-b.se);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    vi v(n);
    cin >> s;
    pii r,o;
    for(int i = 0 ; i < n ; i ++)
        r += movs[s[i]];
    cin >> o.fi >> o.se;
    int j=0,ans=n+1;
    for(int i = 0 ; i < n ; i ++){
        for(;j<n&&absDif(o,r)+i-j>0;j++)
            r-= movs[s[j]];
        if(absDif(o,r)+i-j==0)
            MIN(ans,j-i);
        if(i<j)
            r+=movs[s[i]];
        else
            j++;
    }
    cout << (ans == n+1 ? -1 : ans) << "\n";
    return 0;
}