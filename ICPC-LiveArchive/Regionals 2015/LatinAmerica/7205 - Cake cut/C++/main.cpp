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

int n;

inline int nxt(int i){
    return (i+1)%n;
}

inline int prv(int i){
    return i?i-1:n-1;
}

inline i64 calcN(int i,int j,const v6464 & a){
    int nJ = nxt(j);
    return a[j].fi*(-a[i].se+a[nJ].se) +a[nJ].fi*(-a[j].se + a[i].se) + a[i].fi*(a[j].se-a[nJ].se);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin >> n){
        v6464 a(n);
        for(int i = 0 ; i < n; i ++)
            cin >> a[i].fi >> a[i].se;
        i64 A=0,AL=0;
        int j=2; 
        for(int i = 0 ; i < n ; i ++)
            A+=a[i].fi*a[nxt(i)].se-a[i].fi*a[prv(i)].se;
        ///init AL 
        for(int i = 0 ; i < 3 ; i ++)
            AL += a[i].fi*a[(i + 1)%3].se-a[i].fi*a[i?i-1:2].se;
        //cout << "A: " << A << " AL: " << AL << "\n";
        i64 minMaxAL = A;
        for(int i = 0 ; i < n ; i ++){
            //cout << "i: " << i << "\n";
            i64 maxAL = 0;
            for(;AL+AL<A;j=nxt(j)){
                MAX(maxAL,min(AL,A-AL));
                //cout << "AL: " << AL << "\n";
                //cout << "j: " << j  << "\n";
                AL += calcN(i,j,a);
            }
            //cout << "finalJ: " << j << "\n";
            //cout << "A-AL: " << A-AL << " AL: " << AL << "\n";
            //cout << "maxAL: "<< max(maxAL,A-AL) << "\n";
            MIN(minMaxAL,max(maxAL,A-AL));
            j=prv(j);
            AL -= calcN(i,j,a);//return to previous
            ///remove i
            int nI = nxt(i);
            AL +=  -a[i].fi*a[nI].se + a[nI].fi * a[i].se + a[i].fi * a[j].se + a[j].fi * (-a[i].se + a[nI].se) - a[nI].fi * a[j].se;
        }
        cout << A - minMaxAL << " " << minMaxAL << "\n";
    }
    return 0;
}