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

pair<i64,bool> getMult(const vector<int> & a,int inc,int count){
    i64 ans = 1;
    for(int i = inc==1 ? 0 : a.size()-1;count;count--,i+=inc){
        if(i==-1||i==a.size())
            return mp(0,false);
        ans*=a[i];
    }
    return mp(ans,true);
}

int getIncNegative(int count){
    return count&1?1:-1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t ; 
    while(t--){
        vector<int> positives, negatives;
        cin >> n ; 
        for(int i = 0 ; i < n ; i ++){
            cin >> xi;
            if(xi>=0)
                positives.push_back(xi);
            else
                negatives.push_back(-xi);
        }
        i64 ans = LLONG_MIN;
        sort(positives.begin(),positives.end());
        sort(negatives.begin(),negatives.end());
        for(int ng = 0 ; ng < 6 ; ng ++){
            int countPs = 5 - ng, incNeg = getIncNegative(ng) ;
            auto posM = getMult(positives,incNeg,countPs), negM = getMult(negatives,incNeg,ng);
            if(posM.se&&negM.se)
                MAX(ans,posM.fi*negM.fi*-incNeg);
        }
        cout << ans << "\n";
    }
    return 0;
}