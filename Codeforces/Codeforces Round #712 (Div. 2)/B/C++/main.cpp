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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;
    cin >> t;
    string a,b;
    while(t--){
        cin >> n;
        cin >> a >> b;
        vi s(n+1),d(n+2); /// indexed from 1
        d[0]=d[n+1]=-1;
        s[0]=a[0]-'0';
        for(int i = 0 ; i < n ; i ++)
            s[i+1]=s[i]+a[i]-'0', d[i+1]=a[i]!=b[i];
        bool jump0 = 1;
        int lInd = -1;
        bool ps = 1;
        for(int i = n ; i > -1 ; i --){
            if(!jump0||d[i]){
                if(d[i]&&jump0)
                    lInd = i;
                jump0=0;
                ///transverse until different
                if(d[i+1]!=d[i]){
                    ///different
                    int sz = lInd-i;
                    //cout << "i: " << i << " lInd: " << lInd << "\n";
                    //cout << "s[lInd]-s[i]: " << s[lInd]-s[i] << "\n";
                    if(sz&1 || s[lInd]-s[i]!=sz/2){
                        ps = 0;
                        break;
                    }
                    lInd = i;
                }
            }
        }
        cout << (ps?"YES":"NO") << "\n";
    }
    return 0;
}